#pragma once

#include "FIX/messages/NewOrderSingle.hpp"
#include "FIX/messages/ExecutionReport.hpp"
#include "FIX/messages/OrderCancelRequest.hpp"
#include "FIX/messages/OrderCancelReplaceRequest.hpp"
#include "FIX/messages/OrderCancelReject.hpp"

#include "MODEL/messages/NewOrderRequest.hpp"
#include "MODEL/messages/CreateOrderExecution.hpp"
#include "MODEL/messages/CreateOrderReject.hpp"
#include "MODEL/messages/FillOrderExecution.hpp"
#include "MODEL/messages/CancelOrderRequest.hpp"
#include "MODEL/messages/CancelOrderExecution.hpp"
#include "MODEL/messages/CancelOrderReject.hpp"
#include "MODEL/messages/ReplaceOrderRequest.hpp"
#include "MODEL/messages/ReplaceOrderExecution.hpp"
#include "MODEL/messages/ReplaceOrderReject.hpp"

namespace marx::fix::conversions {

/// General conversion template. Specialized in the source file.
template<typename Target, typename Source>
Target convert(const Source& src);

} // namespace marx::fix::conversions
