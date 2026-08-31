# Marx Execution Management System (EMS)

Marx is a low-latency, multi-protocol **Execution Management System (EMS)** designed to interface clients with financial venues. It provides an abstract, unified connection foundation supporting **FIX** and **OUCH** protocols, routing messages through a central **Common Data Model (CDM)** layer.

---

## 1. Project Importance & Key Advantages
- **Low-Latency Architecture**: Built using C++20, utilizing memory-efficient structures, zero-copy patterns where possible, and minimal allocations.
- **Dedicated Thread Isolation**: Every network session operates on its own dedicated `asio::io_context` running in a separate background thread, isolating network I/O from core processing.
- **Git-Like Order Version Chaining**: To model order replacements (cancels/replaces) robustly, `OrderStore` tracks modifications as a linked commit tree. This guarantees consistency and deterministic state recovery during exchange cancels or rejects.
- **O(1) Operational Mappings**: Lookups are performed in constant time using bi-directional hash indexes mapping `ClientOrderID`, `VenueOrderID`, and `ExecutionID` to internal `MARXID`s.
- **Code Generation Pipeline**: Message payloads, fields, and enumerations are automatically generated from XML schemas (`FIX`, `OUCH`, `MODEL`) using a Python/Jinja2 template generator, ensuring type safety and single-source-of-truth schemas.

---

## 2. High-Level Architecture & Directory Structure

### Architecture Flow Diagram
```mermaid
                                +-------------------+
                                |    Client Layer   |
                                +---------+---------+
                                          | (FIX/OUCH)
                                          ▼
                                +---------+---------+
                                |  Client Sessions  |
                                +---------+---------+
                                          |
                                          | [Client -> CDM Conversion]
                                          ▼
                                +---------+---------+
                                |      Router       |
                                +---------+---------+
                                          |
                                          | [Process & Validate]
                                          ▼
                                +---------+---------+
                                |  LifecycleEngine  |
                                +---------+---------+
                                          |
                                          | [Query & Mutate]
                                          ▼
                                +---------+---------+
                                |    OrderStore     |
                                +---------+---------+
                                          |
                                          | [CDM Outbound Dispatch]
                                          ▼
                                +---------+---------+
                                |   Venue Session   |
                                +---------+---------+
                                          | (FIX/OUCH)
                                          ▼
                                +---------+---------+
                                |    Venue Layer    |
                                +-------------------+
```

### Directory Tree & Component Layout
```text
Marx/
├── CMakeLists.txt              # Root CMake configuration
├── main.cpp                    # Entrance point
├── Protocol/                   # Protocol Schema & Generator
│   ├── generator/              # Python generator scripts and templates
│   ├── schema/                 # XML schemas (FIX, OUCH, MODEL)
│   └── include/                # Generated protocol header files
└── EqtMarketGW/                # Equity Market Gateway implementation
    ├── gateway.conf            # Session and network config
    ├── include/                # Gateways headers
    │   ├── abstract/           # Network & session base interfaces
    │   ├── client/             # Client inbound session layers (FIX)
    │   ├── venue/              # Venue outbound session layers (OUCH)
    │   ├── protocol/           # Encoder, decoder & translation logic
    │   └── routing/            # Router, Order Store, Lifecycle Engine
    └── src/                    # Source files implementing gateways
```

---

## 3. Protocol Specifications & Schema Numbers

### Schema Tag Ranges
- **Common Data Model (MODEL)**: Tags `10001` to `10056`
- **OUCH Protocol**: Tags `20001` to `20032`
- **FIX Protocol**: Tags standard tag identifiers (e.g. `8`, `9`, `35`, `49`, `56`, `34`, `52`, `11`, `38`, `44`, etc.)

### Message Definitions (Inbound & Outbound)

#### OUCH Protocol Messages
- **Client to Exchange**:
  - `EnterOrder` (UserRefNum, Side, Quantity, Symbol, Price, TimeInForce, Display, Capacity, ClOrdID, Firm, MinQty, MaxFloor, PegOffset, ExpireTime)
  - `ReplaceOrderRequest` (ExistingUserRefNum, ReplacementUserRefNum, Quantity, Price, TimeInForce, Display, IntermarketSweepEligibility)
  - `CancelOrderRequest` (UserRefNum, Quantity)
  - `ModifyOrderRequest` (UserRefNum, Price, Display, TimeInForce)
  - `MassCancelRequest` (Scope)
  - `AccountQueryRequest` (Account)
