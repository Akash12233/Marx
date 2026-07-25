#include "protocol/ouch/OuchConversions.h"
#include <sstream>
#include <iomanip>

namespace marx::ouch::conversions {

static std::string formatMarxId(std::uint32_t userRef) {
    std::ostringstream oss;
    oss << "MARX" << std::setw(6) << std::setfill('0') << userRef;
    return oss.str();
}

// ===========================================================================
// OUCH -> CDM conversions
// ===========================================================================

// 1. EnterOrder -> NewOrderRequest
template<>
MODEL::messages::NewOrderRequest convert<MODEL::messages::NewOrderRequest, OUCH::messages::EnterOrder>(const OUCH::messages::EnterOrder& src) {
    MODEL::messages::NewOrderRequest target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setSymbol(MODEL::fields::Symbol(src.getSymbol().toString()));
    target.setSide(MODEL::fields::Side(src.getSide().get()));
    target.setOrderQty(MODEL::fields::OrderQty(static_cast<int>(src.getQuantity().get())));
    target.setPrice(MODEL::fields::Price(src.getPrice().get()));
    target.setTimeInForce(MODEL::fields::TimeInForce(src.getTimeInForce().get()));
    return target;
}

// 2. OrderAccepted -> CreateOrderExecution
template<>
MODEL::messages::CreateOrderExecution convert<MODEL::messages::CreateOrderExecution, OUCH::messages::OrderAccepted>(const OUCH::messages::OrderAccepted& src) {
    MODEL::messages::CreateOrderExecution target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setVenueOrderId(MODEL::fields::VenueOrderId(std::to_string(src.getOrderReferenceNumber().get())));
    target.setExecutionId(MODEL::fields::ExecutionId(std::to_string(src.getUserRefNum().get())));
    target.setExecutionType(MODEL::fields::ExecutionType('0')); // New
    target.setOrderStatus(MODEL::fields::OrderStatus('0'));     // New
    target.setOrderQty(MODEL::fields::OrderQty(static_cast<int>(src.getQuantity().get())));
    target.setFilledQuantity(MODEL::fields::FilledQuantity(0));
    target.setRemainingQuantity(MODEL::fields::RemainingQuantity(static_cast<int>(src.getQuantity().get())));
    target.setAveragePrice(MODEL::fields::AveragePrice(src.getPrice().get()));
    return target;
}

// 3. Rejected -> CreateOrderReject
template<>
MODEL::messages::CreateOrderReject convert<MODEL::messages::CreateOrderReject, OUCH::messages::Rejected>(const OUCH::messages::Rejected& src) {
    MODEL::messages::CreateOrderReject target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setOrderStatus(MODEL::fields::OrderStatus('8')); // Rejected
    target.setExecutionType(MODEL::fields::ExecutionType('8')); // Rejected
    target.setRejectReason(MODEL::fields::RejectReason("EX: ReasonCode " + std::to_string(static_cast<int>(src.getReason().get()))));
    return target;
}

// 4. OrderExecuted -> FillOrderExecution
template<>
MODEL::messages::FillOrderExecution convert<MODEL::messages::FillOrderExecution, OUCH::messages::OrderExecuted>(const OUCH::messages::OrderExecuted& src) {
    MODEL::messages::FillOrderExecution target;
    // OUCH executions reference UserRefNum, which maps to ClientOrderId/MARXID
    target.setClientOrderId(MODEL::fields::ClientOrderId(formatMarxId(src.getUserRefNum().get())));
    target.setExecutionId(MODEL::fields::ExecutionId(std::to_string(src.getMatchNumber().get())));
    target.setLastFillQuantity(MODEL::fields::LastFillQuantity(static_cast<int>(src.getExecutedQuantity().get())));
    target.setLastFillPrice(MODEL::fields::LastFillPrice(src.getPrice().get()));
    target.setTradeId(MODEL::fields::TradeId(std::to_string(src.getMatchNumber().get())));
    target.setTradeTime(MODEL::fields::TradeTime(static_cast<std::int64_t>(src.getTimestamp().get())));
    // Set execution type and status (filled/partially filled is resolved by store)
    target.setExecutionType(MODEL::fields::ExecutionType('F')); // Fill
    return target;
}

// 5. OrderReplaced -> ReplaceOrderExecution
template<>
MODEL::messages::ReplaceOrderExecution convert<MODEL::messages::ReplaceOrderExecution, OUCH::messages::OrderReplaced>(const OUCH::messages::OrderReplaced& src) {
    MODEL::messages::ReplaceOrderExecution target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(formatMarxId(src.getReplacementUserRefNum().get())));
    target.setVenueOrderId(MODEL::fields::VenueOrderId(std::to_string(src.getOrderReferenceNumber().get())));
    target.setExecutionType(MODEL::fields::ExecutionType('5')); // Replaced
    target.setOrderStatus(MODEL::fields::OrderStatus('5')); // Replaced
    target.setOrderQty(MODEL::fields::OrderQty(static_cast<int>(src.getQuantity().get())));
    target.setAveragePrice(MODEL::fields::AveragePrice(src.getPrice().get()));
    return target;
}

