// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "MODEL/fields/Fields.hpp"

namespace MODEL::messages {

class Order {
public:
    Order() = default;

    const MODEL::fields::ClientOrderId& getClientOrderId() const { return clientOrderId_; }
    void setClientOrderId(const MODEL::fields::ClientOrderId& v) { clientOrderId_ = v; }
    const MODEL::fields::VenueOrderId& getVenueOrderId() const { return venueOrderId_; }
    void setVenueOrderId(const MODEL::fields::VenueOrderId& v) { venueOrderId_ = v; }
    const MODEL::fields::ParentOrderId& getParentOrderId() const { return parentOrderId_; }
    void setParentOrderId(const MODEL::fields::ParentOrderId& v) { parentOrderId_ = v; }
    const MODEL::fields::ExecutionId& getExecutionId() const { return executionId_; }
    void setExecutionId(const MODEL::fields::ExecutionId& v) { executionId_ = v; }
    const MODEL::fields::Account& getAccount() const { return account_; }
    void setAccount(const MODEL::fields::Account& v) { account_ = v; }
    const MODEL::fields::ClientId& getClientId() const { return clientId_; }
    void setClientId(const MODEL::fields::ClientId& v) { clientId_ = v; }
    const MODEL::fields::Symbol& getSymbol() const { return symbol_; }
    void setSymbol(const MODEL::fields::Symbol& v) { symbol_ = v; }
    const MODEL::fields::SecurityId& getSecurityId() const { return securityId_; }
    void setSecurityId(const MODEL::fields::SecurityId& v) { securityId_ = v; }
    const MODEL::fields::Exchange& getExchange() const { return exchange_; }
    void setExchange(const MODEL::fields::Exchange& v) { exchange_ = v; }
    const MODEL::fields::Currency& getCurrency() const { return currency_; }
    void setCurrency(const MODEL::fields::Currency& v) { currency_ = v; }
    const MODEL::fields::Side& getSide() const { return side_; }
    void setSide(const MODEL::fields::Side& v) { side_ = v; }
    const MODEL::fields::OrderType& getOrderType() const { return orderType_; }
    void setOrderType(const MODEL::fields::OrderType& v) { orderType_ = v; }
    const MODEL::fields::TimeInForce& getTimeInForce() const { return timeInForce_; }
    void setTimeInForce(const MODEL::fields::TimeInForce& v) { timeInForce_ = v; }
    const MODEL::fields::OrderQty& getOrderQty() const { return orderQty_; }
    void setOrderQty(const MODEL::fields::OrderQty& v) { orderQty_ = v; }
    const MODEL::fields::Price& getPrice() const { return price_; }
    void setPrice(const MODEL::fields::Price& v) { price_ = v; }
    const MODEL::fields::StopPrice& getStopPrice() const { return stopPrice_; }
    void setStopPrice(const MODEL::fields::StopPrice& v) { stopPrice_ = v; }
    const MODEL::fields::OrderStatus& getOrderStatus() const { return orderStatus_; }
    void setOrderStatus(const MODEL::fields::OrderStatus& v) { orderStatus_ = v; }
    const MODEL::fields::ExecutionType& getExecutionType() const { return executionType_; }
    void setExecutionType(const MODEL::fields::ExecutionType& v) { executionType_ = v; }
    const MODEL::fields::CumQty& getCumQty() const { return cumQty_; }
    void setCumQty(const MODEL::fields::CumQty& v) { cumQty_ = v; }
    const MODEL::fields::LeavesQty& getLeavesQty() const { return leavesQty_; }
    void setLeavesQty(const MODEL::fields::LeavesQty& v) { leavesQty_ = v; }
    const MODEL::fields::FilledQuantity& getFilledQuantity() const { return filledQuantity_; }
    void setFilledQuantity(const MODEL::fields::FilledQuantity& v) { filledQuantity_ = v; }
    const MODEL::fields::RemainingQuantity& getRemainingQuantity() const { return remainingQuantity_; }
    void setRemainingQuantity(const MODEL::fields::RemainingQuantity& v) { remainingQuantity_ = v; }
    const MODEL::fields::AveragePrice& getAveragePrice() const { return averagePrice_; }
    void setAveragePrice(const MODEL::fields::AveragePrice& v) { averagePrice_ = v; }
    const MODEL::fields::LastFillQuantity& getLastFillQuantity() const { return lastFillQuantity_; }
    void setLastFillQuantity(const MODEL::fields::LastFillQuantity& v) { lastFillQuantity_ = v; }
    const MODEL::fields::LastFillPrice& getLastFillPrice() const { return lastFillPrice_; }
    void setLastFillPrice(const MODEL::fields::LastFillPrice& v) { lastFillPrice_ = v; }
    const MODEL::fields::CreatedTime& getCreatedTime() const { return createdTime_; }
    void setCreatedTime(const MODEL::fields::CreatedTime& v) { createdTime_ = v; }
    const MODEL::fields::TransactTime& getTransactTime() const { return transactTime_; }
    void setTransactTime(const MODEL::fields::TransactTime& v) { transactTime_ = v; }
    const MODEL::fields::VenueTime& getVenueTime() const { return venueTime_; }
    void setVenueTime(const MODEL::fields::VenueTime& v) { venueTime_ = v; }
    const MODEL::fields::Text& getText() const { return text_; }
    void setText(const MODEL::fields::Text& v) { text_ = v; }
    const MODEL::fields::RejectReason& getRejectReason() const { return rejectReason_; }
    void setRejectReason(const MODEL::fields::RejectReason& v) { rejectReason_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads Order::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "ClientOrderId", false },
        { "VenueOrderId", false },
        { "ParentOrderId", false },
        { "ExecutionId", false },
        { "Account", false },
        { "ClientId", false },
        { "Symbol", false },
        { "SecurityId", false },
        { "Exchange", false },
        { "Currency", false },
        { "Side", false },
        { "OrderType", false },
        { "TimeInForce", false },
        { "OrderQty", false },
        { "Price", false },
        { "StopPrice", false },
        { "OrderStatus", false },
        { "ExecutionType", false },
        { "CumQty", false },
        { "LeavesQty", false },
        { "FilledQuantity", false },
        { "RemainingQuantity", false },
        { "AveragePrice", false },
        { "LastFillQuantity", false },
        { "LastFillPrice", false },
        { "CreatedTime", false },
        { "TransactTime", false },
        { "VenueTime", false },
        { "Text", false },
        { "RejectReason", false },
    };

private:
    MODEL::fields::ClientOrderId clientOrderId_;
    MODEL::fields::VenueOrderId venueOrderId_;
    MODEL::fields::ParentOrderId parentOrderId_;
    MODEL::fields::ExecutionId executionId_;
    MODEL::fields::Account account_;
    MODEL::fields::ClientId clientId_;
    MODEL::fields::Symbol symbol_;
    MODEL::fields::SecurityId securityId_;
    MODEL::fields::Exchange exchange_;
    MODEL::fields::Currency currency_;
    MODEL::fields::Side side_;
    MODEL::fields::OrderType orderType_;
    MODEL::fields::TimeInForce timeInForce_;
    MODEL::fields::OrderQty orderQty_;
    MODEL::fields::Price price_;
    MODEL::fields::StopPrice stopPrice_;
    MODEL::fields::OrderStatus orderStatus_;
    MODEL::fields::ExecutionType executionType_;
    MODEL::fields::CumQty cumQty_;
    MODEL::fields::LeavesQty leavesQty_;
    MODEL::fields::FilledQuantity filledQuantity_;
    MODEL::fields::RemainingQuantity remainingQuantity_;
    MODEL::fields::AveragePrice averagePrice_;
    MODEL::fields::LastFillQuantity lastFillQuantity_;
    MODEL::fields::LastFillPrice lastFillPrice_;
    MODEL::fields::CreatedTime createdTime_;
    MODEL::fields::TransactTime transactTime_;
    MODEL::fields::VenueTime venueTime_;
    MODEL::fields::Text text_;
    MODEL::fields::RejectReason rejectReason_;
};

} // namespace MODEL::messages