// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "MODEL/fields/Fields.hpp"

namespace MODEL::messages {

class ReplaceOrderRequest {
public:
    ReplaceOrderRequest() = default;

    const MODEL::fields::ClientOrderId& getClientOrderId() const { return clientOrderId_; }
    void setClientOrderId(const MODEL::fields::ClientOrderId& v) { clientOrderId_ = v; }
    const MODEL::fields::OriginalClientOrderId& getOriginalClientOrderId() const { return originalClientOrderId_; }
    void setOriginalClientOrderId(const MODEL::fields::OriginalClientOrderId& v) { originalClientOrderId_ = v; }
    const MODEL::fields::OrderQty& getOrderQty() const { return orderQty_; }
    void setOrderQty(const MODEL::fields::OrderQty& v) { orderQty_ = v; }
    const MODEL::fields::Price& getPrice() const { return price_; }
    void setPrice(const MODEL::fields::Price& v) { price_ = v; }
    const MODEL::fields::StopPrice& getStopPrice() const { return stopPrice_; }
    void setStopPrice(const MODEL::fields::StopPrice& v) { stopPrice_ = v; }
    const MODEL::fields::TimeInForce& getTimeInForce() const { return timeInForce_; }
    void setTimeInForce(const MODEL::fields::TimeInForce& v) { timeInForce_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads ReplaceOrderRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "ClientOrderId", false },
        { "OriginalClientOrderId", false },
        { "OrderQty", false },
        { "Price", false },
        { "StopPrice", false },
        { "TimeInForce", false },
    };

private:
    MODEL::fields::ClientOrderId clientOrderId_;
    MODEL::fields::OriginalClientOrderId originalClientOrderId_;
    MODEL::fields::OrderQty orderQty_;
    MODEL::fields::Price price_;
    MODEL::fields::StopPrice stopPrice_;
    MODEL::fields::TimeInForce timeInForce_;
};

} // namespace MODEL::messages