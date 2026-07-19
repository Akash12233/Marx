#pragma once

#include "MODEL/messages/Order.hpp"
#include "MODEL/messages/NewOrderRequest.hpp"
#include "MODEL/messages/ReplaceOrderRequest.hpp"
#include "MODEL/messages/FillOrderExecution.hpp"

#include <string>
#include <vector>
#include <unordered_map>

namespace marx {

struct OrderRecord {
    std::string marxId;
    MODEL::messages::Order cdmOrder;
    std::string parentMarxId;
    std::string successorMarxId;
    std::vector<std::string> executionIds;
    std::string sessionId;
    
    // Store previous status in case we need to restore it (e.g. Cancel/Replace Reject)
    char previousStatus = '0';
};

class OrderStore {
public:
    OrderStore() = default;

    // Operational mutations (Single Source of Truth)
    OrderRecord& createOrder(const MODEL::messages::NewOrderRequest& req, const std::string& sessionId);
    void acceptOrder(const std::string& marxId, const std::string& venueOrderId);
    void rejectOrder(const std::string& marxId, const std::string& reason);
    
    OrderRecord& replaceOrder(const std::string& parentMarxId, const MODEL::messages::ReplaceOrderRequest& req);
    void acceptReplace(const std::string& childMarxId);
    void rejectReplace(const std::string& childMarxId);
    
    void cancelOrder(const std::string& marxId);
    void acceptCancel(const std::string& marxId);
    void rejectCancel(const std::string& marxId);
    
    void applyExecution(const std::string& marxId, const MODEL::messages::FillOrderExecution& exec);

    // Lookups
    OrderRecord* findByMarxId(const std::string& marxId);
    OrderRecord* findActiveOrder(const std::string& marxId);
    OrderRecord* findByClientOrderId(const std::string& clOrdId);
    OrderRecord* findByVenueOrderId(const std::string& venueOrdId);
    
    std::string getOriginalClientOrderId(const std::string& marxId);

private:
    std::string generateMarxId();

    std::unordered_map<std::string, OrderRecord> orders_; // marxId -> Record
    std::unordered_map<std::string, std::string> clOrdIdToMarxId_;
    std::unordered_map<std::string, std::string> venueOrdIdToMarxId_;
    std::unordered_map<std::string, std::string> execIdToMarxId_;
    
    std::uint64_t nextMarxIdNum_ = 1;
};

} // namespace marx
