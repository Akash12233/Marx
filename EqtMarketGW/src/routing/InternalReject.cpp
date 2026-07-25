#include "routing/InternalReject.h"

namespace marx {

std::string InternalReject::formatReason(const std::string& reason) {
    if (reason.rfind("MARX: ", 0) == 0 || reason.rfind("EX: ", 0) == 0) {
        return reason;
    }
    return "MARX: " + reason;
}

MODEL::messages::CreateOrderReject InternalReject::createOrderReject(
    const std::string& clientOrderId,
    const std::string& reason,
    int orderQty)
{
    std::string formatted = formatReason(reason);
    MODEL::messages::CreateOrderReject reject;
    reject.setClientOrderId(MODEL::fields::ClientOrderId(clientOrderId));
    reject.setOrderStatus(MODEL::fields::OrderStatus('8'));     // Rejected
    reject.setExecutionType(MODEL::fields::ExecutionType('8')); // Rejected
    reject.setOrderQty(MODEL::fields::OrderQty(orderQty));
    reject.setFilledQuantity(MODEL::fields::FilledQuantity(0));
    reject.setRemainingQuantity(MODEL::fields::RemainingQuantity(0));
    reject.setAveragePrice(MODEL::fields::AveragePrice(0.0));
    reject.setText(MODEL::fields::Text(formatted));
    reject.setRejectReason(MODEL::fields::RejectReason(formatted));
    return reject;
}

MODEL::messages::ReplaceOrderReject InternalReject::replaceOrderReject(
    const std::string& clientOrderId,
    const std::string& reason,
    const std::string& venueOrderId)
{
    std::string formatted = formatReason(reason);
    MODEL::messages::ReplaceOrderReject reject;
    reject.setClientOrderId(MODEL::fields::ClientOrderId(clientOrderId));
    reject.setVenueOrderId(MODEL::fields::VenueOrderId(venueOrderId));
    reject.setOrderStatus(MODEL::fields::OrderStatus('8'));     // Rejected
    reject.setRejectReason(MODEL::fields::RejectReason(formatted));
    return reject;
}

MODEL::messages::CancelOrderReject InternalReject::cancelOrderReject(
    const std::string& clientOrderId,
    const std::string& reason,
    const std::string& venueOrderId)
{
    std::string formatted = formatReason(reason);
    MODEL::messages::CancelOrderReject reject;
    reject.setClientOrderId(MODEL::fields::ClientOrderId(clientOrderId));
    reject.setVenueOrderId(MODEL::fields::VenueOrderId(venueOrderId));
    reject.setOrderStatus(MODEL::fields::OrderStatus('8'));     // Rejected
    reject.setRejectReason(MODEL::fields::RejectReason(formatted));
    return reject;
}

} // namespace marx
