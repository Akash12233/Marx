#include "client/fix/Fix.h"
#include "routing/Router.h"
#include "routing/InternalReject.h"
#include "abstract/Logger.h"

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

FixClient::FixClient(const ConfigLoader& config, const std::string& prefix, Router* router)
    : FixClient(loadFixCtx(config, prefix), router)
{
}

FixClient::FixClient(SessionContext ctx, Router* router)
    : ClientSession(std::move(ctx))
    , hbManager_(io_, ctx_.heartbeatIntervalSecs)
    , encoder_(ctx_.protocol.empty() ? "FIX.4.2" : ctx_.protocol)
    , router_(router)
{
    // Wire up decoder callbacks
    decoder_.onMessage = [this](marx::fix::FixMessage msg) {
        handleIncomingMessage(msg);
    };

    decoder_.onError = [this](const std::string& err) {
        LOG_ERROR("FixClient", "[" + ctx_.sessionId + "] Decode error: " + err);
    };

    // Wire up HeartbeatManager callbacks
    hbManager_.onSendHeartbeat = [this]() {
        sendAdminMessage("0"); // Heartbeat MsgType is "0"
    };

    hbManager_.onSendTestRequest = [this](const std::string& testReqId) {
        sendAdminMessage("1", {{112, testReqId}}); // TestRequest MsgType is "1"
    };

    hbManager_.onTimeout = [this]() {
        LOG_WARN("FixClient", "[" + ctx_.sessionId + "] Heartbeat timeout! Disconnecting...");
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
    LOG_INFO("FixClient", "[" + ctx_.sessionId + "] Initiating FIX logon...");
    
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
        LOG_WARN("FixClient", "[" + ctx_.sessionId + "] MsgSeqNum gap detected (Expected: " 
                  + std::to_string(seqManager_.incoming()) + ", Received: " + std::to_string(msg.msgSeqNum) + "). Requesting resend.");
        std::vector<marx::fix::FixField> fields;
        fields.push_back({7, std::to_string(seqManager_.incoming())}); // BeginSeqNo
        fields.push_back({16, "0"}); // EndSeqNo (0 means infinity / current)
        sendAdminMessage("2", fields);
        return;
    } else if (valResult == marx::fix::SequenceManager::ValidationResult::TooLow) {
        if (!msg.has(43) || msg.get(43) != "Y") {
            LOG_WARN("FixClient", "[" + ctx_.sessionId + "] MsgSeqNum too low (" + std::to_string(msg.msgSeqNum) 
                      + " < " + std::to_string(seqManager_.incoming()) + ") without PossDupFlag. Skipping.");
            return;
        }
    }

    seqManager_.advanceIncoming();
    hbManager_.markReceived();

    // Log client incoming message
    Logger::instance().logClient("RECV", ctx_.sessionId, "MsgType=" + msg.msgType + " Seq=" + std::to_string(msg.msgSeqNum));

    // 2. Process message by MsgType
    if (msg.msgType == "A") { // Logon
        LOG_INFO("FixClient", "[" + ctx_.sessionId + "] FIX logon successful!");
        setState(ConnectionState::Active);
        hbManager_.start();
    } 
    else if (msg.msgType == "5") { // Logout
        LOG_INFO("FixClient", "[" + ctx_.sessionId + "] FIX logout received. Stopping session.");
        stop();
    }
    else if (msg.msgType == "0") { // Heartbeat
        // HeartbeatManager already updated by markReceived()
    }
    else if (msg.msgType == "1") { // TestRequest
        std::string testReqId = msg.get(112);
        sendAdminMessage("0", {{112, testReqId}});
    }
    else if (msg.msgType == "D") { // NewOrderSingle
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

            MODEL::messages::NewOrderRequest cdmReq = fix_.toNewOrderRequest(nos);
            
            if (router_) {
                router_->routeFromClient(ctx_.sessionId, cdmReq);
            }
        } 
        catch (const std::exception& e) {
            LOG_ERROR("FixClient", "[" + ctx_.sessionId + "] Exception during NewOrderSingle conversion: " + std::string(e.what()));
            std::string clOrdId = msg.has(11) ? msg.get(11) : "UNKNOWN";
            auto rej = InternalReject::createOrderReject(clOrdId, e.what());
            routeCDM(rej);
        }
    }
    else if (msg.msgType == "F") { // OrderCancelRequest
        try {
            FIX::messages::OrderCancelRequest req;
            if (msg.has(11)) req.setClOrdID(FIX::fields::ClOrdID(msg.get(11)));
            if (msg.has(41)) req.setOrigClOrdID(FIX::fields::OrigClOrdID(msg.get(41)));
            if (msg.has(55)) req.setSymbol(FIX::fields::Symbol(msg.get(55)));
            if (msg.has(54) && !msg.get(54).empty()) req.setSide(FIX::fields::Side(msg.get(54)[0]));

            MODEL::messages::CancelOrderRequest cdmReq = fix_.toCancelOrderRequest(req);

            if (router_) {
                router_->routeFromClient(ctx_.sessionId, cdmReq);
            }
        }
        catch (const std::exception& e) {
            LOG_ERROR("FixClient", "[" + ctx_.sessionId + "] Exception during OrderCancelRequest conversion: " + std::string(e.what()));
            std::string clOrdId = msg.has(11) ? msg.get(11) : "UNKNOWN";
            auto rej = InternalReject::cancelOrderReject(clOrdId, e.what());
            routeCDM(rej);
        }
    }
    else if (msg.msgType == "G") { // OrderCancelReplaceRequest
        try {
            FIX::messages::OrderCancelReplaceRequest req;
            if (msg.has(11)) req.setClOrdID(FIX::fields::ClOrdID(msg.get(11)));
            if (msg.has(41)) req.setOrigClOrdID(FIX::fields::OrigClOrdID(msg.get(41)));
            if (msg.has(38) && !msg.get(38).empty()) req.setOrderQty(FIX::fields::OrderQty(std::stod(msg.get(38))));
            if (msg.has(44) && !msg.get(44).empty()) req.setPrice(FIX::fields::Price(std::stod(msg.get(44))));
            if (msg.has(99) && !msg.get(99).empty()) req.setStopPx(FIX::fields::StopPx(std::stod(msg.get(99))));
            if (msg.has(59) && !msg.get(59).empty()) req.setTimeInForce(FIX::fields::TimeInForce(msg.get(59)[0]));

            MODEL::messages::ReplaceOrderRequest cdmReq = fix_.toReplaceOrderRequest(req);

            if (router_) {
                router_->routeFromClient(ctx_.sessionId, cdmReq);
            }
        }
        catch (const std::exception& e) {
            LOG_ERROR("FixClient", "[" + ctx_.sessionId + "] Exception during OrderCancelReplaceRequest conversion: " + std::string(e.what()));
            std::string clOrdId = msg.has(11) ? msg.get(11) : "UNKNOWN";
            auto rej = InternalReject::replaceOrderReject(clOrdId, e.what());
            routeCDM(rej);
        }
    }
    else {
        LOG_INFO("FixClient", "[" + ctx_.sessionId + "] Received message of type: " + msg.msgType);
    }
}

