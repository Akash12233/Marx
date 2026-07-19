#include "abstract/TcpConnection.h"

#include <iostream>

namespace marx {

TcpConnection::TcpConnection(asio::io_context& io)
    : io_(io)
    , strand_(io)
    , resolver_(io)
    , socket_(io)
{
}

TcpConnection::~TcpConnection()
{
    disconnect();
}

// ---------------------------------------------------------------------------
// connect
// ---------------------------------------------------------------------------
void TcpConnection::connect(const std::string& host, std::uint16_t port)
{
    if (state_ != State::Disconnected) {
        return;  // already connecting or connected
    }

    state_ = State::Connecting;

    resolver_.async_resolve(
        host, std::to_string(port),
        asio::bind_executor(strand_,
            [this](std::error_code ec,
                   asio::ip::tcp::resolver::results_type results)
            {
                if (ec) {
                    state_ = State::Disconnected;
                    if (onError) onError(ec);
                    return;
                }

                asio::async_connect(
                    socket_, results,
                    asio::bind_executor(strand_,
                        [this](std::error_code ec,
                               const asio::ip::tcp::endpoint& /*ep*/)
                        {
                            if (ec) {
                                state_ = State::Disconnected;
                                if (onError) onError(ec);
                                return;
                            }

                            state_ = State::Connected;

                            // Disable Nagle for low-latency sends
                            std::error_code ignore;
                            socket_.set_option(
                                asio::ip::tcp::no_delay(true), ignore);

                            if (onConnected) onConnected();

                            startRead();
                        }));
            }));
}

// ---------------------------------------------------------------------------
// disconnect
// ---------------------------------------------------------------------------
void TcpConnection::disconnect()
{
    if (state_ == State::Disconnected) {
        return;
    }

    asio::post(strand_, [this]() {
        std::error_code ec;
        socket_.shutdown(asio::ip::tcp::socket::shutdown_both, ec);
        socket_.close(ec);

        state_ = State::Disconnected;
        writeQueue_.clear();
        writing_ = false;

        if (onDisconnected) onDisconnected();
    });
}

// ---------------------------------------------------------------------------
// send
// ---------------------------------------------------------------------------
void TcpConnection::send(std::vector<char> data)
{
    asio::post(strand_, [this, d = std::move(data)]() mutable {
        writeQueue_.push_back(std::move(d));
        if (!writing_) {
            doWrite();
        }
    });
}

// ---------------------------------------------------------------------------
// startRead  (internal — runs on strand)
// ---------------------------------------------------------------------------
void TcpConnection::startRead()
{
    socket_.async_read_some(
        asio::buffer(readBuf_),
        asio::bind_executor(strand_,
            [this](std::error_code ec, std::size_t bytesRead)
            {
                if (ec) {
                    if (ec == asio::error::eof ||
                        ec == asio::error::connection_reset ||
                        ec == asio::error::operation_aborted)
                    {
                        // Normal disconnect path
                        state_ = State::Disconnected;
                        if (onDisconnected) onDisconnected();
                    } else {
                        if (onError) onError(ec);
                    }
                    return;
                }

                if (onData) {
                    onData(readBuf_.data(), bytesRead);
                }

                // Continue reading
                startRead();
            }));
}

// ---------------------------------------------------------------------------
// doWrite  (internal — runs on strand, processes queue)
// ---------------------------------------------------------------------------
void TcpConnection::doWrite()
{
    if (writeQueue_.empty()) {
        writing_ = false;
        return;
    }

    writing_ = true;
    auto& front = writeQueue_.front();

    asio::async_write(
        socket_,
        asio::buffer(front),
        asio::bind_executor(strand_,
            [this](std::error_code ec, std::size_t /*bytesWritten*/)
            {
                if (ec) {
                    writing_ = false;
                    if (onError) onError(ec);
                    return;
                }

                writeQueue_.pop_front();
                doWrite();  // process next queued message
            }));
}

} // namespace marx
