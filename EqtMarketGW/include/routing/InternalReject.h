#pragma once

#include "MODEL/messages/CreateOrderReject.hpp"
#include "MODEL/messages/ReplaceOrderReject.hpp"
#include "MODEL/messages/CancelOrderReject.hpp"

#include <string>

namespace marx {

class InternalReject {
public:
    static MODEL::messages::CreateOrderReject createOrderReject(
        const std::string& clientOrderId,
        const std::string& reason,
        int orderQty = 0);

    static MODEL::messages::ReplaceOrderReject replaceOrderReject(
        const std::string& clientOrderId,
        const std::string& reason,
        const std::string& venueOrderId = "");

    static MODEL::messages::CancelOrderReject cancelOrderReject(
        const std::string& clientOrderId,
        const std::string& reason,
        const std::string& venueOrderId = "");

private:
    static std::string formatReason(const std::string& reason);
};

} // namespace marx
