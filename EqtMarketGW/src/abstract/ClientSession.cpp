#include "abstract/ClientSession.h"

#include <iostream>

namespace marx {

// ---------------------------------------------------------------------------
// onConnected — TCP is up, start protocol logon
// ---------------------------------------------------------------------------
void ClientSession::onConnected()
{
    std::cout << "[" << ctx_.sessionId << "] TCP connected to "
              << ctx_.host << ":" << ctx_.port << "\n";

    reconnectAttempts_ = 0;  // reset on successful connect
    initiateLogon();
}

// ---------------------------------------------------------------------------
// onDisconnected — schedule reconnect if allowed
// ---------------------------------------------------------------------------
void ClientSession::onDisconnected()
{
    std::cout << "[" << ctx_.sessionId << "] TCP disconnected\n";
    scheduleReconnect();
}

// ---------------------------------------------------------------------------
// scheduleReconnect
// ---------------------------------------------------------------------------
void ClientSession::scheduleReconnect()
{
    // Check if we've exhausted reconnect attempts (0 = unlimited)
    if (ctx_.maxReconnectAttempts > 0 &&
        reconnectAttempts_ >= static_cast<std::uint32_t>(ctx_.maxReconnectAttempts))
    {
        std::cerr << "[" << ctx_.sessionId
                  << "] max reconnect attempts reached (" << ctx_.maxReconnectAttempts
                  << "), giving up\n";
        return;
    }

    ++reconnectAttempts_;
    std::cout << "[" << ctx_.sessionId << "] reconnect attempt "
              << reconnectAttempts_ << " in " << ctx_.reconnectDelaySecs << "s\n";

    reconnectTimer_ = std::make_unique<asio::steady_timer>(io_);
    reconnectTimer_->expires_after(
        std::chrono::seconds(ctx_.reconnectDelaySecs));

    reconnectTimer_->async_wait(
        [this](std::error_code ec) {
            if (ec) {
                // Timer cancelled (session stopped), don't reconnect
                return;
            }
            setState(ConnectionState::Connecting);
            connection_.connect(ctx_.host, ctx_.port);
        });
}

} // namespace marx
