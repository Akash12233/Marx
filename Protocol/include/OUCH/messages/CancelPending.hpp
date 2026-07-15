// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "OUCH/fields/Fields.hpp"

namespace OUCH::messages {

class CancelPending {
public:
    CancelPending() = default;

    const OUCH::fields::Timestamp& getTimestamp() const { return timestamp_; }
    void setTimestamp(const OUCH::fields::Timestamp& v) { timestamp_ = v; }
    const OUCH::fields::UserRefNum& getUserRefNum() const { return userRefNum_; }
    void setUserRefNum(const OUCH::fields::UserRefNum& v) { userRefNum_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads CancelPending::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "Timestamp", false },
        { "UserRefNum", false },
    };

private:
    OUCH::fields::Timestamp timestamp_;
    OUCH::fields::UserRefNum userRefNum_;
};

} // namespace OUCH::messages