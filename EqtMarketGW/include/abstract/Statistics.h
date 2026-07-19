#pragma once

#include <atomic>
#include <chrono>
#include <cstdint>

namespace marx {

/// Per-session runtime statistics.
/// All counters are atomic so stats can be read from a monitoring thread
/// without locking the session's I/O thread.
struct Statistics {
    std::atomic<std::uint64_t> messagesSent{0};
    std::atomic<std::uint64_t> messagesReceived{0};
    std::atomic<std::uint64_t> bytesSent{0};
    std::atomic<std::uint64_t> bytesReceived{0};

    /// Epoch-millis of last successful send / receive.
    std::atomic<std::int64_t> lastSendTimeMs{0};
    std::atomic<std::int64_t> lastReceiveTimeMs{0};

    void recordSend(std::uint64_t bytes) {
        messagesSent.fetch_add(1, std::memory_order_relaxed);
        bytesSent.fetch_add(bytes, std::memory_order_relaxed);
        lastSendTimeMs.store(
            std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now().time_since_epoch())
                .count(),
            std::memory_order_relaxed);
    }

    void recordReceive(std::uint64_t bytes) {
        messagesReceived.fetch_add(1, std::memory_order_relaxed);
        bytesReceived.fetch_add(bytes, std::memory_order_relaxed);
        lastReceiveTimeMs.store(
            std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now().time_since_epoch())
                .count(),
            std::memory_order_relaxed);
    }

    void reset() {
        messagesSent.store(0, std::memory_order_relaxed);
        messagesReceived.store(0, std::memory_order_relaxed);
        bytesSent.store(0, std::memory_order_relaxed);
        bytesReceived.store(0, std::memory_order_relaxed);
        lastSendTimeMs.store(0, std::memory_order_relaxed);
        lastReceiveTimeMs.store(0, std::memory_order_relaxed);
    }
};

} // namespace marx
