#include "protocol/ouch/OuchEncoder.h"
#include <cstring>

namespace marx::ouch {

// Helper to write primitive types to buffer
template<typename T>
void writeBinary(std::vector<char>& buf, T val) {
    const char* ptr = reinterpret_cast<const char*>(&val);
    buf.insert(buf.end(), ptr, ptr + sizeof(T));
}

// Helper to write fixed-width strings to buffer
void writeString(std::vector<char>& buf, const std::string& str, std::size_t len) {
    std::string copy = str;
    copy.resize(len, ' '); // pad with spaces
    buf.insert(buf.end(), copy.begin(), copy.end());
}

// ---------------------------------------------------------------------------
// encode EnterOrder
// ---------------------------------------------------------------------------
std::vector<char> OuchEncoder::encode(const OUCH::messages::EnterOrder& msg) {
    std::vector<char> buf;
    buf.push_back('U'); // Message Type

    writeBinary<std::uint32_t>(buf, msg.getUserRefNum().get());
    writeBinary<char>(buf, msg.getSide().get());
    writeBinary<std::uint32_t>(buf, msg.getQuantity().get());
    writeString(buf, msg.getSymbol().toString(), 8);
    writeBinary<double>(buf, msg.getPrice().get());
    writeBinary<char>(buf, msg.getTimeInForce().get());
    writeBinary<char>(buf, msg.getDisplay().get());
    writeBinary<char>(buf, msg.getCapacity().get());
    writeBinary<char>(buf, msg.getIntermarketSweepEligibility().get());
    writeBinary<char>(buf, msg.getCrossType().get());
    writeString(buf, msg.getClOrdID().toString(), 14);
    writeString(buf, msg.getFirm().toString(), 4);
    writeBinary<std::uint32_t>(buf, msg.getMinQty().get());
    writeBinary<std::uint32_t>(buf, msg.getMaxFloor().get());
    writeBinary<std::uint32_t>(buf, msg.getPegOffset().get());
    writeBinary<std::uint32_t>(buf, msg.getExpireTime().get());

    return buf;
}

// ---------------------------------------------------------------------------
// encode ReplaceOrderRequest
// ---------------------------------------------------------------------------
std::vector<char> OuchEncoder::encode(const OUCH::messages::ReplaceOrderRequest& msg) {
    std::vector<char> buf;
    buf.push_back('R'); // Message Type

    writeBinary<std::uint32_t>(buf, msg.getExistingUserRefNum().get());
    writeBinary<std::uint32_t>(buf, msg.getReplacementUserRefNum().get());
    writeBinary<std::uint32_t>(buf, msg.getQuantity().get());
    writeBinary<double>(buf, msg.getPrice().get());
    writeBinary<char>(buf, msg.getTimeInForce().get());
    writeBinary<char>(buf, msg.getDisplay().get());
    writeBinary<char>(buf, msg.getIntermarketSweepEligibility().get());

    return buf;
}

// ---------------------------------------------------------------------------
// encode CancelOrderRequest
// ---------------------------------------------------------------------------
std::vector<char> OuchEncoder::encode(const OUCH::messages::CancelOrderRequest& msg) {
    std::vector<char> buf;
    buf.push_back('X'); // Message Type

    writeBinary<std::uint32_t>(buf, msg.getUserRefNum().get());
    writeBinary<std::uint32_t>(buf, msg.getQuantity().get());

    return buf;
}

// ---------------------------------------------------------------------------
// encode OrderAccepted
// ---------------------------------------------------------------------------
std::vector<char> OuchEncoder::encode(const OUCH::messages::OrderAccepted& msg) {
    std::vector<char> buf;
    buf.push_back('A'); // Message Type

    writeBinary<std::uint64_t>(buf, msg.getTimestamp().get());
    writeBinary<std::uint32_t>(buf, msg.getUserRefNum().get());
    writeBinary<std::uint64_t>(buf, msg.getOrderReferenceNumber().get());
    writeBinary<char>(buf, msg.getSide().get());
    writeString(buf, msg.getSymbol().toString(), 8);
    writeBinary<std::uint32_t>(buf, msg.getQuantity().get());
    writeBinary<double>(buf, msg.getPrice().get());
    writeBinary<char>(buf, msg.getTimeInForce().get());
    writeBinary<char>(buf, msg.getDisplay().get());
    writeBinary<char>(buf, msg.getOrderState().get());
    writeString(buf, msg.getClOrdID().toString(), 14);

    return buf;
}

// ---------------------------------------------------------------------------
// encode OrderReplaced
// ---------------------------------------------------------------------------
std::vector<char> OuchEncoder::encode(const OUCH::messages::OrderReplaced& msg) {
    std::vector<char> buf;
    buf.push_back('r'); // Message Type

    writeBinary<std::uint64_t>(buf, msg.getTimestamp().get());
    writeBinary<std::uint32_t>(buf, msg.getOriginalUserRefNum().get());
    writeBinary<std::uint32_t>(buf, msg.getReplacementUserRefNum().get());
    writeBinary<std::uint64_t>(buf, msg.getOrderReferenceNumber().get());
    writeBinary<std::uint32_t>(buf, msg.getQuantity().get());
    writeBinary<double>(buf, msg.getPrice().get());
    writeBinary<char>(buf, msg.getOrderState().get());

    return buf;
}

// ---------------------------------------------------------------------------
// encode OrderCanceled
// ---------------------------------------------------------------------------
std::vector<char> OuchEncoder::encode(const OUCH::messages::OrderCanceled& msg) {
    std::vector<char> buf;
    buf.push_back('C'); // Message Type

    writeBinary<std::uint64_t>(buf, msg.getTimestamp().get());
    writeBinary<std::uint32_t>(buf, msg.getUserRefNum().get());
    writeBinary<std::uint32_t>(buf, msg.getCanceledQuantity().get());
    writeBinary<std::uint32_t>(buf, msg.getRemainingQuantity().get());
    writeBinary<char>(buf, msg.getReason().get());

    return buf;
}

// ---------------------------------------------------------------------------
// encode OrderExecuted
// ---------------------------------------------------------------------------
std::vector<char> OuchEncoder::encode(const OUCH::messages::OrderExecuted& msg) {
    std::vector<char> buf;
    buf.push_back('E'); // Message Type

    writeBinary<std::uint64_t>(buf, msg.getTimestamp().get());
    writeBinary<std::uint32_t>(buf, msg.getUserRefNum().get());
    writeBinary<std::uint32_t>(buf, msg.getExecutedQuantity().get());
    writeBinary<double>(buf, msg.getPrice().get());
    writeBinary<char>(buf, msg.getLiquidityFlag().get());
    writeBinary<std::uint64_t>(buf, msg.getMatchNumber().get());

    return buf;
}

// ---------------------------------------------------------------------------
// encode Rejected
// ---------------------------------------------------------------------------
std::vector<char> OuchEncoder::encode(const OUCH::messages::Rejected& msg) {
    std::vector<char> buf;
    buf.push_back('J'); // Message Type

    writeBinary<std::uint64_t>(buf, msg.getTimestamp().get());
    writeBinary<std::uint32_t>(buf, msg.getUserRefNum().get());
    writeBinary<char>(buf, msg.getReason().get());
    writeString(buf, msg.getClOrdID().toString(), 14);

    return buf;
}

} // namespace marx::ouch
