#pragma once

#include "abstract/Session.h"

namespace marx {

/// Venue-side session base (Marx acts as server or connects to exchange).
///
/// Adds on top of Session:
///   - Responds to logon (doesn't initiate)
///   - Different disconnect handling (no auto-reconnect by default)
///
/// Protocol-derived classes (FixVenueSession, OuchVenueSession) implement:
///   - respondToLogon()  — validate and ack the incoming logon message
///   - onData()          — decode incoming wire bytes
class VenueSession : public Session {
public:
    using Session::Session;
    ~VenueSession() override = default;

protected:
    // ---- Session hooks ---------------------------------------------------

    /// TCP is up.  Venue side waits for the counterparty to send logon.
    void onConnected() override;

    /// TCP went down.  Schedule reconnect if enabled.
    void onDisconnected() override;

    // ---- Protocol hook (pure virtual) ------------------------------------

    /// Called when the protocol layer receives a logon message.
    /// Derived class validates and sends back a logon acknowledgement.
    virtual void respondToLogon() = 0;

private:
    void scheduleReconnect();

    std::uint32_t reconnectAttempts_ = 0;
    std::unique_ptr<asio::steady_timer> reconnectTimer_;
};

} // namespace marx
