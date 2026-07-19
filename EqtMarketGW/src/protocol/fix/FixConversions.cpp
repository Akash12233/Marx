#include "protocol/fix/FixConversions.h"

namespace marx::fix::conversions {

// ===========================================================================
// FIX -> CDM conversions
// ===========================================================================

// 1. NewOrderSingle -> NewOrderRequest
template<>
MODEL::messages::NewOrderRequest convert<MODEL::messages::NewOrderRequest, FIX::messages::NewOrderSingle>(const FIX::messages::NewOrderSingle& src) {
    MODEL::messages::NewOrderRequest target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setAccount(MODEL::fields::Account(src.getAccount().toString()));
    target.setSymbol(MODEL::fields::Symbol(src.getSymbol().toString()));
    target.setSide(MODEL::fields::Side(src.getSide().get()));
    target.setOrderType(MODEL::fields::OrderType(src.getOrdType().get()));
    target.setOrderQty(MODEL::fields::OrderQty(static_cast<int>(src.getOrderQty().get())));
    target.setTimeInForce(MODEL::fields::TimeInForce(src.getTimeInForce().get()));
    target.setTransactTime(MODEL::fields::TransactTime(src.getTransactTime().get()));
    target.setPrice(MODEL::fields::Price(src.getPrice().get()));
    target.setStopPrice(MODEL::fields::StopPrice(src.getStopPx().get()));
    target.setCurrency(MODEL::fields::Currency(src.getCurrency().toString()));
    target.setExecutionInstruction(MODEL::fields::ExecutionInstruction(src.getExecInst().get()));
    return target;
}

// 2. ExecutionReport -> CreateOrderExecution
template<>
MODEL::messages::CreateOrderExecution convert<MODEL::messages::CreateOrderExecution, FIX::messages::ExecutionReport>(const FIX::messages::ExecutionReport& src) {
    MODEL::messages::CreateOrderExecution target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setVenueOrderId(MODEL::fields::VenueOrderId(src.getOrderID().toString()));
    target.setExecutionId(MODEL::fields::ExecutionId(src.getExecID().toString()));
    target.setExecutionType(MODEL::fields::ExecutionType(src.getExecType().get()));
    target.setOrderStatus(MODEL::fields::OrderStatus(src.getOrdStatus().get()));
    target.setOrderQty(MODEL::fields::OrderQty(static_cast<int>(src.getOrderQty().get())));
    target.setFilledQuantity(MODEL::fields::FilledQuantity(static_cast<int>(src.getCumQty().get())));
    target.setRemainingQuantity(MODEL::fields::RemainingQuantity(static_cast<int>(src.getLeavesQty().get())));
    target.setAveragePrice(MODEL::fields::AveragePrice(src.getAvgPx().get()));
    target.setText(MODEL::fields::Text(src.getText().toString()));
    target.setRejectReason(MODEL::fields::RejectReason(src.getOrdRejReason().toString()));
    return target;
}

// 3. ExecutionReport -> CreateOrderReject
template<>
MODEL::messages::CreateOrderReject convert<MODEL::messages::CreateOrderReject, FIX::messages::ExecutionReport>(const FIX::messages::ExecutionReport& src) {
    MODEL::messages::CreateOrderReject target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setVenueOrderId(MODEL::fields::VenueOrderId(src.getOrderID().toString()));
    target.setExecutionId(MODEL::fields::ExecutionId(src.getExecID().toString()));
    target.setExecutionType(MODEL::fields::ExecutionType(src.getExecType().get()));
    target.setOrderStatus(MODEL::fields::OrderStatus(src.getOrdStatus().get()));
    target.setOrderQty(MODEL::fields::OrderQty(static_cast<int>(src.getOrderQty().get())));
    target.setFilledQuantity(MODEL::fields::FilledQuantity(static_cast<int>(src.getCumQty().get())));
    target.setRemainingQuantity(MODEL::fields::RemainingQuantity(static_cast<int>(src.getLeavesQty().get())));
    target.setAveragePrice(MODEL::fields::AveragePrice(src.getAvgPx().get()));
    target.setText(MODEL::fields::Text(src.getText().toString()));
    target.setRejectReason(MODEL::fields::RejectReason(src.getOrdRejReason().toString()));
    return target;
}

// 4. ExecutionReport -> FillOrderExecution
template<>
MODEL::messages::FillOrderExecution convert<MODEL::messages::FillOrderExecution, FIX::messages::ExecutionReport>(const FIX::messages::ExecutionReport& src) {
    MODEL::messages::FillOrderExecution target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setVenueOrderId(MODEL::fields::VenueOrderId(src.getOrderID().toString()));
    target.setExecutionId(MODEL::fields::ExecutionId(src.getExecID().toString()));
    target.setExecutionType(MODEL::fields::ExecutionType(src.getExecType().get()));
    target.setOrderStatus(MODEL::fields::OrderStatus(src.getOrdStatus().get()));
    target.setLastFillQuantity(MODEL::fields::LastFillQuantity(static_cast<int>(src.getLastQty().get())));
    target.setLastFillPrice(MODEL::fields::LastFillPrice(src.getLastPx().get()));
    target.setCumQty(MODEL::fields::CumQty(static_cast<int>(src.getCumQty().get())));
    target.setLeavesQty(MODEL::fields::LeavesQty(static_cast<int>(src.getLeavesQty().get())));
    target.setAveragePrice(MODEL::fields::AveragePrice(src.getAvgPx().get()));
    target.setTradeId(MODEL::fields::TradeId(src.getExecID().toString()));
    target.setTradeTime(MODEL::fields::TradeTime(src.getTransactTime().get()));
    return target;
}

// 5. ExecutionReport -> ReplaceOrderExecution
template<>
MODEL::messages::ReplaceOrderExecution convert<MODEL::messages::ReplaceOrderExecution, FIX::messages::ExecutionReport>(const FIX::messages::ExecutionReport& src) {
    MODEL::messages::ReplaceOrderExecution target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setVenueOrderId(MODEL::fields::VenueOrderId(src.getOrderID().toString()));
    target.setExecutionId(MODEL::fields::ExecutionId(src.getExecID().toString()));
    target.setExecutionType(MODEL::fields::ExecutionType(src.getExecType().get()));
    target.setOrderStatus(MODEL::fields::OrderStatus(src.getOrdStatus().get()));
    target.setOrderQty(MODEL::fields::OrderQty(static_cast<int>(src.getOrderQty().get())));
    target.setFilledQuantity(MODEL::fields::FilledQuantity(static_cast<int>(src.getCumQty().get())));
    target.setRemainingQuantity(MODEL::fields::RemainingQuantity(static_cast<int>(src.getLeavesQty().get())));
    target.setAveragePrice(MODEL::fields::AveragePrice(src.getAvgPx().get()));
    target.setRejectReason(MODEL::fields::RejectReason(src.getOrdRejReason().toString()));
    return target;
}

// 6. ExecutionReport -> CancelOrderExecution
template<>
MODEL::messages::CancelOrderExecution convert<MODEL::messages::CancelOrderExecution, FIX::messages::ExecutionReport>(const FIX::messages::ExecutionReport& src) {
    MODEL::messages::CancelOrderExecution target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setVenueOrderId(MODEL::fields::VenueOrderId(src.getOrderID().toString()));
    target.setExecutionId(MODEL::fields::ExecutionId(src.getExecID().toString()));
    target.setExecutionType(MODEL::fields::ExecutionType(src.getExecType().get()));
    target.setOrderStatus(MODEL::fields::OrderStatus(src.getOrdStatus().get()));
    target.setFilledQuantity(MODEL::fields::FilledQuantity(static_cast<int>(src.getCumQty().get())));
    target.setRemainingQuantity(MODEL::fields::RemainingQuantity(static_cast<int>(src.getLeavesQty().get())));
    target.setAveragePrice(MODEL::fields::AveragePrice(src.getAvgPx().get()));
    target.setRejectReason(MODEL::fields::RejectReason(src.getOrdRejReason().toString()));
    return target;
}

// 7. OrderCancelRequest -> CancelOrderRequest
template<>
MODEL::messages::CancelOrderRequest convert<MODEL::messages::CancelOrderRequest, FIX::messages::OrderCancelRequest>(const FIX::messages::OrderCancelRequest& src) {
    MODEL::messages::CancelOrderRequest target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setOriginalClientOrderId(MODEL::fields::OriginalClientOrderId(src.getOrigClOrdID().toString()));
    target.setSymbol(MODEL::fields::Symbol(src.getSymbol().toString()));
    target.setSide(MODEL::fields::Side(src.getSide().get()));
    return target;
}

// 8. OrderCancelReplaceRequest -> ReplaceOrderRequest
template<>
MODEL::messages::ReplaceOrderRequest convert<MODEL::messages::ReplaceOrderRequest, FIX::messages::OrderCancelReplaceRequest>(const FIX::messages::OrderCancelReplaceRequest& src) {
    MODEL::messages::ReplaceOrderRequest target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setOriginalClientOrderId(MODEL::fields::OriginalClientOrderId(src.getOrigClOrdID().toString()));
    target.setOrderQty(MODEL::fields::OrderQty(static_cast<int>(src.getOrderQty().get())));
    target.setPrice(MODEL::fields::Price(src.getPrice().get()));
    target.setStopPrice(MODEL::fields::StopPrice(src.getStopPx().get()));
    target.setTimeInForce(MODEL::fields::TimeInForce(src.getTimeInForce().get()));
    return target;
}

// 9. OrderCancelReject -> CancelOrderReject
template<>
MODEL::messages::CancelOrderReject convert<MODEL::messages::CancelOrderReject, FIX::messages::OrderCancelReject>(const FIX::messages::OrderCancelReject& src) {
    MODEL::messages::CancelOrderReject target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setVenueOrderId(MODEL::fields::VenueOrderId(src.getOrderID().toString()));
    target.setOrderStatus(MODEL::fields::OrderStatus(src.getOrdStatus().get()));
    target.setRejectReason(MODEL::fields::RejectReason(src.getText().toString()));
    return target;
}

// 10. OrderCancelReject -> ReplaceOrderReject
template<>
MODEL::messages::ReplaceOrderReject convert<MODEL::messages::ReplaceOrderReject, FIX::messages::OrderCancelReject>(const FIX::messages::OrderCancelReject& src) {
    MODEL::messages::ReplaceOrderReject target;
    target.setClientOrderId(MODEL::fields::ClientOrderId(src.getClOrdID().toString()));
    target.setVenueOrderId(MODEL::fields::VenueOrderId(src.getOrderID().toString()));
    target.setOrderStatus(MODEL::fields::OrderStatus(src.getOrdStatus().get()));
    target.setRejectReason(MODEL::fields::RejectReason(src.getText().toString()));
    return target;
}


// ===========================================================================
// CDM -> FIX conversions
// ===========================================================================

// 11. NewOrderRequest -> NewOrderSingle
template<>
FIX::messages::NewOrderSingle convert<FIX::messages::NewOrderSingle, MODEL::messages::NewOrderRequest>(const MODEL::messages::NewOrderRequest& src) {
    FIX::messages::NewOrderSingle target;
    target.setClOrdID(FIX::fields::ClOrdID(src.getClientOrderId().toString()));
    target.setAccount(FIX::fields::Account(src.getAccount().toString()));
    target.setSymbol(FIX::fields::Symbol(src.getSymbol().toString()));
    target.setSide(FIX::fields::Side(src.getSide().get()));
    target.setOrdType(FIX::fields::OrdType(src.getOrderType().get()));
    target.setOrderQty(FIX::fields::OrderQty(src.getOrderQty().get()));
    target.setTimeInForce(FIX::fields::TimeInForce(src.getTimeInForce().get()));
    target.setTransactTime(FIX::fields::TransactTime(src.getTransactTime().get()));
    target.setPrice(FIX::fields::Price(src.getPrice().get()));
    target.setStopPx(FIX::fields::StopPx(src.getStopPrice().get()));
    target.setCurrency(FIX::fields::Currency(src.getCurrency().toString()));
    target.setExecInst(FIX::fields::ExecInst(src.getExecutionInstruction().get()));
    return target;
}

// 12. CancelOrderRequest -> OrderCancelRequest
template<>
FIX::messages::OrderCancelRequest convert<FIX::messages::OrderCancelRequest, MODEL::messages::CancelOrderRequest>(const MODEL::messages::CancelOrderRequest& src) {
    FIX::messages::OrderCancelRequest target;
    target.setClOrdID(FIX::fields::ClOrdID(src.getClientOrderId().toString()));
    target.setOrigClOrdID(FIX::fields::OrigClOrdID(src.getOriginalClientOrderId().toString()));
    target.setSymbol(FIX::fields::Symbol(src.getSymbol().toString()));
    target.setSide(FIX::fields::Side(src.getSide().get()));
    return target;
}

// 13. ReplaceOrderRequest -> OrderCancelReplaceRequest
template<>
FIX::messages::OrderCancelReplaceRequest convert<FIX::messages::OrderCancelReplaceRequest, MODEL::messages::ReplaceOrderRequest>(const MODEL::messages::ReplaceOrderRequest& src) {
    FIX::messages::OrderCancelReplaceRequest target;
    target.setClOrdID(FIX::fields::ClOrdID(src.getClientOrderId().toString()));
    target.setOrigClOrdID(FIX::fields::OrigClOrdID(src.getOriginalClientOrderId().toString()));
    target.setOrderQty(FIX::fields::OrderQty(src.getOrderQty().get()));
    target.setPrice(FIX::fields::Price(src.getPrice().get()));
    target.setStopPx(FIX::fields::StopPx(src.getStopPrice().get()));
    target.setTimeInForce(FIX::fields::TimeInForce(src.getTimeInForce().get()));
    return target;
}

// 14. CreateOrderExecution -> ExecutionReport
template<>
FIX::messages::ExecutionReport convert<FIX::messages::ExecutionReport, MODEL::messages::CreateOrderExecution>(const MODEL::messages::CreateOrderExecution& src) {
    FIX::messages::ExecutionReport target;
    target.setClOrdID(FIX::fields::ClOrdID(src.getClientOrderId().toString()));
    target.setOrderID(FIX::fields::OrderID(src.getVenueOrderId().toString()));
    target.setExecID(FIX::fields::ExecID(src.getExecutionId().toString()));
    target.setExecType(FIX::fields::ExecType(src.getExecutionType().get()));
    target.setOrdStatus(FIX::fields::OrdStatus(src.getOrderStatus().get()));
    target.setOrderQty(FIX::fields::OrderQty(src.getOrderQty().get()));
    target.setCumQty(FIX::fields::CumQty(src.getFilledQuantity().get()));
    target.setLeavesQty(FIX::fields::LeavesQty(src.getRemainingQuantity().get()));
    target.setAvgPx(FIX::fields::AvgPx(src.getAveragePrice().get()));
    target.setText(FIX::fields::Text(src.getText().toString()));
    // Convert reject reason string back to reject reason enum if parsing is possible, or use standard default
    target.setOrdRejReason(FIX::fields::OrdRejReason(0)); // default broker option or mapping if needed
    return target;
}

} // namespace marx::fix::conversions
