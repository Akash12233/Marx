// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class MarketDataRequest {
public:
    MarketDataRequest() = default;

    const FIX::fields::MDReqID& getMDReqID() const { return mDReqID_; }
    void setMDReqID(const FIX::fields::MDReqID& v) { mDReqID_ = v; }
    const FIX::fields::SubscriptionRequestType& getSubscriptionRequestType() const { return subscriptionRequestType_; }
    void setSubscriptionRequestType(const FIX::fields::SubscriptionRequestType& v) { subscriptionRequestType_ = v; }
    const FIX::fields::MarketDepth& getMarketDepth() const { return marketDepth_; }
    void setMarketDepth(const FIX::fields::MarketDepth& v) { marketDepth_ = v; }
    const FIX::fields::MDUpdateType& getMDUpdateType() const { return mDUpdateType_; }
    void setMDUpdateType(const FIX::fields::MDUpdateType& v) { mDUpdateType_ = v; }
    const FIX::fields::NoMDEntryTypes& getNoMDEntryTypes() const { return noMDEntryTypes_; }
    void setNoMDEntryTypes(const FIX::fields::NoMDEntryTypes& v) { noMDEntryTypes_ = v; }
    const FIX::fields::NoRelatedSym& getNoRelatedSym() const { return noRelatedSym_; }
    void setNoRelatedSym(const FIX::fields::NoRelatedSym& v) { noRelatedSym_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads MarketDataRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "MDReqID", true },
        { "SubscriptionRequestType", true },
        { "MarketDepth", true },
        { "MDUpdateType", false },
        { "NoMDEntryTypes", true },
        { "NoRelatedSym", true },
    };

private:
    FIX::fields::MDReqID mDReqID_;
    FIX::fields::SubscriptionRequestType subscriptionRequestType_;
    FIX::fields::MarketDepth marketDepth_;
    FIX::fields::MDUpdateType mDUpdateType_;
    FIX::fields::NoMDEntryTypes noMDEntryTypes_;
    FIX::fields::NoRelatedSym noRelatedSym_;
};

} // namespace FIX::messages