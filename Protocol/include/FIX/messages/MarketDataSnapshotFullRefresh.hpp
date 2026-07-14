// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class MarketDataSnapshotFullRefresh {
public:
    MarketDataSnapshotFullRefresh() = default;

    const FIX::fields::Symbol& getSymbol() const { return symbol_; }
    void setSymbol(const FIX::fields::Symbol& v) { symbol_ = v; }
    const FIX::fields::SecurityID& getSecurityID() const { return securityID_; }
    void setSecurityID(const FIX::fields::SecurityID& v) { securityID_ = v; }
    const FIX::fields::NoMDEntries& getNoMDEntries() const { return noMDEntries_; }
    void setNoMDEntries(const FIX::fields::NoMDEntries& v) { noMDEntries_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads MarketDataSnapshotFullRefresh::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "Symbol", true },
        { "SecurityID", false },
        { "NoMDEntries", true },
    };

private:
    FIX::fields::Symbol symbol_;
    FIX::fields::SecurityID securityID_;
    FIX::fields::NoMDEntries noMDEntries_;
};

} // namespace FIX::messages