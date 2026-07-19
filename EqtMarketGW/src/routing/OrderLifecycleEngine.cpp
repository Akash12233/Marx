#include "routing/OrderLifecycleEngine.h"
#include "abstract/Logger.h"
#include <sstream>


namespace marx {

OrderLifecycleEngine::OrderLifecycleEngine(OrderStore& store)
    : store_(store)
{
}

// ---------------------------------------------------------------------------
// processNewOrder
// ---------------------------------------------------------------------------
std::variant<OrderRecord*, MODEL::messages::CreateOrderReject>
OrderLifecycleEngine::processNewOrder(const MODEL::messages::NewOrderRequest& req, const std::string& sessionId)
{
    // Business Validation
    bool valid = true;
    std::string rejectReason;

    if (req.getOrderQty().get() <= 0) {
        valid = false;
        rejectReason = "OrderQty must be greater than zero";
    } else if (req.getPrice().get() <= 0.0) {
        valid = false;
        rejectReason = "Price must be greater than zero";
    } else if (req.getSymbol().toString().empty()) {
        valid = false;
        rejectReason = "Symbol must not be empty";
    }

    if (!valid) {
        MODEL::messages::CreateOrderReject reject;
        reject.setClientOrderId(req.getClientOrderId());
        reject.setOrderStatus(MODEL::fields::OrderStatus('8')); // Rejected
        reject.setExecutionType(MODEL::fields::ExecutionType('8')); // Rejected
        reject.setOrderQty(req.getOrderQty());
        reject.setFilledQuantity(MODEL::fields::FilledQuantity(0));
        reject.setRemainingQuantity(MODEL::fields::RemainingQuantity(0));
        reject.setAveragePrice(MODEL::fields::AveragePrice(0.0));
        reject.setRejectReason(MODEL::fields::RejectReason(rejectReason));
        return reject;
    }

    // Persist new order in store
    OrderRecord& rec = store_.createOrder(req, sessionId);
    return &rec;
}

// ---------------------------------------------------------------------------
// processReplaceRequest
// ---------------------------------------------------------------------------
std::variant<OrderRecord*, MODEL::messages::ReplaceOrderReject>
OrderLifecycleEngine::processReplaceRequest(const MODEL::messages::ReplaceOrderRequest& req)
{
    // Find parent order
    std::string origClOrdId = req.getOriginalClientOrderId().toString();
    OrderRecord* parent = store_.findByClientOrderId(origClOrdId);
    
    bool valid = true;
    std::string rejectReason;

    if (!parent) {
        valid = false;
        rejectReason = "Original order not found: " + origClOrdId;
    } else {
        char status = parent->cdmOrder.getOrderStatus().get();
        if (status != '0' && status != '1') { // must be New or PartiallyFilled
            valid = false;
            rejectReason = "Order not in replaceable state: status=" + std::string(1, status);
        } else if (req.getOrderQty().get() <= 0) {
            valid = false;
            rejectReason = "New Qty must be greater than zero";
        } else if (req.getPrice().get() <= 0.0) {
            valid = false;
            rejectReason = "New Price must be greater than zero";
        }
    }

    if (!valid) {
        MODEL::messages::ReplaceOrderReject reject;
        reject.setClientOrderId(req.getClientOrderId());
        if (parent) {
            reject.setVenueOrderId(parent->cdmOrder.getVenueOrderId());
            reject.setOrderStatus(parent->cdmOrder.getOrderStatus());
        } else {
            reject.setOrderStatus(MODEL::fields::OrderStatus('8'));
        }
        reject.setRejectReason(MODEL::fields::RejectReason(rejectReason));
        return reject;
    }

    // Persist replacement in store
    OrderRecord& child = store_.replaceOrder(parent->marxId, req);
    return &child;
}

// ---------------------------------------------------------------------------
// processCancelRequest
// ---------------------------------------------------------------------------
std::variant<std::string, MODEL::messages::CancelOrderReject>
OrderLifecycleEngine::processCancelRequest(const MODEL::messages::CancelOrderRequest& req)
{
    // Find target order
    std::string origClOrdId = req.getOriginalClientOrderId().toString();
    OrderRecord* record = store_.findByClientOrderId(origClOrdId);
    
    bool valid = true;
    std::string rejectReason;

    if (!record) {
        valid = false;
        rejectReason = "Original order not found: " + origClOrdId;
    } else {
        char status = record->cdmOrder.getOrderStatus().get();
        if (status != '0' && status != '1') { // must be New or PartiallyFilled
            valid = false;
            rejectReason = "Order not in cancellable state: status=" + std::string(1, status);
        }
    }

    if (!valid) {
        MODEL::messages::CancelOrderReject reject;
        reject.setClientOrderId(req.getClientOrderId());
        if (record) {
            reject.setVenueOrderId(record->cdmOrder.getVenueOrderId());
            reject.setOrderStatus(record->cdmOrder.getOrderStatus());
        } else {
            reject.setOrderStatus(MODEL::fields::OrderStatus('8'));
        }
        reject.setRejectReason(MODEL::fields::RejectReason(rejectReason));
        return reject;
    }

    // Transition state to Pending Cancel
    store_.cancelOrder(record->marxId);
    return record->marxId;
}

// =-------------------------------------------------------------------------
// Venue Execution/Reject Handlers
// =-------------------------------------------------------------------------

void OrderLifecycleEngine::processCreateExecution(const MODEL::messages::CreateOrderExecution& exec)
{
    std::string marxId = exec.getClientOrderId().toString();
    store_.acceptOrder(marxId, exec.getVenueOrderId().toString());
}

void OrderLifecycleEngine::processCreateReject(const MODEL::messages::CreateOrderReject& rej)
{
    std::string marxId = rej.getClientOrderId().toString();
    store_.rejectOrder(marxId, rej.getRejectReason().toString());
}

void OrderLifecycleEngine::processReplaceExecution(const MODEL::messages::ReplaceOrderExecution& exec)
{
    std::string childMarxId = exec.getClientOrderId().toString();
    store_.acceptReplace(childMarxId);
}

void OrderLifecycleEngine::processReplaceReject(const MODEL::messages::ReplaceOrderReject& rej)
{
    std::string childMarxId = rej.getClientOrderId().toString();
    store_.rejectReplace(childMarxId);
}

void OrderLifecycleEngine::processCancelExecution(const MODEL::messages::CancelOrderExecution& exec)
{
    std::string clOrdId = exec.getClientOrderId().toString();
    std::string marxId = (clOrdId.size() > 2 && clOrdId.substr(clOrdId.size() - 2) == "_C")
                         ? clOrdId.substr(0, clOrdId.size() - 2)
                         : clOrdId;
    store_.acceptCancel(marxId);
}

void OrderLifecycleEngine::processCancelReject(const MODEL::messages::CancelOrderReject& rej)
{
    std::string clOrdId = rej.getClientOrderId().toString();
    std::string marxId = (clOrdId.size() > 2 && clOrdId.substr(clOrdId.size() - 2) == "_C")
                         ? clOrdId.substr(0, clOrdId.size() - 2)
                         : clOrdId;
    store_.rejectCancel(marxId);
}

void OrderLifecycleEngine::processFillExecution(const MODEL::messages::FillOrderExecution& exec)
{
    std::string marxId = exec.getClientOrderId().toString();
    OrderRecord* record = store_.findByMarxId(marxId);
    
    if (record) {
        int currentCum = record->cdmOrder.getCumQty().get();
        int orderQty = record->cdmOrder.getOrderQty().get();
        int lastFill = exec.getLastFillQuantity().get();
        
        if (currentCum + lastFill > orderQty) {
            std::stringstream ss;
            ss << "OVERFILL DETECTED for Order " << marxId 
               << " (Original ClOrdID: " << store_.getOriginalClientOrderId(marxId) << "). "
               << "Current CumQty: " << currentCum 
               << ", incoming FillQty: " << lastFill 
               << ", total would be: " << (currentCum + lastFill) 
               << ", exceeding OrderQty: " << orderQty << ". Routing fill anyway.";
            LOG_WARN("OrderLifecycleEngine", ss.str());
        }
    } else {
        LOG_ERROR("OrderLifecycleEngine", "Received execution fill for unknown Order: " + marxId);
    }

    store_.applyExecution(marxId, exec);
}

} // namespace marx
