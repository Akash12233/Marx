#include "routing/Router.h"
#include <iostream>

namespace marx {

Router::Router(EndpointRegistry& registry, OrderLifecycleEngine& engine, OrderStore& store)
    : registry_(registry)
    , lifecycleEngine_(engine)
    , store_(store)
{
}

// ===========================================================================
// Client Requests (Outbound to Venue)
// ===========================================================================

void Router::routeFromClient(const std::string& sessionId, const MODEL::messages::NewOrderRequest& msg) {
    auto res = lifecycleEngine_.processNewOrder(msg, sessionId);
    
    if (std::holds_alternative<MODEL::messages::CreateOrderReject>(res)) {
        // Validation failed, route reject back to client
        auto reject = std::get<MODEL::messages::CreateOrderReject>(res);
        Session* client = registry_.lookup(sessionId);
        if (client) {
            client->routeCDM(reject);
        }
    } else {
        // Success: forward NewOrderRequest to venue with MARXID as the ClientOrderId
        auto record = std::get<OrderRecord*>(res);
        
        MODEL::messages::NewOrderRequest venueReq;
        venueReq.setClientOrderId(MODEL::fields::ClientOrderId(record->marxId));
        venueReq.setAccount(msg.getAccount());
        venueReq.setSymbol(msg.getSymbol());
        venueReq.setSide(msg.getSide());
        venueReq.setOrderType(msg.getOrderType());
        venueReq.setOrderQty(msg.getOrderQty());
        venueReq.setTimeInForce(msg.getTimeInForce());
        venueReq.setTransactTime(msg.getTransactTime());
        venueReq.setPrice(msg.getPrice());
        venueReq.setStopPrice(msg.getStopPrice());
        venueReq.setExecutionInstruction(msg.getExecutionInstruction());
        venueReq.setCurrency(msg.getCurrency());
        
        Session* venue = registry_.lookup(venueSessionId_);
        if (venue) {
            venue->routeCDM(venueReq);
        }
    }
}

void Router::routeFromClient(const std::string& sessionId, const MODEL::messages::ReplaceOrderRequest& msg) {
    auto res = lifecycleEngine_.processReplaceRequest(msg);
    
    if (std::holds_alternative<MODEL::messages::ReplaceOrderReject>(res)) {
        auto reject = std::get<MODEL::messages::ReplaceOrderReject>(res);
        Session* client = registry_.lookup(sessionId);
        if (client) {
            client->routeCDM(reject);
        }
    } else {
        auto record = std::get<OrderRecord*>(res);
        
        MODEL::messages::ReplaceOrderRequest venueReq;
        venueReq.setClientOrderId(MODEL::fields::ClientOrderId(record->marxId));
        venueReq.setOriginalClientOrderId(MODEL::fields::OriginalClientOrderId(record->parentMarxId));
        venueReq.setOrderQty(msg.getOrderQty());
        venueReq.setPrice(msg.getPrice());
        venueReq.setStopPrice(msg.getStopPrice());
        venueReq.setTimeInForce(msg.getTimeInForce());
        
        Session* venue = registry_.lookup(venueSessionId_);
        if (venue) {
            venue->routeCDM(venueReq);
        }
    }
}

void Router::routeFromClient(const std::string& sessionId, const MODEL::messages::CancelOrderRequest& msg) {
    auto res = lifecycleEngine_.processCancelRequest(msg);
    
    if (std::holds_alternative<MODEL::messages::CancelOrderReject>(res)) {
        auto reject = std::get<MODEL::messages::CancelOrderReject>(res);
        Session* client = registry_.lookup(sessionId);
        if (client) {
            client->routeCDM(reject);
        }
    } else {
        auto marxId = std::get<std::string>(res);
        
        MODEL::messages::CancelOrderRequest venueReq;
        venueReq.setClientOrderId(MODEL::fields::ClientOrderId(marxId + "_C"));
        venueReq.setOriginalClientOrderId(MODEL::fields::OriginalClientOrderId(marxId));
        venueReq.setSymbol(msg.getSymbol());
        venueReq.setSide(msg.getSide());
        
        Session* venue = registry_.lookup(venueSessionId_);
        if (venue) {
            venue->routeCDM(venueReq);
        }
    }
}

// ===========================================================================
// Venue Executions (Inbound to Client)
// ===========================================================================

void Router::routeFromVenue(const MODEL::messages::CreateOrderExecution& msg) {
    lifecycleEngine_.processCreateExecution(msg);
    
    std::string marxId = msg.getClientOrderId().toString();
    OrderRecord* record = store_.findByMarxId(marxId);
    if (record) {
        // Prepare a copy of the execution report with original client order ID
        MODEL::messages::CreateOrderExecution clientExec = msg;
        clientExec.setClientOrderId(MODEL::fields::ClientOrderId(store_.getOriginalClientOrderId(marxId)));
        
        Session* client = registry_.lookup(record->sessionId);
        if (client) {
            client->routeCDM(clientExec);
        }
    }
}

void Router::routeFromVenue(const MODEL::messages::CreateOrderReject& msg) {
    lifecycleEngine_.processCreateReject(msg);
    
    std::string marxId = msg.getClientOrderId().toString();
    OrderRecord* record = store_.findByMarxId(marxId);
    if (record) {
        MODEL::messages::CreateOrderReject clientRej = msg;
        clientRej.setClientOrderId(MODEL::fields::ClientOrderId(store_.getOriginalClientOrderId(marxId)));
        
        Session* client = registry_.lookup(record->sessionId);
        if (client) {
            client->routeCDM(clientRej);
        }
    }
}

void Router::routeFromVenue(const MODEL::messages::ReplaceOrderExecution& msg) {
    lifecycleEngine_.processReplaceExecution(msg);
    
    std::string marxId = msg.getClientOrderId().toString();
    OrderRecord* record = store_.findByMarxId(marxId);
    if (record) {
        MODEL::messages::ReplaceOrderExecution clientExec = msg;
        clientExec.setClientOrderId(MODEL::fields::ClientOrderId(record->cdmOrder.getClientOrderId().toString()));
        
        Session* client = registry_.lookup(record->sessionId);
        if (client) {
            client->routeCDM(clientExec);
        }
    }
}

void Router::routeFromVenue(const MODEL::messages::ReplaceOrderReject& msg) {
    lifecycleEngine_.processReplaceReject(msg);
    
    std::string marxId = msg.getClientOrderId().toString();
    OrderRecord* record = store_.findByMarxId(marxId);
    if (record) {
        MODEL::messages::ReplaceOrderReject clientRej = msg;
        clientRej.setClientOrderId(MODEL::fields::ClientOrderId(record->cdmOrder.getClientOrderId().toString()));
        
        Session* client = registry_.lookup(record->sessionId);
        if (client) {
            client->routeCDM(clientRej);
        }
    }
}

void Router::routeFromVenue(const MODEL::messages::CancelOrderExecution& msg) {
    lifecycleEngine_.processCancelExecution(msg);
    
    std::string clOrdId = msg.getClientOrderId().toString();
    std::string marxId = (clOrdId.size() > 2 && clOrdId.substr(clOrdId.size() - 2) == "_C")
                         ? clOrdId.substr(0, clOrdId.size() - 2)
                         : clOrdId;
    // For Cancel, the original client order ID can be derived from the target order
    OrderRecord* record = store_.findByMarxId(marxId);
    if (record) {
        MODEL::messages::CancelOrderExecution clientExec = msg;
        clientExec.setClientOrderId(MODEL::fields::ClientOrderId(store_.getOriginalClientOrderId(marxId)));
        
        Session* client = registry_.lookup(record->sessionId);
        if (client) {
            client->routeCDM(clientExec);
        }
    }
}

void Router::routeFromVenue(const MODEL::messages::CancelOrderReject& msg) {
    lifecycleEngine_.processCancelReject(msg);
    
    std::string clOrdId = msg.getClientOrderId().toString();
    std::string marxId = (clOrdId.size() > 2 && clOrdId.substr(clOrdId.size() - 2) == "_C")
                         ? clOrdId.substr(0, clOrdId.size() - 2)
                         : clOrdId;
    OrderRecord* record = store_.findByMarxId(marxId);
    if (record) {
        MODEL::messages::CancelOrderReject clientRej = msg;
        clientRej.setClientOrderId(MODEL::fields::ClientOrderId(store_.getOriginalClientOrderId(marxId)));
        
        Session* client = registry_.lookup(record->sessionId);
        if (client) {
            client->routeCDM(clientRej);
        }
    }
}

void Router::routeFromVenue(const MODEL::messages::FillOrderExecution& msg) {
    lifecycleEngine_.processFillExecution(msg);
    
    std::string marxId = msg.getClientOrderId().toString();
    OrderRecord* record = store_.findByMarxId(marxId);
    if (record) {
        MODEL::messages::FillOrderExecution clientExec = msg;
        clientExec.setClientOrderId(MODEL::fields::ClientOrderId(store_.getOriginalClientOrderId(marxId)));
        
        Session* client = registry_.lookup(record->sessionId);
        if (client) {
            client->routeCDM(clientExec);
        }
    }
}

} // namespace marx
