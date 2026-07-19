#pragma once

#include "OUCH/messages/EnterOrder.hpp"
#include "OUCH/messages/ReplaceOrderRequest.hpp"
#include "OUCH/messages/CancelOrderRequest.hpp"
#include "OUCH/messages/OrderAccepted.hpp"
#include "OUCH/messages/OrderReplaced.hpp"
#include "OUCH/messages/OrderCanceled.hpp"
#include "OUCH/messages/OrderExecuted.hpp"
#include "OUCH/messages/Rejected.hpp"

#include <cstdint>
#include <functional>
#include <string>
#include <vector>
#include <variant>

namespace marx::ouch {

using OuchMessage = std::variant<
    OUCH::messages::EnterOrder,
    OUCH::messages::ReplaceOrderRequest,
    OUCH::messages::CancelOrderRequest,
    OUCH::messages::OrderAccepted,
    OUCH::messages::OrderReplaced,
    OUCH::messages::OrderCanceled,
    OUCH::messages::OrderExecuted,
    OUCH::messages::Rejected
>;

class OuchDecoder {
public:
    OuchDecoder() = default;

    std::function<void(const OuchMessage&)> onMessage;
    std::function<void(const std::string& error)> onError;

    void onData(const char* data, std::size_t len);
    void reset();

private:
    bool tryExtractMessage();
    
    std::vector<char> buffer_;
};

} // namespace marx::ouch