// 6. OrderCanceled -> CancelOrderExecution
template<>
MODEL::messages::CancelOrderExecution convert<MODEL::messages::CancelOrderExecution, OUCH::messages::OrderCanceled>(const OUCH::messages::OrderCanceled& src) {
    MODEL::messages::CancelOrderExecution target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(formatMarxId(src.getUserRefNum().get())));
    target.setExecutionType(MODEL::fields::ExecutionType('4')); // Cancelled
    target.setOrderStatus(MODEL::fields::OrderStatus('4')); // Cancelled
    target.setFilledQuantity(MODEL::fields::FilledQuantity(static_cast<int>(src.getCanceledQuantity().get())));
    target.setRemainingQuantity(MODEL::fields::RemainingQuantity(static_cast<int>(src.getRemainingQuantity().get())));
    return target;
}


// ===========================================================================
// CDM -> OUCH conversions
// ===========================================================================

// 7. NewOrderRequest -> EnterOrder
template<>
OUCH::messages::EnterOrder convert<OUCH::messages::EnterOrder, MODEL::messages::NewOrderRequest>(const MODEL::messages::NewOrderRequest& src) {
    OUCH::messages::EnterOrder target;
    // For OUCH, the unique key on wire is UserRefNum. We can parse numeric MARXID or use hash/std::stoul
    std::string clOrdId = src.getClientOrderId().toString();
    std::uint32_t userRef = 0;
    if (clOrdId.size() > 4 && clOrdId.substr(0, 4) == "MARX") {
        try {
            userRef = static_cast<std::uint32_t>(std::stoul(clOrdId.substr(4)));
        } catch (...) {
            userRef = std::hash<std::string>{}(clOrdId);
        }
    } else {
        userRef = std::hash<std::string>{}(clOrdId);
    }
    
    target.setUserRefNum(OUCH::fields::UserRefNum(userRef));
    target.setSide(OUCH::fields::Side(src.getSide().get()));
    target.setQuantity(OUCH::fields::Quantity(src.getOrderQty().get()));
    target.setSymbol(OUCH::fields::Symbol(src.getSymbol().toString()));
    target.setPrice(OUCH::fields::Price(src.getPrice().get()));
    target.setTimeInForce(OUCH::fields::TimeInForce(src.getTimeInForce().get()));
    target.setClOrdID(OUCH::fields::ClOrdID(src.getClientOrderId().toString()));
    
    // Set typical OUCH defaults
    target.setDisplay(OUCH::fields::Display('Y'));
    target.setCapacity(OUCH::fields::Capacity('A')); // Agency
    target.setIntermarketSweepEligibility(OUCH::fields::IntermarketSweepEligibility('N'));
    target.setCrossType(OUCH::fields::CrossType('N'));
    target.setFirm(OUCH::fields::Firm(""));
    return target;
}

