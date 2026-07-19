#pragma once

#include "routing/OrderStore.h"
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

#include <variant>
#include <string>

namespace marx {

class OrderLifecycleEngine {
public:
    explicit OrderLifecycleEngine(OrderStore& store);

    // Incoming messages from client (requesting transitions)
    std::variant<OrderRecord*, MODEL::messages::CreateOrderReject>
    processNewOrder(const MODEL::messages::NewOrderRequest& req, const std::string& sessionId);

    std::variant<OrderRecord*, MODEL::messages::ReplaceOrderReject>
    processReplaceRequest(const MODEL::messages::ReplaceOrderRequest& req);

    std::variant<std::string, MODEL::messages::CancelOrderReject>
    processCancelRequest(const MODEL::messages::CancelOrderRequest& req);

    // Incoming execution reports from venue
    void processCreateExecution(const MODEL::messages::CreateOrderExecution& exec);
    void processCreateReject(const MODEL::messages::CreateOrderReject& rej);
    
    void processReplaceExecution(const MODEL::messages::ReplaceOrderExecution& exec);
    void processReplaceReject(const MODEL::messages::ReplaceOrderReject& rej);
    
    void processCancelExecution(const MODEL::messages::CancelOrderExecution& exec);
    void processCancelReject(const MODEL::messages::CancelOrderReject& rej);
    
    void processFillExecution(const MODEL::messages::FillOrderExecution& exec);

private:
    OrderStore& store_;
};

} // namespace marx
