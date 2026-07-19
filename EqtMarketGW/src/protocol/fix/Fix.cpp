#include "protocol/fix/Fix.h"

namespace marx::fix {

Fix::Fix() = default;

MODEL::messages::NewOrderRequest Fix::toNewOrderRequest(const FIX::messages::NewOrderSingle& src) {
    return conversions::convert<MODEL::messages::NewOrderRequest>(src);
}

FIX::messages::NewOrderSingle Fix::toNewOrderSingle(const MODEL::messages::NewOrderRequest& src) {
    return conversions::convert<FIX::messages::NewOrderSingle>(src);
}

MODEL::messages::CreateOrderExecution Fix::toCreateOrderExecution(const FIX::messages::ExecutionReport& src) {
    return conversions::convert<MODEL::messages::CreateOrderExecution>(src);
}

MODEL::messages::CreateOrderReject Fix::toCreateOrderReject(const FIX::messages::ExecutionReport& src) {
    return conversions::convert<MODEL::messages::CreateOrderReject>(src);
}

MODEL::messages::FillOrderExecution Fix::toFillOrderExecution(const FIX::messages::ExecutionReport& src) {
    return conversions::convert<MODEL::messages::FillOrderExecution>(src);
}

MODEL::messages::ReplaceOrderExecution Fix::toReplaceOrderExecution(const FIX::messages::ExecutionReport& src) {
    return conversions::convert<MODEL::messages::ReplaceOrderExecution>(src);
}

MODEL::messages::CancelOrderExecution Fix::toCancelOrderExecution(const FIX::messages::ExecutionReport& src) {
    return conversions::convert<MODEL::messages::CancelOrderExecution>(src);
}

MODEL::messages::CancelOrderRequest Fix::toCancelOrderRequest(const FIX::messages::OrderCancelRequest& src) {
    return conversions::convert<MODEL::messages::CancelOrderRequest>(src);
}

FIX::messages::OrderCancelRequest Fix::toOrderCancelRequest(const MODEL::messages::CancelOrderRequest& src) {
    return conversions::convert<FIX::messages::OrderCancelRequest>(src);
}

MODEL::messages::ReplaceOrderRequest Fix::toReplaceOrderRequest(const FIX::messages::OrderCancelReplaceRequest& src) {
    return conversions::convert<MODEL::messages::ReplaceOrderRequest>(src);
}

FIX::messages::OrderCancelReplaceRequest Fix::toOrderCancelReplaceRequest(const MODEL::messages::ReplaceOrderRequest& src) {
    return conversions::convert<FIX::messages::OrderCancelReplaceRequest>(src);
}

MODEL::messages::CancelOrderReject Fix::toCancelOrderReject(const FIX::messages::OrderCancelReject& src) {
    return conversions::convert<MODEL::messages::CancelOrderReject>(src);
}

MODEL::messages::ReplaceOrderReject Fix::toReplaceOrderReject(const FIX::messages::OrderCancelReject& src) {
    return conversions::convert<MODEL::messages::ReplaceOrderReject>(src);
}

FIX::messages::ExecutionReport Fix::toExecutionReport(const MODEL::messages::CreateOrderExecution& src) {
    return conversions::convert<FIX::messages::ExecutionReport>(src);
}

} // namespace marx::fix
