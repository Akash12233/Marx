// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "MODEL/fields/Fields.hpp"

namespace MODEL::messages {

class FillOrderExecution {
public:
    FillOrderExecution() = default;

    const MODEL::fields::ClientOrderId& getClientOrderId() const { return clientOrderId_; }
    void setClientOrderId(const MODEL::fields::ClientOrderId& v) { clientOrderId_ = v; }
    const MODEL::fields::VenueOrderId& getVenueOrderId() const { return venueOrderId_; }
    void setVenueOrderId(const MODEL::fields::VenueOrderId& v) { venueOrderId_ = v; }
    const MODEL::fields::ExecutionId& getExecutionId() const { return executionId_; }
    void setExecutionId(const MODEL::fields::ExecutionId& v) { executionId_ = v; }
    const MODEL::fields::ExecutionType& getExecutionType() const { return executionType_; }
    void setExecutionType(const MODEL::fields::ExecutionType& v) { executionType_ = v; }
    const MODEL::fields::OrderStatus& getOrderStatus() const { return orderStatus_; }
    void setOrderStatus(const MODEL::fields::OrderStatus& v) { orderStatus_ = v; }
    const MODEL::fields::LastFillQuantity& getLastFillQuantity() const { return lastFillQuantity_; }
    void setLastFillQuantity(const MODEL::fields::LastFillQuantity& v) { lastFillQuantity_ = v; }
    const MODEL::fields::LastFillPrice& getLastFillPrice() const { return lastFillPrice_; }
    void setLastFillPrice(const MODEL::fields::LastFillPrice& v) { lastFillPrice_ = v; }
    const MODEL::fields::CumQty& getCumQty() const { return cumQty_; }
    void setCumQty(const MODEL::fields::CumQty& v) { cumQty_ = v; }
    const MODEL::fields::LeavesQty& getLeavesQty() const { return leavesQty_; }
    void setLeavesQty(const MODEL::fields::LeavesQty& v) { leavesQty_ = v; }
    const MODEL::fields::AveragePrice& getAveragePrice() const { return averagePrice_; }
    void setAveragePrice(const MODEL::fields::AveragePrice& v) { averagePrice_ = v; }
    const MODEL::fields::TradeId& getTradeId() const { return tradeId_; }
    void setTradeId(const MODEL::fields::TradeId& v) { tradeId_ = v; }
    const MODEL::fields::TradeTime& getTradeTime() const { return tradeTime_; }
    void setTradeTime(const MODEL::fields::TradeTime& v) { tradeTime_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads FillOrderExecution::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "ClientOrderId", false },
        { "VenueOrderId", false },
        { "ExecutionId", false },
        { "ExecutionType", false },
        { "OrderStatus", false },
        { "LastFillQuantity", false },
        { "LastFillPrice", false },
        { "CumQty", false },
        { "LeavesQty", false },
        { "AveragePrice", false },
        { "TradeId", false },
        { "TradeTime", false },
    };

private:
    MODEL::fields::ClientOrderId clientOrderId_;
    MODEL::fields::VenueOrderId venueOrderId_;
    MODEL::fields::ExecutionId executionId_;
    MODEL::fields::ExecutionType executionType_;
    MODEL::fields::OrderStatus orderStatus_;
    MODEL::fields::LastFillQuantity lastFillQuantity_;
    MODEL::fields::LastFillPrice lastFillPrice_;
    MODEL::fields::CumQty cumQty_;
    MODEL::fields::LeavesQty leavesQty_;
    MODEL::fields::AveragePrice averagePrice_;
    MODEL::fields::TradeId tradeId_;
    MODEL::fields::TradeTime tradeTime_;
};

} // namespace MODEL::messages