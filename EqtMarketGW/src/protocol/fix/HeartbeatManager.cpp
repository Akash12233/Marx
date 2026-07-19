#include "protocol/fix/HeartbeatManager.h"

#include <string>

namespace marx::fix {

HeartbeatManager::HeartbeatManager(asio::io_context& io, int intervalSecs)
    : io_(io)
    , intervalSecs_(intervalSecs)
    , sendTimer_(io)
    , receiveTimer_(io)
    , testReqTimer_(io)
{
}

// ---------------------------------------------------------------------------
// start / stop
// ---------------------------------------------------------------------------
void HeartbeatManager::start()
{
    running_ = true;
    testRequestPending_ = false;
    resetSendTimer();
    resetReceiveTimer();
}

void HeartbeatManager::stop()
{
    running_ = false;
    sendTimer_.cancel();
    receiveTimer_.cancel();
    testReqTimer_.cancel();
}

// ---------------------------------------------------------------------------
// markSent — reset the "need to send heartbeat" timer
// ---------------------------------------------------------------------------
void HeartbeatManager::markSent()
{
    if (running_) {
        resetSendTimer();
    }
}

// ---------------------------------------------------------------------------
// markReceived — reset the "expect data from peer" timer
// ---------------------------------------------------------------------------
void HeartbeatManager::markReceived()
{
    if (!running_) return;

    // If we were waiting for a TestRequest response, we got it
    if (testRequestPending_) {
        testRequestPending_ = false;
        testReqTimer_.cancel();
    }
    resetReceiveTimer();
}

// ---------------------------------------------------------------------------
// resetSendTimer — fires after heartbeatInterval of silence (no sends)
// ---------------------------------------------------------------------------
void HeartbeatManager::resetSendTimer()
{
    sendTimer_.cancel();
    sendTimer_.expires_after(std::chrono::seconds(intervalSecs_));
    sendTimer_.async_wait([this](std::error_code ec) {
        if (ec || !running_) return;
        if (onSendHeartbeat) onSendHeartbeat();
    });
}

// ---------------------------------------------------------------------------
// resetReceiveTimer — fires after heartbeatInterval + tolerance (no receives)
// ---------------------------------------------------------------------------
void HeartbeatManager::resetReceiveTimer()
{
    receiveTimer_.cancel();

    // FIX spec: if no data received for HeartBtInt + "reasonable transmission
    // time", send TestRequest.  We use 1.5x the interval as tolerance.
    auto timeout = std::chrono::milliseconds(
        static_cast<int>(intervalSecs_ * 1500));

    receiveTimer_.expires_after(timeout);
    receiveTimer_.async_wait([this](std::error_code ec) {
        if (ec || !running_) return;

        // No data from peer — send TestRequest
        testRequestPending_ = true;
        std::string testReqId = "TR-" + std::to_string(++testReqCounter_);
        if (onSendTestRequest) onSendTestRequest(testReqId);

        startTestRequestTimer();
    });
}

// ---------------------------------------------------------------------------
// startTestRequestTimer — if peer doesn't respond, we timeout
// ---------------------------------------------------------------------------
void HeartbeatManager::startTestRequestTimer()
{
    testReqTimer_.cancel();
    testReqTimer_.expires_after(std::chrono::seconds(intervalSecs_));
    testReqTimer_.async_wait([this](std::error_code ec) {
        if (ec || !running_) return;

        if (testRequestPending_) {
            // Peer didn't respond — connection is dead
            if (onTimeout) onTimeout();
        }
    });
}

} // namespace marx::fix
