// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class OrderCancelReject {
public:
    OrderCancelReject() = default;

    const FIX::fields::OrderID& getOrderID() const { return orderID_; }
    void setOrderID(const FIX::fields::OrderID& v) { orderID_ = v; }
    const FIX::fields::ClOrdID& getClOrdID() const { return clOrdID_; }
    void setClOrdID(const FIX::fields::ClOrdID& v) { clOrdID_ = v; }
    const FIX::fields::OrigClOrdID& getOrigClOrdID() const { return origClOrdID_; }
    void setOrigClOrdID(const FIX::fields::OrigClOrdID& v) { origClOrdID_ = v; }
    const FIX::fields::OrdStatus& getOrdStatus() const { return ordStatus_; }
    void setOrdStatus(const FIX::fields::OrdStatus& v) { ordStatus_ = v; }
    const FIX::fields::Text& getText() const { return text_; }
    void setText(const FIX::fields::Text& v) { text_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads OrderCancelReject::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "OrderID", true },
        { "ClOrdID", true },
        { "OrigClOrdID", false },
        { "OrdStatus", true },
        { "Text", false },
    };

private:
    FIX::fields::OrderID orderID_;
    FIX::fields::ClOrdID clOrdID_;
    FIX::fields::OrigClOrdID origClOrdID_;
    FIX::fields::OrdStatus ordStatus_;
    FIX::fields::Text text_;
};

} // namespace FIX::messages