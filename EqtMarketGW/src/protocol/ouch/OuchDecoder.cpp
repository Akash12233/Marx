#include "protocol/ouch/OuchDecoder.h"
#include <cstring>
#include <iostream>

namespace marx::ouch {

// Helper to read primitive types from contiguous binary stream
template<typename T>
T readBinary(const char*& ptr) {
    T val;
    std::memcpy(&val, ptr, sizeof(T));
    ptr += sizeof(T);
    return val;
}

// Helper to read fixed-width strings
std::string readString(const char*& ptr, std::size_t len) {
    std::string str(ptr, len);
    ptr += len;
    return str;
}

// ---------------------------------------------------------------------------
// onData
// ---------------------------------------------------------------------------
void OuchDecoder::onData(const char* data, std::size_t len) {
    buffer_.insert(buffer_.end(), data, data + len);
    while (tryExtractMessage()) {
        // Continue extracting complete messages
    }
}

// ---------------------------------------------------------------------------
// reset
// ---------------------------------------------------------------------------
void OuchDecoder::reset() {
    buffer_.clear();
}

// ---------------------------------------------------------------------------
// tryExtractMessage
// ---------------------------------------------------------------------------
bool OuchDecoder::tryExtractMessage() {
    if (buffer_.empty()) {
        return false;
    }

    char msgType = buffer_[0];
    std::size_t expectedLen = 0;

    // Get expected binary message size based on message type character
    switch (msgType) {
        case 'U': expectedLen = 65; break; // EnterOrder (Client -> Exchange)
        case 'R': expectedLen = 24; break; // ReplaceOrderRequest (Client -> Exchange)
        case 'X': expectedLen = 9;  break; // CancelOrderRequest (Client -> Exchange)
        case 'A': expectedLen = 59; break; // OrderAccepted (Exchange -> Client)
        case 'r': expectedLen = 38; break; // OrderReplaced (Exchange -> Client)
        case 'C': expectedLen = 22; break; // OrderCanceled (Exchange -> Client)
        case 'E': expectedLen = 34; break; // OrderExecuted (Exchange -> Client)
        case 'J': expectedLen = 28; break; // Rejected (Exchange -> Client)
        default:
            if (onError) onError("Unknown binary OUCH message type: " + std::string(1, msgType));
            // Discard invalid first byte to prevent infinite loop
            buffer_.erase(buffer_.begin());
            return true; 
    }

    if (buffer_.size() < expectedLen) {
        return false; // Need more bytes
    }

    const char* ptr = buffer_.data();
    ptr++; // skip MsgType

    try {
        if (msgType == 'A') { // OrderAccepted
            OUCH::messages::OrderAccepted msg;
            msg.setTimestamp(OUCH::fields::Timestamp(readBinary<std::uint64_t>(ptr)));
            msg.setUserRefNum(OUCH::fields::UserRefNum(readBinary<std::uint32_t>(ptr)));
            msg.setOrderReferenceNumber(OUCH::fields::OrderReferenceNumber(readBinary<std::uint64_t>(ptr)));
            msg.setSide(OUCH::fields::Side(readBinary<char>(ptr)));
            msg.setSymbol(OUCH::fields::Symbol(readString(ptr, 8)));
            msg.setQuantity(OUCH::fields::Quantity(readBinary<std::uint32_t>(ptr)));
            msg.setPrice(OUCH::fields::Price(readBinary<double>(ptr)));
            msg.setTimeInForce(OUCH::fields::TimeInForce(readBinary<char>(ptr)));
            msg.setDisplay(OUCH::fields::Display(readBinary<char>(ptr)));
            msg.setOrderState(OUCH::fields::OrderState(readBinary<char>(ptr)));
            msg.setClOrdID(OUCH::fields::ClOrdID(readString(ptr, 14)));
            
            if (onMessage) onMessage(msg);
        }
        else if (msgType == 'r') { // OrderReplaced
            OUCH::messages::OrderReplaced msg;
            msg.setTimestamp(OUCH::fields::Timestamp(readBinary<std::uint64_t>(ptr)));
            msg.setOriginalUserRefNum(OUCH::fields::OriginalUserRefNum(readBinary<std::uint32_t>(ptr)));
            msg.setReplacementUserRefNum(OUCH::fields::ReplacementUserRefNum(readBinary<std::uint32_t>(ptr)));
            msg.setOrderReferenceNumber(OUCH::fields::OrderReferenceNumber(readBinary<std::uint64_t>(ptr)));
            msg.setQuantity(OUCH::fields::Quantity(readBinary<std::uint32_t>(ptr)));
            msg.setPrice(OUCH::fields::Price(readBinary<double>(ptr)));
            msg.setOrderState(OUCH::fields::OrderState(readBinary<char>(ptr)));
            
            if (onMessage) onMessage(msg);
        }
        else if (msgType == 'C') { // OrderCanceled
            OUCH::messages::OrderCanceled msg;
            msg.setTimestamp(OUCH::fields::Timestamp(readBinary<std::uint64_t>(ptr)));
            msg.setUserRefNum(OUCH::fields::UserRefNum(readBinary<std::uint32_t>(ptr)));
            msg.setCanceledQuantity(OUCH::fields::CanceledQuantity(readBinary<std::uint32_t>(ptr)));
            msg.setRemainingQuantity(OUCH::fields::RemainingQuantity(readBinary<std::uint32_t>(ptr)));
            msg.setReason(OUCH::fields::Reason(readBinary<char>(ptr)));
            
            if (onMessage) onMessage(msg);
        }
        else if (msgType == 'E') { // OrderExecuted
            OUCH::messages::OrderExecuted msg;
            msg.setTimestamp(OUCH::fields::Timestamp(readBinary<std::uint64_t>(ptr)));
            msg.setUserRefNum(OUCH::fields::UserRefNum(readBinary<std::uint32_t>(ptr)));
            msg.setExecutedQuantity(OUCH::fields::ExecutedQuantity(readBinary<std::uint32_t>(ptr)));
            msg.setPrice(OUCH::fields::Price(readBinary<double>(ptr)));
            msg.setLiquidityFlag(OUCH::fields::LiquidityFlag(readBinary<char>(ptr)));
            msg.setMatchNumber(OUCH::fields::MatchNumber(readBinary<std::uint64_t>(ptr)));
            
            if (onMessage) onMessage(msg);
        }
        else if (msgType == 'J') { // Rejected
            OUCH::messages::Rejected msg;
            msg.setTimestamp(OUCH::fields::Timestamp(readBinary<std::uint64_t>(ptr)));
            msg.setUserRefNum(OUCH::fields::UserRefNum(readBinary<std::uint32_t>(ptr)));
            msg.setReason(OUCH::fields::Reason(readBinary<char>(ptr)));
            msg.setClOrdID(OUCH::fields::ClOrdID(readString(ptr, 14)));
            
            if (onMessage) onMessage(msg);
        }
        else if (msgType == 'U') { // EnterOrder (For loopback testing/venue simulator)
            OUCH::messages::EnterOrder msg;
            msg.setUserRefNum(OUCH::fields::UserRefNum(readBinary<std::uint32_t>(ptr)));
            msg.setSide(OUCH::fields::Side(readBinary<char>(ptr)));
            msg.setQuantity(OUCH::fields::Quantity(readBinary<std::uint32_t>(ptr)));
            msg.setSymbol(OUCH::fields::Symbol(readString(ptr, 8)));
            msg.setPrice(OUCH::fields::Price(readBinary<double>(ptr)));
            msg.setTimeInForce(OUCH::fields::TimeInForce(readBinary<char>(ptr)));
            msg.setDisplay(OUCH::fields::Display(readBinary<char>(ptr)));
            msg.setCapacity(OUCH::fields::Capacity(readBinary<char>(ptr)));
            msg.setIntermarketSweepEligibility(OUCH::fields::IntermarketSweepEligibility(readBinary<char>(ptr)));
            msg.setCrossType(OUCH::fields::CrossType(readBinary<char>(ptr)));
            msg.setClOrdID(OUCH::fields::ClOrdID(readString(ptr, 14)));
            msg.setFirm(OUCH::fields::Firm(readString(ptr, 4)));
            msg.setMinQty(OUCH::fields::MinQty(readBinary<std::uint32_t>(ptr)));
            msg.setMaxFloor(OUCH::fields::MaxFloor(readBinary<std::uint32_t>(ptr)));
            msg.setPegOffset(OUCH::fields::PegOffset(readBinary<std::uint32_t>(ptr)));
            msg.setExpireTime(OUCH::fields::ExpireTime(readBinary<std::uint32_t>(ptr)));
            
            if (onMessage) onMessage(msg);
        }
        else if (msgType == 'R') { // ReplaceOrderRequest
            OUCH::messages::ReplaceOrderRequest msg;
            msg.setExistingUserRefNum(OUCH::fields::ExistingUserRefNum(readBinary<std::uint32_t>(ptr)));
            msg.setReplacementUserRefNum(OUCH::fields::ReplacementUserRefNum(readBinary<std::uint32_t>(ptr)));
            msg.setQuantity(OUCH::fields::Quantity(readBinary<std::uint32_t>(ptr)));
            msg.setPrice(OUCH::fields::Price(readBinary<double>(ptr)));
            msg.setTimeInForce(OUCH::fields::TimeInForce(readBinary<char>(ptr)));
            msg.setDisplay(OUCH::fields::Display(readBinary<char>(ptr)));
            msg.setIntermarketSweepEligibility(OUCH::fields::IntermarketSweepEligibility(readBinary<char>(ptr)));
            
            if (onMessage) onMessage(msg);
        }
        else if (msgType == 'X') { // CancelOrderRequest
            OUCH::messages::CancelOrderRequest msg;
            msg.setUserRefNum(OUCH::fields::UserRefNum(readBinary<std::uint32_t>(ptr)));
            msg.setQuantity(OUCH::fields::Quantity(readBinary<std::uint32_t>(ptr)));
            
            if (onMessage) onMessage(msg);
        }
    } 
    catch (const std::exception& e) {
        if (onError) onError("Failed to parse binary message " + std::string(1, msgType) + ": " + e.what());
    }

    // Remove processed message from buffer
    buffer_.erase(buffer_.begin(), buffer_.begin() + expectedLen);
    return true;
}

} // namespace marx::ouch