// 8. ReplaceOrderRequest -> ReplaceOrderRequest
template<>
OUCH::messages::ReplaceOrderRequest convert<OUCH::messages::ReplaceOrderRequest, MODEL::messages::ReplaceOrderRequest>(const MODEL::messages::ReplaceOrderRequest& src) {
    OUCH::messages::ReplaceOrderRequest target;
    
    std::string clOrdId = src.getClientOrderId().toString();
    std::string origClOrdId = src.getOriginalClientOrderId().toString();
    std::uint32_t parentRef = 0;
    std::uint32_t childRef = 0;
    
    try {
        if (origClOrdId.size() > 4 && origClOrdId.substr(0, 4) == "MARX") {
            parentRef = static_cast<std::uint32_t>(std::stoul(origClOrdId.substr(4)));
        } else {
            parentRef = std::hash<std::string>{}(origClOrdId);
        }
        if (clOrdId.size() > 4 && clOrdId.substr(0, 4) == "MARX") {
            childRef = static_cast<std::uint32_t>(std::stoul(clOrdId.substr(4)));
        } else {
            childRef = std::hash<std::string>{}(clOrdId);
        }
    } catch (...) {
        parentRef = std::hash<std::string>{}(origClOrdId);
        childRef = std::hash<std::string>{}(clOrdId);
    }
    
    target.setExistingUserRefNum(OUCH::fields::ExistingUserRefNum(parentRef));
    target.setReplacementUserRefNum(OUCH::fields::ReplacementUserRefNum(childRef));
    target.setQuantity(OUCH::fields::Quantity(src.getOrderQty().get()));
    target.setPrice(OUCH::fields::Price(src.getPrice().get()));
    target.setTimeInForce(OUCH::fields::TimeInForce(src.getTimeInForce().get()));
    target.setDisplay(OUCH::fields::Display('Y'));
    target.setIntermarketSweepEligibility(OUCH::fields::IntermarketSweepEligibility('N'));
    return target;
}

// 9. CancelOrderRequest -> CancelOrderRequest
template<>
OUCH::messages::CancelOrderRequest convert<OUCH::messages::CancelOrderRequest, MODEL::messages::CancelOrderRequest>(const MODEL::messages::CancelOrderRequest& src) {
    OUCH::messages::CancelOrderRequest target;
    
    std::string origClOrdId = src.getOriginalClientOrderId().toString();
    std::uint32_t parentRef = 0;
    
    try {
        if (origClOrdId.size() > 4 && origClOrdId.substr(0, 4) == "MARX") {
            parentRef = static_cast<std::uint32_t>(std::stoul(origClOrdId.substr(4)));
        } else {
            parentRef = std::hash<std::string>{}(origClOrdId);
        }
    } catch (...) {
        parentRef = std::hash<std::string>{}(origClOrdId);
    }
    
    target.setUserRefNum(OUCH::fields::UserRefNum(parentRef));
    target.setQuantity(OUCH::fields::Quantity(0)); // 0 means cancel full quantity in OUCH
    return target;
}

// 10. OUCH CancelOrderRequest -> MODEL CancelOrderRequest
template<>
MODEL::messages::CancelOrderRequest convert<MODEL::messages::CancelOrderRequest, OUCH::messages::CancelOrderRequest>(const OUCH::messages::CancelOrderRequest& src) {
    MODEL::messages::CancelOrderRequest target;
    target.setOriginalClientOrderId(MODEL::fields::OriginalClientOrderId(std::to_string(src.getUserRefNum().get())));
    return target;
}

// 11. OUCH ReplaceOrderRequest -> MODEL ReplaceOrderRequest
template<>
MODEL::messages::ReplaceOrderRequest convert<MODEL::messages::ReplaceOrderRequest, OUCH::messages::ReplaceOrderRequest>(const OUCH::messages::ReplaceOrderRequest& src) {
    MODEL::messages::ReplaceOrderRequest target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(std::to_string(src.getReplacementUserRefNum().get())));
    target.setOriginalClientOrderId(MODEL::fields::OriginalClientOrderId(std::to_string(src.getExistingUserRefNum().get())));
    target.setOrderQty(MODEL::fields::OrderQty(src.getQuantity().get()));
    target.setPrice(MODEL::fields::Price(src.getPrice().get()));
    target.setTimeInForce(MODEL::fields::TimeInForce(src.getTimeInForce().get()));
    return target;
}

} // namespace marx::ouch::conversions
