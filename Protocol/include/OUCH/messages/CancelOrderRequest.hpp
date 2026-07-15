// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "OUCH/fields/Fields.hpp"

namespace OUCH::messages {

class CancelOrderRequest {
public:
    CancelOrderRequest() = default;

    const OUCH::fields::UserRefNum& getUserRefNum() const { return userRefNum_; }
    void setUserRefNum(const OUCH::fields::UserRefNum& v) { userRefNum_ = v; }
    const OUCH::fields::Quantity& getQuantity() const { return quantity_; }
    void setQuantity(const OUCH::fields::Quantity& v) { quantity_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads CancelOrderRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "UserRefNum", false },
        { "Quantity", false },
    };

private:
    OUCH::fields::UserRefNum userRefNum_;
    OUCH::fields::Quantity quantity_;
};

} // namespace OUCH::messages