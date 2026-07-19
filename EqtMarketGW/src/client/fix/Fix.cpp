#include "client/fix/Fix.h"

#include <iostream>
#include <stdexcept>

namespace marx::client::fix {

static SessionContext loadFixCtx(const ConfigLoader& config, const std::string& prefix) {
    SessionContext ctx;
    ctx.sessionId = "FIX_CLIENT_01";
    ctx.host = "127.0.0.1";
    ctx.port = 9876;
    ctx.senderCompId = "MARX_GW";
    ctx.targetCompId = "BROKER_FIX";
    ctx.protocol = "FIX.4.2";
    ctx.heartbeatIntervalSecs = 30;
    ctx.reconnectDelaySecs = 5;
    ctx.maxReconnectAttempts = 0;
    config.loadSession(prefix, ctx);
    return ctx;
}

FixClient::FixClient(const ConfigLoader& config, const std::string& prefix)
    : FixClient(loadFixCtx(config, prefix))
{
}

FixClient::FixClient(SessionContext ctx)
    : ClientSession(std::move(ctx))
    , hbManager_(io_, ctx_.heartbeatIntervalSecs)
    , encoder_(ctx_.protocol.empty() ? "FIX.4.2" : ctx_.protocol)
{
    // Wire up decoder callbacks
    decoder_.onMessage = [this](marx::fix::FixMessage msg) {
        handleIncomingMessage(msg);
    };

    decoder_.onError = [this](const std::string& err) {
        std::cerr << "[" << ctx_.sessionId << "] Decode error: " << err << "\n";
    };

    // Wire up HeartbeatManager callbacks
    hbManager_.onSendHeartbeat = [this]() {
        sendAdminMessage("0"); // Heartbeat MsgType is "0"
    };

    hbManager_.onSendTestRequest = [this](const std::string& testReqId) {
        sendAdminMessage("1", {{112, testReqId}}); // TestRequest MsgType is "1"
    };

    hbManager_.onTimeout = [this]() {
        std::cerr << "[" << ctx_.sessionId << "] Heartbeat timeout! Disconnecting...\n";
        stop();
    };
}

FixClient::~FixClient() {
    hbManager_.stop();
}

// ---------------------------------------------------------------------------
// initiateLogon
// ---------------------------------------------------------------------------
void FixClient::initiateLogon() {
    std::cout << "[" << ctx_.sessionId << "] Initiating FIX logon...\n";
    
    // Logon fields: EncryptMethod (98=0), HeartBtInt (108=heartbeatIntervalSecs)
    std::vector<marx::fix::FixField> fields;
    fields.push_back({98, "0"});
    fields.push_back({108, std::to_string(ctx_.heartbeatIntervalSecs)});
    
    sendAdminMessage("A", fields); // Logon MsgType is "A"
}

// ---------------------------------------------------------------------------
// onData
// ---------------------------------------------------------------------------
void FixClient::onData(const char* data, std::size_t len) {
    decoder_.onData(data, len);
}

// ---------------------------------------------------------------------------
// handleIncomingMessage
// ---------------------------------------------------------------------------
void FixClient::handleIncomingMessage(const marx::fix::FixMessage& msg) {
    // 1. Validate sequence number
    auto valResult = seqManager_.validate(msg.msgSeqNum);
    if (valResult == marx::fix::SequenceManager::ValidationResult::TooHigh) {
        std::cout << "[" << ctx_.sessionId << "] MsgSeqNum gap detected (Expected: " 
                  << seqManager_.incoming() << ", Received: " << msg.msgSeqNum << "). "
                  << "Requesting resend.\n";
        // Send ResendRequest (MsgType "2")
        std::vector<marx::fix::FixField> fields;
        fields.push_back({7, std::to_string(seqManager_.incoming())}); // BeginSeqNo
        fields.push_back({16, "0"}); // EndSeqNo (0 means infinity / current)
        sendAdminMessage("2", fields);
        return;
    } else if (valResult == marx::fix::SequenceManager::ValidationResult::TooLow) {
        // Skip duplicate or low sequence number unless PossDupFlag is set
        if (!msg.has(43) || msg.get(43) != "Y") {
            std::cerr << "[" << ctx_.sessionId << "] MsgSeqNum too low (" << msg.msgSeqNum 
                      << " < " << seqManager_.incoming() << ") without PossDupFlag. Skipping.\n";
            return;
        }
    }

    seqManager_.advanceIncoming();
    hbManager_.markReceived();

    // 2. Process message by MsgType
    if (msg.msgType == "A") { // Logon
        std::cout << "[" << ctx_.sessionId << "] FIX logon successful!\n";
        setState(ConnectionState::Active);
        hbManager_.start();
    } 
    else if (msg.msgType == "5") { // Logout
        std::cout << "[" << ctx_.sessionId << "] FIX logout received. Stopping session.\n";
        stop();
    }
    else if (msg.msgType == "0") { // Heartbeat
        // HeartbeatManager already updated by markReceived()
    }
    else if (msg.msgType == "1") { // TestRequest
        // Respond with Heartbeat including TestReqID
        std::string testReqId = msg.get(112);
        sendAdminMessage("0", {{112, testReqId}});
    }
    else if (msg.msgType == "D") { // NewOrderSingle
        std::cout << "[" << ctx_.sessionId << "] Received FIX NewOrderSingle. Converting to CDM...\n";
        
        try {
            FIX::messages::NewOrderSingle nos;
            if (msg.has(11)) nos.setClOrdID(FIX::fields::ClOrdID(msg.get(11)));
            if (msg.has(1)) nos.setAccount(FIX::fields::Account(msg.get(1)));
            if (msg.has(21) && !msg.get(21).empty()) nos.setHandlInst(FIX::fields::HandlInst(msg.get(21)[0]));
            if (msg.has(55)) nos.setSymbol(FIX::fields::Symbol(msg.get(55)));
            if (msg.has(48)) nos.setSecurityID(FIX::fields::SecurityID(msg.get(48)));
            if (msg.has(54) && !msg.get(54).empty()) nos.setSide(FIX::fields::Side(msg.get(54)[0]));
            if (msg.has(60) && !msg.get(60).empty()) nos.setTransactTime(FIX::fields::TransactTime(std::stoll(msg.get(60))));
            if (msg.has(40) && !msg.get(40).empty()) nos.setOrdType(FIX::fields::OrdType(msg.get(40)[0]));
            if (msg.has(38) && !msg.get(38).empty()) nos.setOrderQty(FIX::fields::OrderQty(std::stod(msg.get(38))));
            if (msg.has(44) && !msg.get(44).empty()) nos.setPrice(FIX::fields::Price(std::stod(msg.get(44))));
            if (msg.has(99) && !msg.get(99).empty()) nos.setStopPx(FIX::fields::StopPx(std::stod(msg.get(99))));
            if (msg.has(59) && !msg.get(59).empty()) nos.setTimeInForce(FIX::fields::TimeInForce(msg.get(59)[0]));
            if (msg.has(15)) nos.setCurrency(FIX::fields::Currency(msg.get(15)));
            if (msg.has(18) && !msg.get(18).empty()) nos.setExecInst(FIX::fields::ExecInst(msg.get(18)[0]));

            // Call template conversion via Fix entrypoint
            MODEL::messages::NewOrderRequest cdmReq = fix_.toNewOrderRequest(nos);
            
            std::cout << ">>> CONVERSION SUCCESSFUL:\n"
                      << "  ClientOrderId: " << cdmReq.getClientOrderId().toString() << "\n"
                      << "  Account: " << cdmReq.getAccount().toString() << "\n"
                      << "  Symbol: " << cdmReq.getSymbol().toString() << "\n"
                      << "  Side: " << cdmReq.getSide().toString() << "\n"
                      << "  OrdType: " << cdmReq.getOrderType().toString() << "\n"
                      << "  Qty: " << cdmReq.getOrderQty().get() << "\n"
                      << "  Price: " << cdmReq.getPrice().get() << "\n";
        } 
        catch (const std::exception& e) {
            std::cerr << "[" << ctx_.sessionId << "] Error during NewOrderSingle conversion: " << e.what() << "\n";
        }
    }
    else {
        std::cout << "[" << ctx_.sessionId << "] Received message of type: " << msg.msgType << "\n";
    }
}

// ---------------------------------------------------------------------------
// sendAdminMessage
// ---------------------------------------------------------------------------
void FixClient::sendAdminMessage(const std::string& msgType, const std::vector<marx::fix::FixField>& bodyFields) {
    auto outgoingSeq = seqManager_.next();
    auto rawBytes = encoder_.encode(msgType, outgoingSeq, ctx_.senderCompId, ctx_.targetCompId, bodyFields);
    send(std::move(rawBytes));
    hbManager_.markSent();
}

} // namespace marx::client::fix
