#include "client/ouch/Ouch.h"
#include "routing/Router.h"
#include <iostream>

namespace marx::client::ouch {

static SessionContext loadOuchCtx(const ConfigLoader& config, const std::string& prefix) {
    SessionContext ctx;
    ctx.sessionId = "OUCH_CLIENT_01";
    ctx.host = "127.0.0.1";
    ctx.port = 9877;
    ctx.senderCompId = "MARX_GW_OUCH";
    ctx.targetCompId = "EXCHANGE_OUCH";
    ctx.protocol = "OUCH";
    ctx.heartbeatIntervalSecs = 1;
    ctx.reconnectDelaySecs = 5;
    ctx.maxReconnectAttempts = 0;
    config.loadSession(prefix, ctx);
    return ctx;
}

OuchClient::OuchClient(const ConfigLoader& config, const std::string& prefix, Router* router)
    : OuchClient(loadOuchCtx(config, prefix), router)
{
}

OuchClient::OuchClient(SessionContext ctx, Router* router)
    : ClientSession(std::move(ctx))
    , router_(router)
{
    decoder_.onMessage = [this](const marx::ouch::OuchMessage& msg) {
        handleIncomingMessage(msg);
    };

    decoder_.onError = [this](const std::string& err) {
        std::cerr << "[" << ctx_.sessionId << "] OUCH decode error: " << err << "\n";
    };
}

// ---------------------------------------------------------------------------
// initiateLogon
// ---------------------------------------------------------------------------
void OuchClient::initiateLogon() {
    std::cout << "[" << ctx_.sessionId << "] OUCH session active (Logon complete)\n";
    setState(ConnectionState::Active);
}

// ---------------------------------------------------------------------------
// onData
// ---------------------------------------------------------------------------
void OuchClient::onData(const char* data, std::size_t len) {
    decoder_.onData(data, len);
}

// ---------------------------------------------------------------------------
// routeCDM (Polymorphic Outbound Sends)
// ---------------------------------------------------------------------------
void OuchClient::routeCDM(const MODEL::messages::NewOrderRequest& msg) {
    std::cout << "[" << ctx_.sessionId << "] Encoding NewOrderRequest to OUCH EnterOrder...\n";
    auto ouchMsg = ouch_.toEnterOrder(msg);
    auto bytes = encoder_.encode(ouchMsg);
    send(std::move(bytes));
}

void OuchClient::routeCDM(const MODEL::messages::ReplaceOrderRequest& msg) {
    std::cout << "[" << ctx_.sessionId << "] Encoding ReplaceOrderRequest to OUCH Replace...\n";
    auto ouchMsg = ouch_.toReplaceOrderRequest(msg);
    auto bytes = encoder_.encode(ouchMsg);
    send(std::move(bytes));
}

void OuchClient::routeCDM(const MODEL::messages::CancelOrderRequest& msg) {
    std::cout << "[" << ctx_.sessionId << "] Encoding CancelOrderRequest to OUCH Cancel...\n";
    auto ouchMsg = ouch_.toCancelOrderRequest(msg);
    auto bytes = encoder_.encode(ouchMsg);
    send(std::move(bytes));
}

// ---------------------------------------------------------------------------
// handleIncomingMessage (Inbound Executions from Venue)
// ---------------------------------------------------------------------------
void OuchClient::handleIncomingMessage(const marx::ouch::OuchMessage& msg) {
    std::visit([this](auto&& concreteMsg) {
        using T = std::decay_t<decltype(concreteMsg)>;
        
        if constexpr (std::is_same_v<T, OUCH::messages::OrderAccepted>) {
            std::cout << "[" << ctx_.sessionId << "] Received OUCH OrderAccepted.\n";
            auto cdm = ouch_.toCreateOrderExecution(concreteMsg);
            if (router_) {
                router_->routeFromVenue(cdm);
            }
        }
        else if constexpr (std::is_same_v<T, OUCH::messages::Rejected>) {
            std::cout << "[" << ctx_.sessionId << "] Received OUCH Rejected.\n";
            auto cdm = ouch_.toCreateOrderReject(concreteMsg);
            if (router_) {
                router_->routeFromVenue(cdm);
            }
        }
        else if constexpr (std::is_same_v<T, OUCH::messages::OrderExecuted>) {
            std::cout << "[" << ctx_.sessionId << "] Received OUCH OrderExecuted.\n";
            auto cdm = ouch_.toFillOrderExecution(concreteMsg);
            if (router_) {
                router_->routeFromVenue(cdm);
            }
        }
        else if constexpr (std::is_same_v<T, OUCH::messages::OrderReplaced>) {
            std::cout << "[" << ctx_.sessionId << "] Received OUCH OrderReplaced.\n";
            auto cdm = ouch_.toReplaceOrderExecution(concreteMsg);
            if (router_) {
                router_->routeFromVenue(cdm);
            }
        }
        else if constexpr (std::is_same_v<T, OUCH::messages::OrderCanceled>) {
            std::cout << "[" << ctx_.sessionId << "] Received OUCH OrderCanceled.\n";
            auto cdm = ouch_.toCancelOrderExecution(concreteMsg);
            if (router_) {
                router_->routeFromVenue(cdm);
            }
        }
        else {
            std::cout << "[" << ctx_.sessionId << "] Received unhandled OUCH message variant.\n";
        }
    }, msg);
}

} // namespace marx::client::ouch
