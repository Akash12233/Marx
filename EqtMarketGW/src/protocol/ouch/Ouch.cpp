#include "protocol/ouch/Ouch.h"

namespace marx::ouch {

MODEL::messages::NewOrderRequest Ouch::toNewOrderRequest(const OUCH::messages::EnterOrder& src) {
    return conversions::convert<MODEL::messages::NewOrderRequest>(src);
}

OUCH::messages::EnterOrder Ouch::toEnterOrder(const MODEL::messages::NewOrderRequest& src) {
    return conversions::convert<OUCH::messages::EnterOrder>(src);
}

MODEL::messages::CreateOrderExecution Ouch::toCreateOrderExecution(const OUCH::messages::OrderAccepted& src) {
    return conversions::convert<MODEL::messages::CreateOrderExecution>(src);
}

MODEL::messages::CreateOrderReject Ouch::toCreateOrderReject(const OUCH::messages::Rejected& src) {
    return conversions::convert<MODEL::messages::CreateOrderReject>(src);
}

MODEL::messages::FillOrderExecution Ouch::toFillOrderExecution(const OUCH::messages::OrderExecuted& src) {
    return conversions::convert<MODEL::messages::FillOrderExecution>(src);
}

MODEL::messages::ReplaceOrderExecution Ouch::toReplaceOrderExecution(const OUCH::messages::OrderReplaced& src) {
    return conversions::convert<MODEL::messages::ReplaceOrderExecution>(src);
}

MODEL::messages::CancelOrderExecution Ouch::toCancelOrderExecution(const OUCH::messages::OrderCanceled& src) {
    return conversions::convert<MODEL::messages::CancelOrderExecution>(src);
}

MODEL::messages::CancelOrderRequest Ouch::toCancelOrderRequest(const OUCH::messages::CancelOrderRequest& src) {
    return conversions::convert<MODEL::messages::CancelOrderRequest>(src);
}

OUCH::messages::CancelOrderRequest Ouch::toCancelOrderRequest(const MODEL::messages::CancelOrderRequest& src) {
    return conversions::convert<OUCH::messages::CancelOrderRequest>(src);
}

MODEL::messages::ReplaceOrderRequest Ouch::toReplaceOrderRequest(const OUCH::messages::ReplaceOrderRequest& src) {
    return conversions::convert<MODEL::messages::ReplaceOrderRequest>(src);
}

OUCH::messages::ReplaceOrderRequest Ouch::toReplaceOrderRequest(const MODEL::messages::ReplaceOrderRequest& src) {
    return conversions::convert<OUCH::messages::ReplaceOrderRequest>(src);
}

} // namespace marx::ouch
