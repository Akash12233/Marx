#pragma once

#include "OUCH/messages/EnterOrder.hpp"
#include "OUCH/messages/ReplaceOrderRequest.hpp"
#include "OUCH/messages/CancelOrderRequest.hpp"
#include "OUCH/messages/OrderAccepted.hpp"
#include "OUCH/messages/OrderReplaced.hpp"
#include "OUCH/messages/OrderCanceled.hpp"
#include "OUCH/messages/OrderExecuted.hpp"
#include "OUCH/messages/Rejected.hpp"

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

namespace marx::ouch::conversions {

/// General OUCH conversion template. Specialized in the source file.
template<typename Target, typename Source>
Target convert(const Source& src);

} // namespace marx::ouch::conversions
