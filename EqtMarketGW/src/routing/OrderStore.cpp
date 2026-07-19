#include "routing/OrderStore.h"
#include "MODEL/enumerations/Enumerations.hpp"
#include <sstream>
#include <iomanip>

namespace marx {

// ---------------------------------------------------------------------------
// generateMarxId
// ---------------------------------------------------------------------------
std::string OrderStore::generateMarxId() {
    std::ostringstream oss;
    oss << "MARX" << std::setw(6) << std::setfill('0') << nextMarxIdNum_++;
    return oss.str();
}

// ---------------------------------------------------------------------------
// createOrder
// ---------------------------------------------------------------------------
OrderRecord& OrderStore::createOrder(const MODEL::messages::NewOrderRequest& req, const std::string& sessionId) {
    std::string marxId = generateMarxId();
    
    OrderRecord rec;
    rec.marxId = marxId;
    rec.sessionId = sessionId;
    
    rec.cdmOrder.setClientOrderId(req.getClientOrderId());
    rec.cdmOrder.setAccount(req.getAccount());
    rec.cdmOrder.setSymbol(req.getSymbol());
    rec.cdmOrder.setSide(req.getSide());
    rec.cdmOrder.setOrderType(req.getOrderType());
    rec.cdmOrder.setOrderQty(req.getOrderQty());
    rec.cdmOrder.setPrice(req.getPrice());
    rec.cdmOrder.setStopPrice(req.getStopPrice());
    rec.cdmOrder.setTimeInForce(req.getTimeInForce());
    rec.cdmOrder.setCurrency(req.getCurrency());
    
    // Initial state: Pending New
    rec.cdmOrder.setOrderStatus(MODEL::fields::OrderStatus('A')); 
    rec.cdmOrder.setCumQty(MODEL::fields::CumQty(0));
    rec.cdmOrder.setLeavesQty(MODEL::fields::LeavesQty(req.getOrderQty().get()));
    rec.cdmOrder.setAveragePrice(MODEL::fields::AveragePrice(0.0));
    rec.cdmOrder.setCreatedTime(MODEL::fields::CreatedTime(req.getTransactTime().get()));
    
    orders_[marxId] = std::move(rec);
    clOrdIdToMarxId_[req.getClientOrderId().toString()] = marxId;
    
    return orders_[marxId];
}

// ---------------------------------------------------------------------------
// acceptOrder
// ---------------------------------------------------------------------------
void OrderStore::acceptOrder(const std::string& marxId, const std::string& venueOrderId) {
    auto it = orders_.find(marxId);
    if (it != orders_.end()) {
        it->second.cdmOrder.setOrderStatus(MODEL::fields::OrderStatus('0')); // Status = New
        it->second.cdmOrder.setVenueOrderId(MODEL::fields::VenueOrderId(venueOrderId));
        venueOrdIdToMarxId_[venueOrderId] = marxId;
    }
}

// ---------------------------------------------------------------------------
// rejectOrder
// ---------------------------------------------------------------------------
void OrderStore::rejectOrder(const std::string& marxId, const std::string& reason) {
    auto it = orders_.find(marxId);
    if (it != orders_.end()) {
        it->second.cdmOrder.setOrderStatus(MODEL::fields::OrderStatus('8')); // Status = Rejected
        it->second.cdmOrder.setLeavesQty(MODEL::fields::LeavesQty(0));
        it->second.cdmOrder.setRejectReason(MODEL::fields::RejectReason(reason));
    }
}

// ---------------------------------------------------------------------------
// replaceOrder
// ---------------------------------------------------------------------------
OrderRecord& OrderStore::replaceOrder(const std::string& parentMarxId, const MODEL::messages::ReplaceOrderRequest& req) {
    std::string childMarxId = generateMarxId();
    
    OrderRecord child;
    child.marxId = childMarxId;
    child.parentMarxId = parentMarxId;
    
    auto pit = orders_.find(parentMarxId);
    if (pit != orders_.end()) {
        child.sessionId = pit->second.sessionId;
        // Copy static attributes from parent
        child.cdmOrder.setAccount(pit->second.cdmOrder.getAccount());
        child.cdmOrder.setSymbol(pit->second.cdmOrder.getSymbol());
        child.cdmOrder.setSide(pit->second.cdmOrder.getSide());
        child.cdmOrder.setOrderType(pit->second.cdmOrder.getOrderType());
        child.cdmOrder.setCurrency(pit->second.cdmOrder.getCurrency());
        child.cdmOrder.setCreatedTime(pit->second.cdmOrder.getCreatedTime());
        
        pit->second.successorMarxId = childMarxId;
    }
    
    child.cdmOrder.setClientOrderId(req.getClientOrderId());
    child.cdmOrder.setParentOrderId(MODEL::fields::ParentOrderId(parentMarxId));
    child.cdmOrder.setOrderQty(req.getOrderQty());
    child.cdmOrder.setPrice(req.getPrice());
    child.cdmOrder.setStopPrice(req.getStopPrice());
    child.cdmOrder.setTimeInForce(req.getTimeInForce());
    
    // State: Pending Replace
    child.cdmOrder.setOrderStatus(MODEL::fields::OrderStatus('E'));
    child.cdmOrder.setCumQty(MODEL::fields::CumQty(0));
    child.cdmOrder.setLeavesQty(MODEL::fields::LeavesQty(req.getOrderQty().get()));
    child.cdmOrder.setAveragePrice(MODEL::fields::AveragePrice(0.0));
    
    orders_[childMarxId] = std::move(child);
    clOrdIdToMarxId_[req.getClientOrderId().toString()] = childMarxId;
    
    return orders_[childMarxId];
}

// ---------------------------------------------------------------------------
// acceptReplace
// ---------------------------------------------------------------------------
void OrderStore::acceptReplace(const std::string& childMarxId) {
    auto cit = orders_.find(childMarxId);
    if (cit != orders_.end()) {
        cit->second.cdmOrder.setOrderStatus(MODEL::fields::OrderStatus('0')); // New
        
        // Update parent
        if (!cit->second.parentMarxId.empty()) {
            auto pit = orders_.find(cit->second.parentMarxId);
            if (pit != orders_.end()) {
                pit->second.cdmOrder.setOrderStatus(MODEL::fields::OrderStatus('5')); // Replaced
                pit->second.cdmOrder.setLeavesQty(MODEL::fields::LeavesQty(0));
                
                // Inherit CumQty and VenueOrderId
                cit->second.cdmOrder.setCumQty(MODEL::fields::CumQty(pit->second.cdmOrder.getCumQty().get()));
                cit->second.cdmOrder.setLeavesQty(MODEL::fields::LeavesQty(cit->second.cdmOrder.getOrderQty().get() - pit->second.cdmOrder.getCumQty().get()));
                cit->second.cdmOrder.setAveragePrice(MODEL::fields::AveragePrice(pit->second.cdmOrder.getAveragePrice().get()));
                cit->second.cdmOrder.setVenueOrderId(pit->second.cdmOrder.getVenueOrderId());
            }
        }
    }
}

// ---------------------------------------------------------------------------
// rejectReplace
// ---------------------------------------------------------------------------
void OrderStore::rejectReplace(const std::string& childMarxId) {
    auto cit = orders_.find(childMarxId);
    if (cit != orders_.end()) {
        cit->second.cdmOrder.setOrderStatus(MODEL::fields::OrderStatus('8')); // Rejected
        cit->second.cdmOrder.setLeavesQty(MODEL::fields::LeavesQty(0));
        
        // Restore parent
        if (!cit->second.parentMarxId.empty()) {
            auto pit = orders_.find(cit->second.parentMarxId);
            if (pit != orders_.end()) {
                pit->second.successorMarxId.clear(); // remove successor link
            }
        }
    }
}

// ---------------------------------------------------------------------------
// cancelOrder
// ---------------------------------------------------------------------------
void OrderStore::cancelOrder(const std::string& marxId) {
    auto it = orders_.find(marxId);
    if (it != orders_.end()) {
        it->second.previousStatus = it->second.cdmOrder.getOrderStatus().get();
        it->second.cdmOrder.setOrderStatus(MODEL::fields::OrderStatus('6')); // Pending Cancel
    }
}

// ---------------------------------------------------------------------------
// acceptCancel
// ---------------------------------------------------------------------------
void OrderStore::acceptCancel(const std::string& marxId) {
    auto it = orders_.find(marxId);
    if (it != orders_.end()) {
        it->second.cdmOrder.setOrderStatus(MODEL::fields::OrderStatus('4')); // Cancelled
        it->second.cdmOrder.setLeavesQty(MODEL::fields::LeavesQty(0));
    }
}

// ---------------------------------------------------------------------------
// rejectCancel
// ---------------------------------------------------------------------------
void OrderStore::rejectCancel(const std::string& marxId) {
    auto it = orders_.find(marxId);
    if (it != orders_.end()) {
        it->second.cdmOrder.setOrderStatus(MODEL::fields::OrderStatus(it->second.previousStatus));
    }
}

// ---------------------------------------------------------------------------
// applyExecution
// ---------------------------------------------------------------------------
void OrderStore::applyExecution(const std::string& marxId, const MODEL::messages::FillOrderExecution& exec) {
    auto it = orders_.find(marxId);
    if (it != orders_.end()) {
        auto& order = it->second.cdmOrder;
        
        int newCum = exec.getCumQty().get();
        int orderQty = order.getOrderQty().get();
        int newLeaves = (newCum >= orderQty) ? 0 : (orderQty - newCum);
        
        order.setCumQty(MODEL::fields::CumQty(newCum));
        order.setLeavesQty(MODEL::fields::LeavesQty(newLeaves));
        order.setAveragePrice(MODEL::fields::AveragePrice(exec.getAveragePrice().get()));
        order.setExecutionId(MODEL::fields::ExecutionId(exec.getExecutionId().toString()));
        
        it->second.executionIds.push_back(exec.getExecutionId().toString());
        execIdToMarxId_[exec.getExecutionId().toString()] = marxId;
        
        if (newLeaves == 0) {
            order.setOrderStatus(MODEL::fields::OrderStatus('2')); // Filled
        } else {
            order.setOrderStatus(MODEL::fields::OrderStatus('1')); // Partially Filled
        }
    }
}

// ---------------------------------------------------------------------------
// findByMarxId
// ---------------------------------------------------------------------------
OrderRecord* OrderStore::findByMarxId(const std::string& marxId) {
    auto it = orders_.find(marxId);
    if (it != orders_.end()) {
        return &it->second;
    }
    return nullptr;
}

// ---------------------------------------------------------------------------
// findActiveOrder
// ---------------------------------------------------------------------------
OrderRecord* OrderStore::findActiveOrder(const std::string& marxId) {
    auto it = orders_.find(marxId);
    if (it != orders_.end()) {
        OrderRecord* rec = &it->second;
        while (!rec->successorMarxId.empty()) {
            auto sit = orders_.find(rec->successorMarxId);
            if (sit != orders_.end() && sit->second.cdmOrder.getOrderStatus().get() != '8') { // not rejected
                rec = &sit->second;
            } else {
                break;
            }
        }
        return rec;
    }
    return nullptr;
}

// ---------------------------------------------------------------------------
// findByClientOrderId
// ---------------------------------------------------------------------------
OrderRecord* OrderStore::findByClientOrderId(const std::string& clOrdId) {
    auto it = clOrdIdToMarxId_.find(clOrdId);
    if (it != clOrdIdToMarxId_.end()) {
        return findActiveOrder(it->second);
    }
    return nullptr;
}

// ---------------------------------------------------------------------------
// findByVenueOrderId
// ---------------------------------------------------------------------------
OrderRecord* OrderStore::findByVenueOrderId(const std::string& venueOrdId) {
    auto it = venueOrdIdToMarxId_.find(venueOrdId);
    if (it != venueOrdIdToMarxId_.end()) {
        return findActiveOrder(it->second);
    }
    return nullptr;
}

// ---------------------------------------------------------------------------
// getOriginalClientOrderId
// ---------------------------------------------------------------------------
std::string OrderStore::getOriginalClientOrderId(const std::string& marxId) {
    auto it = orders_.find(marxId);
    if (it != orders_.end()) {
        // Trace back to the original root parent order's client order ID
        const OrderRecord* rec = &it->second;
        while (!rec->parentMarxId.empty()) {
            auto pit = orders_.find(rec->parentMarxId);
            if (pit != orders_.end()) {
                rec = &pit->second;
            } else {
                break;
            }
        }
        return rec->cdmOrder.getClientOrderId().toString();
    }
    return "";
}

} // namespace marx
