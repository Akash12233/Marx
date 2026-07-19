#pragma once

#include <cstdint>
#include <string>

namespace marx {

/// Configuration for a single session instance.
/// Loaded from config and passed to the session at construction time.
struct SessionContext {
    std::string sessionId;       ///< Unique identifier for this session (e.g. "BROKER_A")
    std::string senderCompId;    ///< "Who am I" on the wire (FIX: SenderCompID)
    std::string targetCompId;    ///< "Who am I talking to" (FIX: TargetCompID)
    std::string host;            ///< Remote host to connect to
    std::uint16_t port = 0;      ///< Remote port

    std::string protocol;        ///< Protocol name: "FIX", "OUCH", etc.

    // Connection tuning
    int heartbeatIntervalSecs = 30;   ///< Heartbeat interval (protocol-specific)
    int reconnectDelaySecs    = 5;    ///< Delay before reconnect attempt
    int maxReconnectAttempts  = 10;   ///< 0 = unlimited
    
    bool isVenue = false;             ///< True if this session faces a venue/exchange
};

} // namespace marx
