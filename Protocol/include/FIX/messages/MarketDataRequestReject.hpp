// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class MarketDataRequestReject {
public:
    MarketDataRequestReject() = default;

    const FIX::fields::MDReqID& getMDReqID() const { return mDReqID_; }
    void setMDReqID(const FIX::fields::MDReqID& v) { mDReqID_ = v; }
    const FIX::fields::Text& getText() const { return text_; }
    void setText(const FIX::fields::Text& v) { text_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads MarketDataRequestReject::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "MDReqID", true },
        { "Text", false },
    };

private:
    FIX::fields::MDReqID mDReqID_;
    FIX::fields::Text text_;
};

} // namespace FIX::messages