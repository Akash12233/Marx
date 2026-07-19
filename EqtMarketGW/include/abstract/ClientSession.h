#pragma once

#include "abstract/Session.h"

#include <asio.hpp>

#include <cstdint>
#include <memory>

namespace marx {

/// Client-side session base (Marx connects outbound to broker / venue).
///
/// Adds on top of Session:
///   - Initiates logon after TCP connects  (via pure virtual initiateLogon)
///   - Auto-reconnect on disconnect
///
/// Protocol-derived classes (FixClientSession, OuchClientSession) only
/// need to implement:
///   - initiateLogon()   — build and send a protocol-specific logon message
///   - onData()          — decode incoming wire bytes
class ClientSession : public Session {
public:
    using Session::Session;
    ~ClientSession() override = default;

protected:
    // ---- Session hooks ---------------------------------------------------

    /// TCP is up.  Kick off the protocol handshake.
    void onConnected() override;

    /// TCP went down.  Schedule a reconnect if attempts remain.
    void onDisconnected() override;

    // ---- Protocol hook (pure virtual) ------------------------------------

    /// Derived class builds and sends its protocol's logon message here.
    /// Called automatically by onConnected().
    virtual void initiateLogon() = 0;

private:
    void scheduleReconnect();

    std::uint32_t reconnectAttempts_ = 0;

    /// Timer for delayed reconnect (lives on the session's io_context).
    std::unique_ptr<asio::steady_timer> reconnectTimer_;
};

} // namespace marx
