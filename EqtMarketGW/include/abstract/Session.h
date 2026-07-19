#pragma once

#include "abstract/ConnectionState.h"
#include "abstract/SessionContext.h"
#include "abstract/Statistics.h"
#include "abstract/TcpConnection.h"

#include <asio.hpp>

#include <memory>
#include <thread>
#include <vector>

namespace MODEL::messages {
class NewOrderRequest;
class ReplaceOrderRequest;
class CancelOrderRequest;
class CreateOrderExecution;
class CreateOrderReject;
class ReplaceOrderExecution;
class ReplaceOrderReject;
class CancelOrderExecution;
class CancelOrderReject;
class FillOrderExecution;
}

namespace marx {

/// Abstract base class for all sessions (client and venue, any protocol).
///
/// Owns:
///   - SessionContext (config)
///   - TcpConnection  (composed — async TCP I/O)
///   - io_context + thread (one event loop per session)
///   - Statistics (message / byte counters)
///   - ConnectionState tracking
///
/// Does NOT own:
///   - Protocol encode / decode (derived classes handle this)
///   - Logon / heartbeat logic (protocol-specific)
///
/// Lifecycle:
///   Construction → start() → [Connected → Active → ...] → stop() → Destruction
class Session {
public:
    explicit Session(SessionContext ctx);
    virtual ~Session();

    // Non-copyable, non-movable
    Session(const Session&) = delete;
    Session& operator=(const Session&) = delete;

    // ---- Lifecycle -------------------------------------------------------

    /// Start the session: spin up the io_context thread and initiate
    /// the TCP connection.  Non-blocking.
    void start();

    /// Graceful shutdown: disconnect, drain I/O, join thread.
    void stop();

    // ---- Sending ---------------------------------------------------------

    /// Enqueue raw bytes for async write.  Thread-safe.
    /// Called by the protocol layer after encoding a message.
    void send(std::vector<char> data);

    // ---- CDM Routing Interface (Polymorphic dispatch) --------------------
    virtual void routeCDM(const MODEL::messages::NewOrderRequest&) {}
    virtual void routeCDM(const MODEL::messages::ReplaceOrderRequest&) {}
    virtual void routeCDM(const MODEL::messages::CancelOrderRequest&) {}
    virtual void routeCDM(const MODEL::messages::CreateOrderExecution&) {}
    virtual void routeCDM(const MODEL::messages::CreateOrderReject&) {}
    virtual void routeCDM(const MODEL::messages::ReplaceOrderExecution&) {}
    virtual void routeCDM(const MODEL::messages::ReplaceOrderReject&) {}
    virtual void routeCDM(const MODEL::messages::CancelOrderExecution&) {}
    virtual void routeCDM(const MODEL::messages::CancelOrderReject&) {}
    virtual void routeCDM(const MODEL::messages::FillOrderExecution&) {}

    // ---- Accessors -------------------------------------------------------

    const SessionContext& context() const { return ctx_; }
    ConnectionState       state()   const { return state_; }
    const Statistics&     stats()   const { return stats_; }

    /// Returns the session's io_context (protocol components may need it
    /// for timers, e.g. HeartbeatManager).
    asio::io_context& ioContext() { return io_; }

protected:
    // ---- Hooks for derived classes ---------------------------------------

    /// Called when TCP connection is established.
    /// ClientSession: initiates logon.  VenueSession: waits for logon.
    virtual void onConnected() = 0;

    /// Called when TCP connection drops.
    /// ClientSession: may schedule reconnect.  VenueSession: cleanup.
    virtual void onDisconnected() = 0;

    /// Called with raw bytes received from the wire.
    /// The protocol layer (FixClientSession, etc.) decodes them here.
    virtual void onData(const char* data, std::size_t len) = 0;

    /// Transition the session state (callable by derived classes,
    /// e.g. to move from Connected → Active after logon).
    void setState(ConnectionState newState);

    // ---- Members accessible to derived classes ---------------------------
    SessionContext       ctx_;
    asio::io_context     io_;
    TcpConnection        connection_;
    Statistics           stats_;

private:
    ConnectionState      state_ = ConnectionState::Disconnected;
    std::thread          ioThread_;

    // Guard to keep io_context::run() alive even when there's no pending work
    asio::executor_work_guard<asio::io_context::executor_type> workGuard_;
};

} // namespace marx
