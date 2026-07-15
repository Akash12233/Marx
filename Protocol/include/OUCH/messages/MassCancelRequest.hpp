// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "OUCH/fields/Fields.hpp"

namespace OUCH::messages {

class MassCancelRequest {
public:
    MassCancelRequest() = default;

    const OUCH::fields::Scope& getScope() const { return scope_; }
    void setScope(const OUCH::fields::Scope& v) { scope_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads MassCancelRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "Scope", false },
    };

private:
    OUCH::fields::Scope scope_;
};

} // namespace OUCH::messages