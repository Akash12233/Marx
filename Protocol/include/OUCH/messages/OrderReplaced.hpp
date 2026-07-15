// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "OUCH/fields/Fields.hpp"

namespace OUCH::messages {

class OrderReplaced {
public:
    OrderReplaced() = default;

    const OUCH::fields::Timestamp& getTimestamp() const { return timestamp_; }
    void setTimestamp(const OUCH::fields::Timestamp& v) { timestamp_ = v; }
    const OUCH::fields::OriginalUserRefNum& getOriginalUserRefNum() const { return originalUserRefNum_; }
    void setOriginalUserRefNum(const OUCH::fields::OriginalUserRefNum& v) { originalUserRefNum_ = v; }
    const OUCH::fields::ReplacementUserRefNum& getReplacementUserRefNum() const { return replacementUserRefNum_; }
    void setReplacementUserRefNum(const OUCH::fields::ReplacementUserRefNum& v) { replacementUserRefNum_ = v; }
    const OUCH::fields::OrderReferenceNumber& getOrderReferenceNumber() const { return orderReferenceNumber_; }
    void setOrderReferenceNumber(const OUCH::fields::OrderReferenceNumber& v) { orderReferenceNumber_ = v; }
    const OUCH::fields::Quantity& getQuantity() const { return quantity_; }
    void setQuantity(const OUCH::fields::Quantity& v) { quantity_ = v; }
    const OUCH::fields::Price& getPrice() const { return price_; }
    void setPrice(const OUCH::fields::Price& v) { price_ = v; }
    const OUCH::fields::OrderState& getOrderState() const { return orderState_; }
    void setOrderState(const OUCH::fields::OrderState& v) { orderState_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads OrderReplaced::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "Timestamp", false },
        { "OriginalUserRefNum", false },
        { "ReplacementUserRefNum", false },
        { "OrderReferenceNumber", false },
        { "Quantity", false },
        { "Price", false },
        { "OrderState", false },
    };

private:
    OUCH::fields::Timestamp timestamp_;
    OUCH::fields::OriginalUserRefNum originalUserRefNum_;
    OUCH::fields::ReplacementUserRefNum replacementUserRefNum_;
    OUCH::fields::OrderReferenceNumber orderReferenceNumber_;
    OUCH::fields::Quantity quantity_;
    OUCH::fields::Price price_;
    OUCH::fields::OrderState orderState_;
};

} // namespace OUCH::messages