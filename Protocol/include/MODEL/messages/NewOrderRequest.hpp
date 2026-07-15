// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "MODEL/fields/Fields.hpp"

namespace MODEL::messages {

class NewOrderRequest {
public:
    NewOrderRequest() = default;

    const MODEL::fields::ClientOrderId& getClientOrderId() const { return clientOrderId_; }
    void setClientOrderId(const MODEL::fields::ClientOrderId& v) { clientOrderId_ = v; }
    const MODEL::fields::Account& getAccount() const { return account_; }
    void setAccount(const MODEL::fields::Account& v) { account_ = v; }
    const MODEL::fields::Symbol& getSymbol() const { return symbol_; }
    void setSymbol(const MODEL::fields::Symbol& v) { symbol_ = v; }
    const MODEL::fields::Side& getSide() const { return side_; }
    void setSide(const MODEL::fields::Side& v) { side_ = v; }
    const MODEL::fields::OrderType& getOrderType() const { return orderType_; }
    void setOrderType(const MODEL::fields::OrderType& v) { orderType_ = v; }
    const MODEL::fields::OrderQty& getOrderQty() const { return orderQty_; }
    void setOrderQty(const MODEL::fields::OrderQty& v) { orderQty_ = v; }
    const MODEL::fields::TimeInForce& getTimeInForce() const { return timeInForce_; }
    void setTimeInForce(const MODEL::fields::TimeInForce& v) { timeInForce_ = v; }
    const MODEL::fields::TransactTime& getTransactTime() const { return transactTime_; }
    void setTransactTime(const MODEL::fields::TransactTime& v) { transactTime_ = v; }
    const MODEL::fields::Price& getPrice() const { return price_; }
    void setPrice(const MODEL::fields::Price& v) { price_ = v; }
    const MODEL::fields::StopPrice& getStopPrice() const { return stopPrice_; }
    void setStopPrice(const MODEL::fields::StopPrice& v) { stopPrice_ = v; }
    const MODEL::fields::ExecutionInstruction& getExecutionInstruction() const { return executionInstruction_; }
    void setExecutionInstruction(const MODEL::fields::ExecutionInstruction& v) { executionInstruction_ = v; }
    const MODEL::fields::Currency& getCurrency() const { return currency_; }
    void setCurrency(const MODEL::fields::Currency& v) { currency_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads NewOrderRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "ClientOrderId", false },
        { "Account", false },
        { "Symbol", false },
        { "Side", false },
        { "OrderType", false },
        { "OrderQty", false },
        { "TimeInForce", false },
        { "TransactTime", false },
        { "Price", false },
        { "StopPrice", false },
        { "ExecutionInstruction", false },
        { "Currency", false },
    };

private:
    MODEL::fields::ClientOrderId clientOrderId_;
    MODEL::fields::Account account_;
    MODEL::fields::Symbol symbol_;
    MODEL::fields::Side side_;
    MODEL::fields::OrderType orderType_;
    MODEL::fields::OrderQty orderQty_;
    MODEL::fields::TimeInForce timeInForce_;
    MODEL::fields::TransactTime transactTime_;
    MODEL::fields::Price price_;
    MODEL::fields::StopPrice stopPrice_;
    MODEL::fields::ExecutionInstruction executionInstruction_;
    MODEL::fields::Currency currency_;
};

} // namespace MODEL::messages