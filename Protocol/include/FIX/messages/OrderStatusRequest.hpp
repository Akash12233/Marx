// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class OrderStatusRequest {
public:
    OrderStatusRequest() = default;

    const FIX::fields::ClOrdID& getClOrdID() const { return clOrdID_; }
    void setClOrdID(const FIX::fields::ClOrdID& v) { clOrdID_ = v; }
    const FIX::fields::OrderID& getOrderID() const { return orderID_; }
    void setOrderID(const FIX::fields::OrderID& v) { orderID_ = v; }
    const FIX::fields::Symbol& getSymbol() const { return symbol_; }
    void setSymbol(const FIX::fields::Symbol& v) { symbol_ = v; }
    const FIX::fields::Side& getSide() const { return side_; }
    void setSide(const FIX::fields::Side& v) { side_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads OrderStatusRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "ClOrdID", false },
        { "OrderID", false },
        { "Symbol", true },
        { "Side", true },
    };

private:
    FIX::fields::ClOrdID clOrdID_;
    FIX::fields::OrderID orderID_;
    FIX::fields::Symbol symbol_;
    FIX::fields::Side side_;
};

} // namespace FIX::messages