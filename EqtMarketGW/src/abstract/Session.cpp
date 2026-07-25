#include "abstract/Session.h"
#include "abstract/Logger.h"
#include <sstream>
#include <iomanip>


#include <iostream>

namespace marx {

Session::Session(SessionContext ctx)
    : ctx_(std::move(ctx))
    , connection_(io_)
    , workGuard_(asio::make_work_guard(io_))
{
    // Wire TcpConnection callbacks to our virtual hooks
    connection_.onConnected = [this]() {
        setState(ConnectionState::Connected);
        onConnected();
    };

    connection_.onDisconnected = [this]() {
        setState(ConnectionState::Disconnected);
        onDisconnected();
    };

    connection_.onData = [this](const char* data, std::size_t len) {
        stats_.recordReceive(len);
        
        std::string rawStr(data, len);
        std::string readable;
        for (char c : rawStr) {
            if (c == '\x01') readable += '|';
            else if (c == '\0') readable += ' ';
            else if (c < 32 || c > 126) {
                std::stringstream ss;
                ss << "\\x" << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)c;
                readable += ss.str();
            }
            else readable += c;
        }
        
        if (ctx_.isVenue) {
            Logger::instance().logVenue("IN", ctx_.sessionId, readable);
        } else {
            Logger::instance().logClient("IN", ctx_.sessionId, readable);
        }

        onData(data, len);
    };

    connection_.onError = [this](std::error_code ec) {
        std::cerr << "[" << ctx_.sessionId << "] connection error: "
                  << ec.message() << "\n";
        if (state_ == ConnectionState::Connecting || state_ == ConnectionState::Connected) {
            setState(ConnectionState::Disconnected);
            onDisconnected();
        }
    };
}

Session::~Session()
{
    stop();
}

// ---------------------------------------------------------------------------
// start
// ---------------------------------------------------------------------------
void Session::start()
{
    if (state_ != ConnectionState::Disconnected) {
        return;  // already running
    }

    // Start the I/O thread
    ioThread_ = std::thread([this]() {
        io_.run();
    });

    // Initiate TCP connect
    setState(ConnectionState::Connecting);
    connection_.connect(ctx_.host, ctx_.port);
}

// ---------------------------------------------------------------------------
// stop
// ---------------------------------------------------------------------------
void Session::stop()
{
    if (state_ == ConnectionState::Disconnected && !ioThread_.joinable()) {
        return;
    }

    setState(ConnectionState::Disconnecting);
    connection_.disconnect();

    // Release the work guard so io_context::run() can return
    workGuard_.reset();
    io_.stop();

    if (ioThread_.joinable()) {
        ioThread_.join();
    }

    setState(ConnectionState::Disconnected);
}

// ---------------------------------------------------------------------------
// send
// ---------------------------------------------------------------------------
void Session::send(std::vector<char> data)
{
    stats_.recordSend(data.size());
    
    std::string rawStr(data.begin(), data.end());
    std::string readable;
    for (char c : rawStr) {
        if (c == '\x01') readable += '|';
        else if (c == '\0') readable += ' ';
        else if (c < 32 || c > 126) {
            std::stringstream ss;
            ss << "\\x" << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)c;
            readable += ss.str();
        }
        else readable += c;
    }
    
    if (ctx_.isVenue) {
        Logger::instance().logVenue("OUT", ctx_.sessionId, readable);
    } else {
        Logger::instance().logClient("OUT", ctx_.sessionId, readable);
    }

    connection_.send(std::move(data));
}

// ---------------------------------------------------------------------------
// setState
// ---------------------------------------------------------------------------
void Session::setState(ConnectionState newState)
{
    state_ = newState;
}

} // namespace marx
