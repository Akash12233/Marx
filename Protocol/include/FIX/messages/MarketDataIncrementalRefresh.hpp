// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class MarketDataIncrementalRefresh {
public:
    MarketDataIncrementalRefresh() = default;

    const FIX::fields::MDReqID& getMDReqID() const { return mDReqID_; }
    void setMDReqID(const FIX::fields::MDReqID& v) { mDReqID_ = v; }
    const FIX::fields::NoMDEntries& getNoMDEntries() const { return noMDEntries_; }
    void setNoMDEntries(const FIX::fields::NoMDEntries& v) { noMDEntries_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads MarketDataIncrementalRefresh::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "MDReqID", false },
        { "NoMDEntries", true },
    };

private:
    FIX::fields::MDReqID mDReqID_;
    FIX::fields::NoMDEntries noMDEntries_;
};

} // namespace FIX::messages