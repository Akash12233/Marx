#pragma once

#include "OUCH/messages/EnterOrder.hpp"
#include "OUCH/messages/ReplaceOrderRequest.hpp"
#include "OUCH/messages/CancelOrderRequest.hpp"
#include "OUCH/messages/OrderAccepted.hpp"
#include "OUCH/messages/OrderReplaced.hpp"
#include "OUCH/messages/OrderCanceled.hpp"
#include "OUCH/messages/OrderExecuted.hpp"
#include "OUCH/messages/Rejected.hpp"

#include <vector>

namespace marx::ouch {

class OuchEncoder {
public:
    OuchEncoder() = default;

    std::vector<char> encode(const OUCH::messages::EnterOrder& msg);
    std::vector<char> encode(const OUCH::messages::ReplaceOrderRequest& msg);
    std::vector<char> encode(const OUCH::messages::CancelOrderRequest& msg);
    std::vector<char> encode(const OUCH::messages::OrderAccepted& msg);
    std::vector<char> encode(const OUCH::messages::OrderReplaced& msg);
    std::vector<char> encode(const OUCH::messages::OrderCanceled& msg);
    std::vector<char> encode(const OUCH::messages::OrderExecuted& msg);
    std::vector<char> encode(const OUCH::messages::Rejected& msg);
};

} // namespace marx::ouch
