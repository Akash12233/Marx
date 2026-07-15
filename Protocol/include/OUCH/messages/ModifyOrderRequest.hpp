// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "OUCH/fields/Fields.hpp"

namespace OUCH::messages {

class ModifyOrderRequest {
public:
    ModifyOrderRequest() = default;

    const OUCH::fields::UserRefNum& getUserRefNum() const { return userRefNum_; }
    void setUserRefNum(const OUCH::fields::UserRefNum& v) { userRefNum_ = v; }
    const OUCH::fields::Price& getPrice() const { return price_; }
    void setPrice(const OUCH::fields::Price& v) { price_ = v; }
    const OUCH::fields::Display& getDisplay() const { return display_; }
    void setDisplay(const OUCH::fields::Display& v) { display_ = v; }
    const OUCH::fields::TimeInForce& getTimeInForce() const { return timeInForce_; }
    void setTimeInForce(const OUCH::fields::TimeInForce& v) { timeInForce_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads ModifyOrderRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "UserRefNum", false },
        { "Price", false },
        { "Display", false },
        { "TimeInForce", false },
    };

private:
    OUCH::fields::UserRefNum userRefNum_;
    OUCH::fields::Price price_;
    OUCH::fields::Display display_;
    OUCH::fields::TimeInForce timeInForce_;
};

} // namespace OUCH::messages