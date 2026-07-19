#pragma once

#include "routing/EndpointRegistry.h"
#include "routing/OrderLifecycleEngine.h"
#include "MODEL/messages/NewOrderRequest.hpp"
#include "MODEL/messages/ReplaceOrderRequest.hpp"
#include "MODEL/messages/CancelOrderRequest.hpp"
#include "MODEL/messages/CreateOrderExecution.hpp"
#include "MODEL/messages/CreateOrderReject.hpp"
#include "MODEL/messages/ReplaceOrderExecution.hpp"
#include "MODEL/messages/ReplaceOrderReject.hpp"
#include "MODEL/messages/CancelOrderExecution.hpp"
#include "MODEL/messages/CancelOrderReject.hpp"
#include "MODEL/messages/FillOrderExecution.hpp"

#include <string>

namespace marx {

class Router {
public:
    Router(EndpointRegistry& registry, OrderLifecycleEngine& engine, OrderStore& store);

    // Callbacks to register destination sessions
    void setVenueSessionId(const std::string& sessionId) { venueSessionId_ = sessionId; }

    // Client requests
    void routeFromClient(const std::string& sessionId, const MODEL::messages::NewOrderRequest& msg);
    void routeFromClient(const std::string& sessionId, const MODEL::messages::ReplaceOrderRequest& msg);
    void routeFromClient(const std::string& sessionId, const MODEL::messages::CancelOrderRequest& msg);

    // Venue executions
    void routeFromVenue(const MODEL::messages::CreateOrderExecution& msg);
    void routeFromVenue(const MODEL::messages::CreateOrderReject& msg);
    void routeFromVenue(const MODEL::messages::ReplaceOrderExecution& msg);
    void routeFromVenue(const MODEL::messages::ReplaceOrderReject& msg);
    void routeFromVenue(const MODEL::messages::CancelOrderExecution& msg);
    void routeFromVenue(const MODEL::messages::CancelOrderReject& msg);
    void routeFromVenue(const MODEL::messages::FillOrderExecution& msg);

private:
    EndpointRegistry& registry_;
    OrderLifecycleEngine& lifecycleEngine_;
    OrderStore& store_;
    
    std::string venueSessionId_;
};

} // namespace marx
