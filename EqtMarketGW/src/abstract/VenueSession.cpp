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
    // Venue doesn't initiate logon — the protocol layer's onData() will
    // detect the incoming Logon message and call respondToLogon().
}

// ---------------------------------------------------------------------------
// onDisconnected — venue sessions don't auto-reconnect
// ---------------------------------------------------------------------------
void VenueSession::onDisconnected()
{
    std::cout << "[" << ctx_.sessionId << "] TCP disconnected (venue side)\n";
    // No auto-reconnect.  The VenueManager is responsible for deciding
    // whether to re-listen or create a new session.
}

} // namespace marx
