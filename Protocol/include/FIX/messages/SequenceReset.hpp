// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class SequenceReset {
public:
    SequenceReset() = default;

    const FIX::fields::GapFillFlag& getGapFillFlag() const { return gapFillFlag_; }
    void setGapFillFlag(const FIX::fields::GapFillFlag& v) { gapFillFlag_ = v; }
    const FIX::fields::NewSeqNo& getNewSeqNo() const { return newSeqNo_; }
    void setNewSeqNo(const FIX::fields::NewSeqNo& v) { newSeqNo_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads SequenceReset::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "GapFillFlag", false },
        { "NewSeqNo", true },
    };

private:
    FIX::fields::GapFillFlag gapFillFlag_;
    FIX::fields::NewSeqNo newSeqNo_;
};

} // namespace FIX::messages