- **Exchange to Client**:
  - `SystemEvent` (Timestamp, EventCode)
  - `OrderAccepted` (Timestamp, UserRefNum, OrderReferenceNumber, Side, Symbol, Quantity, Price, TimeInForce, Display, OrderState, ClOrdID)
  - `OrderReplaced` (Timestamp, OriginalUserRefNum, ReplacementUserRefNum, OrderReferenceNumber, Quantity, Price, OrderState)
  - `OrderCanceled` (Timestamp, UserRefNum, CanceledQuantity, RemainingQuantity, Reason)
  - `OrderExecuted` (Timestamp, UserRefNum, ExecutedQuantity, Price, LiquidityFlag, MatchNumber)
  - `BrokenTrade` (Timestamp, UserRefNum, MatchNumber, Reason)
  - `Rejected` (Timestamp, UserRefNum, Reason, ClOrdID)
  - `CancelPending` (Timestamp, UserRefNum)

#### FIX Protocol Messages
- **Session/Administrative**: `Logon` (A), `Logout` (5), `Heartbeat` (0), `TestRequest` (1), `ResendRequest` (2), `SequenceReset` (4), `Reject` (3)
- **Application**: `NewOrderSingle` (D), `OrderCancelRequest` (F), `OrderCancelReplaceRequest` (G), `OrderStatusRequest` (H), `ExecutionReport` (8), `OrderCancelReject` (9)

---

## 4. Operational Order Store & State Engine

The `OrderStore` maintains the active state of every order and its modifications.

### Git-Like Commit Version Chains
When replacing an order, rather than mutating the original order in-place, Marx creates a new child version of the order linked to its parent:

```text
    [Original Order]                 [Replaced Order]
       (MX000001)                       (MX000002)
   ┌────────────────┐               ┌────────────────┐
   │ ClOrdID: CL_01 │               │ ClOrdID: CL_02 │
   │ Status: REPLACED               │ Status: NEW    │
   │ successor: MX02├──────────────>│ parent: MX01   │
   └────────────────┘               └────────────────┘
```

- **Outbound Replace**: The parent order is kept as active.
- **Execution Accept**: When the exchange accepts the replace, the parent order's status transitions to `REPLACED` and `LeavesQty` goes to `0`. The child order's status transitions to `NEW` (or the status specified by the exchange) and inherits the running totals.
- **State Recovery on Reject**: If the cancel/replace is rejected by the exchange, the child order is marked as `REJECTED`, and the parent order is restored to its previous active status (e.g. `NEW` or `PARTIALLY_FILLED`), cleanly rolling back the state.

### Multi-Index Mapping (O(1) Complexity)
To route messages back and forth instantaneously, three core lookups are kept in memory:
1. `ClientOrderID -> MARXID`: Identifies the internal sequence from client IDs.
2. `VenueOrderID -> MARXID`: Identifies orders using exchange-assigned IDs.
3. `ExecutionID -> MARXID`: Filters out duplicate trades/fills.

---

## 5. Message Lifecycle Handlers & State Flow

Each transaction message type transitions the order record states deterministically.

### 5.1. New Order Request (`NewOrderRequest` -> `OrderAccepted`/`Rejected`)
1. **Validation & Creation**: `OrderLifecycleEngine::processNewOrder` validates the incoming payload (verifying quantity > 0, price > 0, and non-empty symbol).
   - *If invalid*: An internal `CreateOrderReject` is returned immediately.
   - *If valid*: `OrderStore::createOrder` instantiates an `OrderRecord` with status `Pending New` (value `'A'`), sets `LeavesQty = OrderQty` and `CumQty = 0`, and saves the record.
2. **Outbound Routing**: The message is mapped to the venue protocol format (e.g. FIX `NewOrderSingle` or OUCH `EnterOrder`) and dispatched to the exchange.
3. **Execution Response**:
   - **Acceptance**: When the venue responds with `OrderAccepted` or equivalent, `OrderStore::acceptOrder` changes the state to `New` (value `'0'`), registers the exchange-assigned `VenueOrderId`, and creates the index mapping from `VenueOrderID` to `MARXID`.
   - **Rejection**: If the venue responds with a `Rejected` execution, `OrderStore::rejectOrder` updates the state to `Rejected` (value `'8'`), drops `LeavesQty` to `0`, and records the rejection reason.

### 5.2. Replace Order Request (`ReplaceOrderRequest` -> `OrderReplaced`/`ReplaceOrderReject`)
1. **Validation & Creation**: `OrderLifecycleEngine::processReplaceRequest` finds the parent order via `findByClientOrderId` and ensures it is in a replaceable state (`New` or `PartiallyFilled`).
   - *If invalid*: Returns a `ReplaceOrderReject` mapping to FIX `OrderCancelReject`.
   - *If valid*: `OrderStore::replaceOrder` creates a new child `OrderRecord`, links its `parentMarxId` to the parent order, links the parent's `successorMarxId` to the child's `marxId`, and initializes the child order status to `Pending Replace` (value `'E'`).
