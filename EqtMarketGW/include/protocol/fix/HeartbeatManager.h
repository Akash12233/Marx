#pragma once

#include <asio.hpp>

#include <chrono>
#include <functional>

namespace marx::fix {

/// Manages FIX heartbeat timing and TestRequest logic.
///
/// Two timers:
///   1. **Send timer** — fires when we haven't sent anything for heartbeatInterval.
///      We need to send a Heartbeat to keep the session alive.
///   2. **Receive timer** — fires when we haven't received anything for
///      heartbeatInterval + reasonable tolerance. We send a TestRequest.
///      If the peer doesn't respond within another interval, we declare timeout.
///
/// The session calls markSent() / markReceived() on every outgoing / incoming
/// message to reset the respective timers.
class HeartbeatManager {
public:
    /// @param io            The session's io_context (for timers).
    /// @param intervalSecs  FIX HeartBtInt value (tag 108).
    HeartbeatManager(asio::io_context& io, int intervalSecs);

    // ---- Lifecycle -------------------------------------------------------
    void start();
    void stop();

    // ---- Called by session on every send / receive -----------------------
    void markSent();
    void markReceived();

    // ---- Callbacks (set by the owning session) ---------------------------
    /// Time to send a Heartbeat (no outgoing traffic for an interval).
    std::function<void()> onSendHeartbeat;

    /// Peer hasn't sent anything — send a TestRequest.
    std::function<void(const std::string& testReqId)> onSendTestRequest;

    /// Peer didn't respond to TestRequest — connection is dead.
    std::function<void()> onTimeout;

    // ---- Accessors -------------------------------------------------------
    int intervalSecs() const { return intervalSecs_; }

private:
    void resetSendTimer();
    void resetReceiveTimer();
    void startTestRequestTimer();

    asio::io_context& io_;
    int intervalSecs_;

    asio::steady_timer sendTimer_;
    asio::steady_timer receiveTimer_;
    asio::steady_timer testReqTimer_;

    bool running_ = false;
    bool testRequestPending_ = false;
    std::uint64_t testReqCounter_ = 0;   ///< for generating unique TestReqIDs
};

} // namespace marx::fix
