// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class OrderCancelRequest {
public:
    OrderCancelRequest() = default;

    const FIX::fields::OrigClOrdID& getOrigClOrdID() const { return origClOrdID_; }
    void setOrigClOrdID(const FIX::fields::OrigClOrdID& v) { origClOrdID_ = v; }
    const FIX::fields::ClOrdID& getClOrdID() const { return clOrdID_; }
    void setClOrdID(const FIX::fields::ClOrdID& v) { clOrdID_ = v; }
    const FIX::fields::Symbol& getSymbol() const { return symbol_; }
    void setSymbol(const FIX::fields::Symbol& v) { symbol_ = v; }
    const FIX::fields::Side& getSide() const { return side_; }
    void setSide(const FIX::fields::Side& v) { side_ = v; }
    const FIX::fields::TransactTime& getTransactTime() const { return transactTime_; }
    void setTransactTime(const FIX::fields::TransactTime& v) { transactTime_ = v; }
    const FIX::fields::OrderQty& getOrderQty() const { return orderQty_; }
    void setOrderQty(const FIX::fields::OrderQty& v) { orderQty_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads OrderCancelRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "OrigClOrdID", true },
        { "ClOrdID", true },
        { "Symbol", true },
        { "Side", true },
        { "TransactTime", true },
        { "OrderQty", false },
    };

private:
    FIX::fields::OrigClOrdID origClOrdID_;
    FIX::fields::ClOrdID clOrdID_;
    FIX::fields::Symbol symbol_;
    FIX::fields::Side side_;
    FIX::fields::TransactTime transactTime_;
    FIX::fields::OrderQty orderQty_;
};

} // namespace FIX::messages