// ---------------------------------------------------------------------------
// routeCDM (Polymorphic Outbound Sends to Client)
// ---------------------------------------------------------------------------
void FixClient::routeCDM(const MODEL::messages::CreateOrderExecution& msg) {
    try {
        auto execReport = fix_.toExecutionReport(msg);
        auto outgoingSeq = seqManager_.next();
        std::vector<marx::fix::FixField> bodyFields;
        bodyFields.push_back({11, execReport.getClOrdID().toString()});
        bodyFields.push_back({37, execReport.getOrderID().toString()});
        bodyFields.push_back({17, execReport.getExecID().toString()});
        bodyFields.push_back({150, std::string(1, execReport.getExecType().get())});
        bodyFields.push_back({39, std::string(1, execReport.getOrdStatus().get())});
        bodyFields.push_back({38, std::to_string(execReport.getOrderQty().get())});
        bodyFields.push_back({14, std::to_string(execReport.getCumQty().get())});
        bodyFields.push_back({151, std::to_string(execReport.getLeavesQty().get())});
        bodyFields.push_back({6, std::to_string(execReport.getAvgPx().get())});

        auto rawBytes = encoder_.encode("8", outgoingSeq, ctx_.senderCompId, ctx_.targetCompId, bodyFields);
        Logger::instance().logClient("SEND", ctx_.sessionId, "Sending ExecutionReport (CreateOrderExecution ClOrdID=" + msg.getClientOrderId().toString() + ")");
        send(std::move(rawBytes));
        hbManager_.markSent();
    } catch (const std::exception& e) {
        LOG_ERROR("FixClient", "[" + ctx_.sessionId + "] Exception encoding CreateOrderExecution to FIX: " + std::string(e.what()));
    }
}

