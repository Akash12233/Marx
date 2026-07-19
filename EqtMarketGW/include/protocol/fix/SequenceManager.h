#pragma once

#include <cstdint>

namespace marx::fix {

/// Manages FIX session-level sequence numbers.
///
/// Tracks incoming (expected from counterparty) and outgoing (next to send)
/// sequence numbers. Detects gaps and supports reset.
class SequenceManager {
public:
    SequenceManager() = default;

    // ---- Incoming --------------------------------------------------------

    /// Validate a received MsgSeqNum.
    /// Returns true if it matches expected.  Returns false on gap
    /// (caller should trigger ResendRequest) or if too low (PossDup).
    enum class ValidationResult {
        Ok,          ///< Matches expected
        TooHigh,     ///< Gap detected — need ResendRequest
        TooLow       ///< Already seen — check PossDupFlag
    };

    ValidationResult validate(std::uint32_t receivedSeq) const;

    /// Advance the incoming sequence to the next expected value.
    /// Call this after successfully processing a message.
    void advanceIncoming();

    /// Force-set the incoming sequence (used by SequenceReset-GapFill).
    void setIncoming(std::uint32_t seq);

    std::uint32_t incoming() const { return incomingSeq_; }

    // ---- Outgoing --------------------------------------------------------

    /// Get the next outgoing sequence number and advance.
    std::uint32_t next();

    /// Peek at the next outgoing sequence without advancing.
    std::uint32_t peekNext() const { return outgoingSeq_; }

    /// Force-set the outgoing sequence (used during SequenceReset).
    void setOutgoing(std::uint32_t seq);

    // ---- Reset -----------------------------------------------------------

    /// Reset both sequences to 1 (used on ResetSeqNumFlag logon).
    void reset();

private:
    std::uint32_t incomingSeq_ = 1;  ///< Next expected incoming MsgSeqNum
    std::uint32_t outgoingSeq_ = 1;  ///< Next outgoing MsgSeqNum
};

} // namespace marx::fix
