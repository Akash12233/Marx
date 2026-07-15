// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "OUCH/fields/Fields.hpp"

namespace OUCH::messages {

class OrderCanceled {
public:
    OrderCanceled() = default;

    const OUCH::fields::Timestamp& getTimestamp() const { return timestamp_; }
    void setTimestamp(const OUCH::fields::Timestamp& v) { timestamp_ = v; }
    const OUCH::fields::UserRefNum& getUserRefNum() const { return userRefNum_; }
    void setUserRefNum(const OUCH::fields::UserRefNum& v) { userRefNum_ = v; }
    const OUCH::fields::CanceledQuantity& getCanceledQuantity() const { return canceledQuantity_; }
    void setCanceledQuantity(const OUCH::fields::CanceledQuantity& v) { canceledQuantity_ = v; }
    const OUCH::fields::RemainingQuantity& getRemainingQuantity() const { return remainingQuantity_; }
    void setRemainingQuantity(const OUCH::fields::RemainingQuantity& v) { remainingQuantity_ = v; }
    const OUCH::fields::Reason& getReason() const { return reason_; }
    void setReason(const OUCH::fields::Reason& v) { reason_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads OrderCanceled::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "Timestamp", false },
        { "UserRefNum", false },
        { "CanceledQuantity", false },
        { "RemainingQuantity", false },
        { "Reason", false },
    };

private:
    OUCH::fields::Timestamp timestamp_;
    OUCH::fields::UserRefNum userRefNum_;
    OUCH::fields::CanceledQuantity canceledQuantity_;
    OUCH::fields::RemainingQuantity remainingQuantity_;
    OUCH::fields::Reason reason_;
};

} // namespace OUCH::messages