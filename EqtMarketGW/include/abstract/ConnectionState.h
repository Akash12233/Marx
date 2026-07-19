#pragma once

namespace marx {

/// Lifecycle state of a session's connection.
enum class ConnectionState {
    Disconnected,   ///< No TCP connection
    Connecting,     ///< TCP connect in progress
    Connected,      ///< TCP up, not yet logged on
    Active,         ///< Logged on, ready for business messages
    Disconnecting   ///< Graceful shutdown in progress
};

/// Returns a human-readable label for the state (useful for logging).
inline const char* toString(ConnectionState s) {
    switch (s) {
        case ConnectionState::Disconnected:  return "Disconnected";
        case ConnectionState::Connecting:    return "Connecting";
        case ConnectionState::Connected:     return "Connected";
        case ConnectionState::Active:        return "Active";
        case ConnectionState::Disconnecting: return "Disconnecting";
    }
    return "Unknown";
}

} // namespace marx
