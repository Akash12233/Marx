#include "venue/ouch/Ouch.h"
#include "routing/Router.h"
#include "abstract/Logger.h"
#include <iostream>

namespace marx::venue::ouch {

static SessionContext loadOuchCtx(const ConfigLoader& config, const std::string& prefix) {
    SessionContext ctx;
    ctx.sessionId = "OUCH_VENUE_01";
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

OuchVenue::OuchVenue(const ConfigLoader& config, const std::string& prefix, Router* router)
    : OuchVenue(loadOuchCtx(config, prefix), router)
{
}

OuchVenue::OuchVenue(SessionContext ctx, Router* router)
    : VenueSession(std::move(ctx))
    , router_(router)
{
    decoder_.onMessage = [this](const marx::ouch::OuchMessage& msg) {
        handleIncomingMessage(msg);
    };

    decoder_.onError = [this](const std::string& err) {
        LOG_ERROR("OuchVenue", "[" + ctx_.sessionId + "] OUCH decode error: " + err);
    };
}

// ---------------------------------------------------------------------------
// onConnected
// ---------------------------------------------------------------------------
void OuchVenue::onConnected() {
    VenueSession::onConnected();
    respondToLogon();
}

// ---------------------------------------------------------------------------
// respondToLogon
// ---------------------------------------------------------------------------
void OuchVenue::respondToLogon() {
    LOG_INFO("OuchVenue", "[" + ctx_.sessionId + "] OUCH session active (Logon complete)");
    setState(ConnectionState::Active);
}

// ---------------------------------------------------------------------------
// onData
// ---------------------------------------------------------------------------
void OuchVenue::onData(const char* data, std::size_t len) {
    decoder_.onData(data, len);
}

// ---------------------------------------------------------------------------
// routeCDM (Polymorphic Outbound Sends to Venue)
// ---------------------------------------------------------------------------
void OuchVenue::routeCDM(const MODEL::messages::NewOrderRequest& msg) {
    try {
        auto ouchMsg = ouch_.toEnterOrder(msg);
        auto bytes = encoder_.encode(ouchMsg);
        Logger::instance().logVenue("SEND", ctx_.sessionId, "Sending OUCH EnterOrder (ClOrdID=" + msg.getClientOrderId().toString() + ")");
        send(std::move(bytes));
    } catch (const std::exception& e) {
        LOG_ERROR("OuchVenue", "[" + ctx_.sessionId + "] Exception converting/encoding NewOrderRequest to OUCH EnterOrder: " + std::string(e.what()));
    }
}

void OuchVenue::routeCDM(const MODEL::messages::ReplaceOrderRequest& msg) {
    try {
        auto ouchMsg = ouch_.toReplaceOrderRequest(msg);
        auto bytes = encoder_.encode(ouchMsg);
        Logger::instance().logVenue("SEND", ctx_.sessionId, "Sending OUCH ReplaceOrderRequest (ClOrdID=" + msg.getClientOrderId().toString() + ")");
        send(std::move(bytes));
    } catch (const std::exception& e) {
        LOG_ERROR("OuchVenue", "[" + ctx_.sessionId + "] Exception converting/encoding ReplaceOrderRequest to OUCH: " + std::string(e.what()));
    }
}

void OuchVenue::routeCDM(const MODEL::messages::CancelOrderRequest& msg) {
    try {
        auto ouchMsg = ouch_.toCancelOrderRequest(msg);
        auto bytes = encoder_.encode(ouchMsg);
        Logger::instance().logVenue("SEND", ctx_.sessionId, "Sending OUCH CancelOrderRequest (ClOrdID=" + msg.getClientOrderId().toString() + ")");
        send(std::move(bytes));
    } catch (const std::exception& e) {
        LOG_ERROR("OuchVenue", "[" + ctx_.sessionId + "] Exception converting/encoding CancelOrderRequest to OUCH: " + std::string(e.what()));
    }
}

// ---------------------------------------------------------------------------
// handleIncomingMessage (Inbound Executions from Venue)
// ---------------------------------------------------------------------------
void OuchVenue::handleIncomingMessage(const marx::ouch::OuchMessage& msg) {
    std::visit([this](auto&& concreteMsg) {
        using T = std::decay_t<decltype(concreteMsg)>;
        
        if constexpr (std::is_same_v<T, OUCH::messages::OrderAccepted>) {
            Logger::instance().logVenue("RECV", ctx_.sessionId, "Received OUCH OrderAccepted");
            try {
                auto cdm = ouch_.toCreateOrderExecution(concreteMsg);
                if (router_) {
                    router_->routeFromVenue(cdm);
                }
            } catch (const std::exception& e) {
                LOG_ERROR("OuchVenue", "[" + ctx_.sessionId + "] Exception converting OUCH OrderAccepted to CDM: " + std::string(e.what()));
            }
        }
        else if constexpr (std::is_same_v<T, OUCH::messages::Rejected>) {
            Logger::instance().logVenue("RECV", ctx_.sessionId, "Received OUCH Rejected");
            try {
                auto cdm = ouch_.toCreateOrderReject(concreteMsg);
                if (router_) {
                    router_->routeFromVenue(cdm);
                }
            } catch (const std::exception& e) {
                LOG_ERROR("OuchVenue", "[" + ctx_.sessionId + "] Exception converting OUCH Rejected to CDM: " + std::string(e.what()));
            }
        }
        else if constexpr (std::is_same_v<T, OUCH::messages::OrderExecuted>) {
            Logger::instance().logVenue("RECV", ctx_.sessionId, "Received OUCH OrderExecuted");
            try {
                auto cdm = ouch_.toFillOrderExecution(concreteMsg);
                if (router_) {
                    router_->routeFromVenue(cdm);
                }
            } catch (const std::exception& e) {
                LOG_ERROR("OuchVenue", "[" + ctx_.sessionId + "] Exception converting OUCH OrderExecuted to CDM: " + std::string(e.what()));
            }
        }
        else if constexpr (std::is_same_v<T, OUCH::messages::OrderReplaced>) {
            Logger::instance().logVenue("RECV", ctx_.sessionId, "Received OUCH OrderReplaced");
            try {
                auto cdm = ouch_.toReplaceOrderExecution(concreteMsg);
                if (router_) {
                    router_->routeFromVenue(cdm);
                }
            } catch (const std::exception& e) {
                LOG_ERROR("OuchVenue", "[" + ctx_.sessionId + "] Exception converting OUCH OrderReplaced to CDM: " + std::string(e.what()));
            }
        }
        else if constexpr (std::is_same_v<T, OUCH::messages::OrderCanceled>) {
            Logger::instance().logVenue("RECV", ctx_.sessionId, "Received OUCH OrderCanceled");
            try {
                auto cdm = ouch_.toCancelOrderExecution(concreteMsg);
                if (router_) {
                    router_->routeFromVenue(cdm);
                }
            } catch (const std::exception& e) {
                LOG_ERROR("OuchVenue", "[" + ctx_.sessionId + "] Exception converting OUCH OrderCanceled to CDM: " + std::string(e.what()));
            }
        }
        else {
            LOG_WARN("OuchVenue", "[" + ctx_.sessionId + "] Received unhandled OUCH message variant.");
        }
    }, msg);
}

} // namespace marx::venue::ouch
