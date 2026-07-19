#pragma once

#include <asio.hpp>

#include <array>
#include <cstdint>
#include <deque>
#include <functional>
#include <string>
#include <vector>

namespace marx {

/// Asynchronous TCP connection wrapper around an Asio socket.
///
/// Protocol-agnostic: knows nothing about FIX, OUCH, etc.
/// The owning Session sets the callbacks and drives the lifecycle.
///
/// All async operations run on the io_context provided at construction.
/// Thread safety is guaranteed by the internal strand — callers may invoke
/// connect / disconnect / send from any thread.
class TcpConnection {
public:
    enum class State { Disconnected, Connecting, Connected };

    // ---- Callbacks (set by owning Session before connect) ----------------
    std::function<void()>                    onConnected;
    std::function<void()>                    onDisconnected;
    std::function<void(const char*, std::size_t)>  onData;
    std::function<void(std::error_code)>     onError;

    /// @param io  The io_context owned by the parent Session.
    explicit TcpConnection(asio::io_context& io);
    ~TcpConnection();

    // Non-copyable, non-movable (socket + strand are tied to io_context)
    TcpConnection(const TcpConnection&) = delete;
    TcpConnection& operator=(const TcpConnection&) = delete;

    // ---- Lifecycle -------------------------------------------------------
    /// Asynchronously resolve host:port and connect.
    void connect(const std::string& host, std::uint16_t port);

    /// Graceful shutdown: cancel pending ops, close socket.
    void disconnect();

    // ---- Sending ---------------------------------------------------------
    /// Queue data for async write.  Thread-safe (strand-dispatched).
    void send(std::vector<char> data);

    // ---- Accessors -------------------------------------------------------
    State state() const { return state_; }

private:
    void startRead();
    void doWrite();

    asio::io_context&                  io_;
    asio::io_context::strand           strand_;
    asio::ip::tcp::resolver            resolver_;
    asio::ip::tcp::socket              socket_;

    State state_ = State::Disconnected;

    // Read buffer — 8 KB is enough for a single FIX/OUCH message frame
    static constexpr std::size_t kReadBufSize = 8192;
    std::array<char, kReadBufSize> readBuf_;

    // Outgoing write queue (strand-serialized, no external lock needed)
    std::deque<std::vector<char>> writeQueue_;
    bool writing_ = false;
};

} // namespace marx