void FixClient::routeCDM(const MODEL::messages::CreateOrderReject& msg) {
    try {
        auto outgoingSeq = seqManager_.next();
        std::vector<marx::fix::FixField> bodyFields;
        bodyFields.push_back({11, msg.getClientOrderId().toString()});
        bodyFields.push_back({37, msg.getVenueOrderId().toString()});
        bodyFields.push_back({17, msg.getExecutionId().toString()});
        bodyFields.push_back({150, "8"}); // Rejected
        bodyFields.push_back({39, "8"}); // Rejected
        bodyFields.push_back({58, msg.getText().toString()});

        auto rawBytes = encoder_.encode("8", outgoingSeq, ctx_.senderCompId, ctx_.targetCompId, bodyFields);
        Logger::instance().logClient("SEND", ctx_.sessionId, "Sending ExecutionReport (CreateOrderReject ClOrdID=" + msg.getClientOrderId().toString() + ")");
        send(std::move(rawBytes));
        hbManager_.markSent();
    } catch (const std::exception& e) {
        LOG_ERROR("FixClient", "[" + ctx_.sessionId + "] Exception encoding CreateOrderReject to FIX: " + std::string(e.what()));
    }
}

void FixClient::routeCDM(const MODEL::messages::ReplaceOrderExecution& msg) {
    try {
        auto outgoingSeq = seqManager_.next();
        std::vector<marx::fix::FixField> bodyFields;
        bodyFields.push_back({11, msg.getClientOrderId().toString()});
        bodyFields.push_back({37, msg.getVenueOrderId().toString()});
        bodyFields.push_back({17, msg.getExecutionId().toString()});
        bodyFields.push_back({150, "5"}); // Replaced
        bodyFields.push_back({39, "5"}); // Replaced
        bodyFields.push_back({38, std::to_string(msg.getOrderQty().get())});

        auto rawBytes = encoder_.encode("8", outgoingSeq, ctx_.senderCompId, ctx_.targetCompId, bodyFields);
        Logger::instance().logClient("SEND", ctx_.sessionId, "Sending ExecutionReport (ReplaceOrderExecution ClOrdID=" + msg.getClientOrderId().toString() + ")");
        send(std::move(rawBytes));
        hbManager_.markSent();
    } catch (const std::exception& e) {
        LOG_ERROR("FixClient", "[" + ctx_.sessionId + "] Exception encoding ReplaceOrderExecution to FIX: " + std::string(e.what()));
    }
}

void FixClient::routeCDM(const MODEL::messages::ReplaceOrderReject& msg) {
    try {
        auto outgoingSeq = seqManager_.next();
        std::vector<marx::fix::FixField> bodyFields;
        bodyFields.push_back({11, msg.getClientOrderId().toString()});
        bodyFields.push_back({37, msg.getVenueOrderId().toString()});
        bodyFields.push_back({39, std::string(1, msg.getOrderStatus().get())});
        bodyFields.push_back({58, msg.getRejectReason().toString()});

        auto rawBytes = encoder_.encode("9", outgoingSeq, ctx_.senderCompId, ctx_.targetCompId, bodyFields);
        Logger::instance().logClient("SEND", ctx_.sessionId, "Sending OrderCancelReject (ReplaceOrderReject ClOrdID=" + msg.getClientOrderId().toString() + ")");
        send(std::move(rawBytes));
        hbManager_.markSent();
    } catch (const std::exception& e) {
        LOG_ERROR("FixClient", "[" + ctx_.sessionId + "] Exception encoding ReplaceOrderReject to FIX: " + std::string(e.what()));
    }
}

