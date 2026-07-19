#pragma once

#include "protocol/ouch/OuchConversions.h"

#include <string>

namespace marx::ouch {

class Ouch {
public:
    Ouch() = default;

    MODEL::messages::NewOrderRequest toNewOrderRequest(const OUCH::messages::EnterOrder& src);
    OUCH::messages::EnterOrder toEnterOrder(const MODEL::messages::NewOrderRequest& src);

    MODEL::messages::CreateOrderExecution toCreateOrderExecution(const OUCH::messages::OrderAccepted& src);
    MODEL::messages::CreateOrderReject toCreateOrderReject(const OUCH::messages::Rejected& src);
    MODEL::messages::FillOrderExecution toFillOrderExecution(const OUCH::messages::OrderExecuted& src);
    MODEL::messages::ReplaceOrderExecution toReplaceOrderExecution(const OUCH::messages::OrderReplaced& src);
    MODEL::messages::CancelOrderExecution toCancelOrderExecution(const OUCH::messages::OrderCanceled& src);

    MODEL::messages::CancelOrderRequest toCancelOrderRequest(const OUCH::messages::CancelOrderRequest& src);
    OUCH::messages::CancelOrderRequest toCancelOrderRequest(const MODEL::messages::CancelOrderRequest& src);

    MODEL::messages::ReplaceOrderRequest toReplaceOrderRequest(const OUCH::messages::ReplaceOrderRequest& src);
    OUCH::messages::ReplaceOrderRequest toReplaceOrderRequest(const MODEL::messages::ReplaceOrderRequest& src);
};

} // namespace marx::ouch
