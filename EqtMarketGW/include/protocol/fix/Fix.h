#pragma once

#include "protocol/fix/FixConversions.h"

#include <string>
#include <unordered_map>

namespace marx::fix {

class Fix {
public:
    Fix();

    // Translations delegated to template conversion functions
    MODEL::messages::NewOrderRequest toNewOrderRequest(const FIX::messages::NewOrderSingle& src);
    FIX::messages::NewOrderSingle toNewOrderSingle(const MODEL::messages::NewOrderRequest& src);

    MODEL::messages::CreateOrderExecution toCreateOrderExecution(const FIX::messages::ExecutionReport& src);
    MODEL::messages::CreateOrderReject toCreateOrderReject(const FIX::messages::ExecutionReport& src);
    MODEL::messages::FillOrderExecution toFillOrderExecution(const FIX::messages::ExecutionReport& src);
    MODEL::messages::ReplaceOrderExecution toReplaceOrderExecution(const FIX::messages::ExecutionReport& src);
    MODEL::messages::CancelOrderExecution toCancelOrderExecution(const FIX::messages::ExecutionReport& src);

    MODEL::messages::CancelOrderRequest toCancelOrderRequest(const FIX::messages::OrderCancelRequest& src);
    FIX::messages::OrderCancelRequest toOrderCancelRequest(const MODEL::messages::CancelOrderRequest& src);

    MODEL::messages::ReplaceOrderRequest toReplaceOrderRequest(const FIX::messages::OrderCancelReplaceRequest& src);
    FIX::messages::OrderCancelReplaceRequest toOrderCancelReplaceRequest(const MODEL::messages::ReplaceOrderRequest& src);

    MODEL::messages::CancelOrderReject toCancelOrderReject(const FIX::messages::OrderCancelReject& src);
    MODEL::messages::ReplaceOrderReject toReplaceOrderReject(const FIX::messages::OrderCancelReject& src);

    FIX::messages::ExecutionReport toExecutionReport(const MODEL::messages::CreateOrderExecution& src);
};

} // namespace marx::fix