2. **Outbound Routing**: The replace is mapped to OUCH `ReplaceOrderRequest` or FIX `OrderCancelReplaceRequest` and dispatched.
3. **Execution Response**:
   - **Acceptance**: When the venue returns `OrderReplaced`, `OrderStore::acceptReplace` sets the child status to `New` (value `'0'`), sets the parent status to `Replaced` (value `'5'`), zero-out parent's `LeavesQty`, and propagates accumulated execution stats (`CumQty` and `AveragePrice`) and `VenueOrderId` from parent to child.
   - **Rejection**: If rejected, `OrderStore::rejectReplace` sets child status to `Rejected` (value `'8'`), drops child `LeavesQty` to `0`, and clears the parent's `successorMarxId` link, returning the parent order back as the active node in the state tree.

### 5.3. Cancel Order Request (`CancelOrderRequest` -> `OrderCanceled`/`CancelOrderReject`)
1. **Validation**: `OrderLifecycleEngine::processCancelRequest` locates the target order and confirms it is in a cancelable state.
   - *If invalid*: Returns a `CancelOrderReject`.
   - *If valid*: `OrderStore::cancelOrder` stores the current order status into `previousStatus` and transitions the order state to `Pending Cancel` (value `'6'`).
2. **Outbound Routing**: Sent to the venue as OUCH `CancelOrderRequest` or FIX `OrderCancelRequest`.
3. **Execution Response**:
   - **Acceptance**: When `OrderCanceled` is received, `OrderStore::acceptCancel` sets the state to `Canceled` (value `'4'`) and zeros out the `LeavesQty`.
   - **Rejection**: If rejected, `OrderStore::rejectCancel` restores the status of the order back to `previousStatus`.

---

## 6. Structural Code Specifications

Below is the C++ structural implementation of the core structures.


### Order Store Structures ([OrderStore.h](file:///home/akash/projects/Marx/EqtMarketGW/include/routing/OrderStore.h))
```cpp
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
```

### Base Session Interface ([Session.h](file:///home/akash/projects/Marx/EqtMarketGW/include/abstract/Session.h))
```cpp
#pragma once

#include "abstract/SessionContext.h"
#include "abstract/ConnectionState.h"
#include "abstract/Statistics.h"
#include <memory>
#include <string>

namespace marx {

class Session {
public:
    explicit Session(const SessionContext& context);
    virtual ~Session() = default;

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual bool isConnected() const = 0;

    const std::string& getSessionId() const { return context_.sessionId; }
    const SessionContext& getContext() const { return context_; }
    const Statistics& getStatistics() const { return stats_; }

protected:
    SessionContext context_;
    Statistics stats_;
};

} // namespace marx
```

### Routing Interface ([Router.h](file:///home/akash/projects/Marx/EqtMarketGW/include/routing/Router.h))
```cpp
#pragma once

#include "routing/OrderStore.h"
#include "routing/OrderLifecycleEngine.h"
#include "routing/EndpointRegistry.h"
#include "MODEL/messages/NewOrderRequest.hpp"
#include "MODEL/messages/ReplaceOrderRequest.hpp"
#include "MODEL/messages/CancelOrderRequest.hpp"

namespace marx {

class Router {
public:
    Router(OrderStore& store, OrderLifecycleEngine& engine, EndpointRegistry& registry);

    // From Inbound (Client Session -> Router)
    void routeFromClient(const std::string& sessionId, const MODEL::messages::NewOrderRequest& cdmReq);
    void routeFromClient(const std::string& sessionId, const MODEL::messages::ReplaceOrderRequest& cdmReq);
    void routeFromClient(const std::string& sessionId, const MODEL::messages::CancelOrderRequest& cdmReq);

    // From Outbound (Venue Session -> Router)
    void routeFromVenue(const std::string& sessionId, const MODEL::messages::CreateOrderExecution& cdmExec);
    void routeFromVenue(const std::string& sessionId, const MODEL::messages::CreateOrderReject& cdmRej);
    void routeFromVenue(const std::string& sessionId, const MODEL::messages::ReplaceOrderExecution& cdmExec);
    void routeFromVenue(const std::string& sessionId, const MODEL::messages::ReplaceOrderReject& cdmRej);
    void routeFromVenue(const std::string& sessionId, const MODEL::messages::CancelOrderExecution& cdmExec);
    void routeFromVenue(const std::string& sessionId, const MODEL::messages::CancelOrderReject& cdmRej);
    void routeFromVenue(const std::string& sessionId, const MODEL::messages::FillOrderExecution& cdmExec);

private:
    OrderStore& store_;
    OrderLifecycleEngine& engine_;
    EndpointRegistry& registry_;
};

} // namespace marx
```
