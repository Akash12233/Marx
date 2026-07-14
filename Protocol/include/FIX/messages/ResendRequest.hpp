// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class ResendRequest {
public:
    ResendRequest() = default;

    const FIX::fields::BeginSeqNo& getBeginSeqNo() const { return beginSeqNo_; }
    void setBeginSeqNo(const FIX::fields::BeginSeqNo& v) { beginSeqNo_ = v; }
    const FIX::fields::EndSeqNo& getEndSeqNo() const { return endSeqNo_; }
    void setEndSeqNo(const FIX::fields::EndSeqNo& v) { endSeqNo_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads ResendRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "BeginSeqNo", true },
        { "EndSeqNo", true },
    };

private:
    FIX::fields::BeginSeqNo beginSeqNo_;
    FIX::fields::EndSeqNo endSeqNo_;
};

} // namespace FIX::messages