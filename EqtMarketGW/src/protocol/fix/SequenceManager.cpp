#include "protocol/fix/SequenceManager.h"

namespace marx::fix {

// ---------------------------------------------------------------------------
// validate
// ---------------------------------------------------------------------------
SequenceManager::ValidationResult SequenceManager::validate(std::uint32_t receivedSeq) const
{
    if (receivedSeq == incomingSeq_) {
        return ValidationResult::Ok;
    }
    if (receivedSeq > incomingSeq_) {
        return ValidationResult::TooHigh;  // gap — ResendRequest needed
    }
    return ValidationResult::TooLow;  // duplicate — check PossDupFlag
}

// ---------------------------------------------------------------------------
// advanceIncoming
// ---------------------------------------------------------------------------
void SequenceManager::advanceIncoming()
{
    ++incomingSeq_;
}

// ---------------------------------------------------------------------------
// setIncoming
// ---------------------------------------------------------------------------
void SequenceManager::setIncoming(std::uint32_t seq)
{
    incomingSeq_ = seq;
}

// ---------------------------------------------------------------------------
// next
// ---------------------------------------------------------------------------
std::uint32_t SequenceManager::next()
{
    return outgoingSeq_++;
}

// ---------------------------------------------------------------------------
// setOutgoing
// ---------------------------------------------------------------------------
void SequenceManager::setOutgoing(std::uint32_t seq)
{
    outgoingSeq_ = seq;
}

// ---------------------------------------------------------------------------
// reset
// ---------------------------------------------------------------------------
void SequenceManager::reset()
{
    incomingSeq_ = 1;
    outgoingSeq_ = 1;
}

} // namespace marx::fix