void FixClient::routeCDM(const MODEL::messages::CancelOrderExecution& msg) {
    try {
        auto outgoingSeq = seqManager_.next();
        std::vector<marx::fix::FixField> bodyFields;
        bodyFields.push_back({11, msg.getClientOrderId().toString()});
        bodyFields.push_back({37, msg.getVenueOrderId().toString()});
        bodyFields.push_back({17, msg.getExecutionId().toString()});
        bodyFields.push_back({150, "4"}); // Canceled
        bodyFields.push_back({39, "4"}); // Canceled

        auto rawBytes = encoder_.encode("8", outgoingSeq, ctx_.senderCompId, ctx_.targetCompId, bodyFields);
        Logger::instance().logClient("SEND", ctx_.sessionId, "Sending ExecutionReport (CancelOrderExecution ClOrdID=" + msg.getClientOrderId().toString() + ")");
        send(std::move(rawBytes));
        hbManager_.markSent();
    } catch (const std::exception& e) {
        LOG_ERROR("FixClient", "[" + ctx_.sessionId + "] Exception encoding CancelOrderExecution to FIX: " + std::string(e.what()));
    }
}

void FixClient::routeCDM(const MODEL::messages::CancelOrderReject& msg) {
    try {
        auto outgoingSeq = seqManager_.next();
        std::vector<marx::fix::FixField> bodyFields;
        bodyFields.push_back({11, msg.getClientOrderId().toString()});
        bodyFields.push_back({37, msg.getVenueOrderId().toString()});
        bodyFields.push_back({39, std::string(1, msg.getOrderStatus().get())});
        bodyFields.push_back({58, msg.getRejectReason().toString()});

        auto rawBytes = encoder_.encode("9", outgoingSeq, ctx_.senderCompId, ctx_.targetCompId, bodyFields);
        Logger::instance().logClient("SEND", ctx_.sessionId, "Sending OrderCancelReject (CancelOrderReject ClOrdID=" + msg.getClientOrderId().toString() + ")");
        send(std::move(rawBytes));
        hbManager_.markSent();
    } catch (const std::exception& e) {
        LOG_ERROR("FixClient", "[" + ctx_.sessionId + "] Exception encoding CancelOrderReject to FIX: " + std::string(e.what()));
    }
}

void FixClient::routeCDM(const MODEL::messages::FillOrderExecution& msg) {
    try {
        auto outgoingSeq = seqManager_.next();
        std::vector<marx::fix::FixField> bodyFields;
        bodyFields.push_back({11, msg.getClientOrderId().toString()});
        bodyFields.push_back({37, msg.getVenueOrderId().toString()});
        bodyFields.push_back({17, msg.getExecutionId().toString()});
        bodyFields.push_back({150, "2"}); // Fill
        bodyFields.push_back({39, std::string(1, msg.getOrderStatus().get())});
        bodyFields.push_back({32, std::to_string(msg.getLastFillQuantity().get())});
        bodyFields.push_back({31, std::to_string(msg.getLastFillPrice().get())});
        bodyFields.push_back({14, std::to_string(msg.getCumQty().get())});
        bodyFields.push_back({151, std::to_string(msg.getLeavesQty().get())});

        auto rawBytes = encoder_.encode("8", outgoingSeq, ctx_.senderCompId, ctx_.targetCompId, bodyFields);
        Logger::instance().logClient("SEND", ctx_.sessionId, "Sending ExecutionReport (FillOrderExecution ClOrdID=" + msg.getClientOrderId().toString() + ")");
        send(std::move(rawBytes));
        hbManager_.markSent();
    } catch (const std::exception& e) {
        LOG_ERROR("FixClient", "[" + ctx_.sessionId + "] Exception encoding FillOrderExecution to FIX: " + std::string(e.what()));
    }
}

// ---------------------------------------------------------------------------
// sendAdminMessage
// ---------------------------------------------------------------------------
void FixClient::sendAdminMessage(const std::string& msgType, const std::vector<marx::fix::FixField>& bodyFields) {
    try {
        auto outgoingSeq = seqManager_.next();
        auto rawBytes = encoder_.encode(msgType, outgoingSeq, ctx_.senderCompId, ctx_.targetCompId, bodyFields);
        Logger::instance().logClient("SEND", ctx_.sessionId, "Admin MsgType=" + msgType + " Seq=" + std::to_string(outgoingSeq));
        send(std::move(rawBytes));
        hbManager_.markSent();
    } catch (const std::exception& e) {
        LOG_ERROR("FixClient", "[" + ctx_.sessionId + "] Exception encoding admin message: " + std::string(e.what()));
    }
}

} // namespace marx::client::fix
