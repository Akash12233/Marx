// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class Heartbeat {
public:
    Heartbeat() = default;

    const FIX::fields::TestReqID& getTestReqID() const { return testReqID_; }
    void setTestReqID(const FIX::fields::TestReqID& v) { testReqID_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads Heartbeat::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "TestReqID", false },
    };

private:
    FIX::fields::TestReqID testReqID_;
};

} // namespace FIX::messages