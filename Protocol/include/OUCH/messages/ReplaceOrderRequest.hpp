// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "OUCH/fields/Fields.hpp"

namespace OUCH::messages {

class ReplaceOrderRequest {
public:
    ReplaceOrderRequest() = default;

    const OUCH::fields::ExistingUserRefNum& getExistingUserRefNum() const { return existingUserRefNum_; }
    void setExistingUserRefNum(const OUCH::fields::ExistingUserRefNum& v) { existingUserRefNum_ = v; }
    const OUCH::fields::ReplacementUserRefNum& getReplacementUserRefNum() const { return replacementUserRefNum_; }
    void setReplacementUserRefNum(const OUCH::fields::ReplacementUserRefNum& v) { replacementUserRefNum_ = v; }
    const OUCH::fields::Quantity& getQuantity() const { return quantity_; }
    void setQuantity(const OUCH::fields::Quantity& v) { quantity_ = v; }
    const OUCH::fields::Price& getPrice() const { return price_; }
    void setPrice(const OUCH::fields::Price& v) { price_ = v; }
    const OUCH::fields::TimeInForce& getTimeInForce() const { return timeInForce_; }
    void setTimeInForce(const OUCH::fields::TimeInForce& v) { timeInForce_ = v; }
    const OUCH::fields::Display& getDisplay() const { return display_; }
    void setDisplay(const OUCH::fields::Display& v) { display_ = v; }
    const OUCH::fields::IntermarketSweepEligibility& getIntermarketSweepEligibility() const { return intermarketSweepEligibility_; }
    void setIntermarketSweepEligibility(const OUCH::fields::IntermarketSweepEligibility& v) { intermarketSweepEligibility_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads ReplaceOrderRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "ExistingUserRefNum", false },
        { "ReplacementUserRefNum", false },
        { "Quantity", false },
        { "Price", false },
        { "TimeInForce", false },
        { "Display", false },
        { "IntermarketSweepEligibility", false },
    };

private:
    OUCH::fields::ExistingUserRefNum existingUserRefNum_;
    OUCH::fields::ReplacementUserRefNum replacementUserRefNum_;
    OUCH::fields::Quantity quantity_;
    OUCH::fields::Price price_;
    OUCH::fields::TimeInForce timeInForce_;
    OUCH::fields::Display display_;
    OUCH::fields::IntermarketSweepEligibility intermarketSweepEligibility_;
};

} // namespace OUCH::messages