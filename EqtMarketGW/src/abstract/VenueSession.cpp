#include "abstract/VenueSession.h"

#include <iostream>

namespace marx {

// ---------------------------------------------------------------------------
// onConnected — TCP is up, wait for logon from counterparty
// ---------------------------------------------------------------------------
void VenueSession::onConnected()
{
    std::cout << "[" << ctx_.sessionId << "] TCP connected (venue side), "
              << "waiting for logon from counterparty\n";
    reconnectAttempts_ = 0;
}

// ---------------------------------------------------------------------------
// onDisconnected — schedule reconnect
// ---------------------------------------------------------------------------
void VenueSession::onDisconnected()
{
    std::cout << "[" << ctx_.sessionId << "] TCP disconnected (venue side)\n";
    scheduleReconnect();
}

// ---------------------------------------------------------------------------
// scheduleReconnect
// ---------------------------------------------------------------------------
void VenueSession::scheduleReconnect()
{
    if (ctx_.maxReconnectAttempts > 0 &&
        reconnectAttempts_ >= static_cast<std::uint32_t>(ctx_.maxReconnectAttempts))
    {
        return;
    }

    ++reconnectAttempts_;

    reconnectTimer_ = std::make_unique<asio::steady_timer>(io_);
    reconnectTimer_->expires_after(
        std::chrono::seconds(ctx_.reconnectDelaySecs > 0 ? ctx_.reconnectDelaySecs : 1));

    reconnectTimer_->async_wait(
        [this](std::error_code ec) {
            if (ec) {
                return;
            }
            setState(ConnectionState::Connecting);
            connection_.connect(ctx_.host, ctx_.port);
        });
}

} // namespace marx
