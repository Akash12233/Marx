// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "OUCH/fields/Fields.hpp"

namespace OUCH::messages {

class OrderExecuted {
public:
    OrderExecuted() = default;

    const OUCH::fields::Timestamp& getTimestamp() const { return timestamp_; }
    void setTimestamp(const OUCH::fields::Timestamp& v) { timestamp_ = v; }
    const OUCH::fields::UserRefNum& getUserRefNum() const { return userRefNum_; }
    void setUserRefNum(const OUCH::fields::UserRefNum& v) { userRefNum_ = v; }
    const OUCH::fields::ExecutedQuantity& getExecutedQuantity() const { return executedQuantity_; }
    void setExecutedQuantity(const OUCH::fields::ExecutedQuantity& v) { executedQuantity_ = v; }
    const OUCH::fields::Price& getPrice() const { return price_; }
    void setPrice(const OUCH::fields::Price& v) { price_ = v; }
    const OUCH::fields::LiquidityFlag& getLiquidityFlag() const { return liquidityFlag_; }
    void setLiquidityFlag(const OUCH::fields::LiquidityFlag& v) { liquidityFlag_ = v; }
    const OUCH::fields::MatchNumber& getMatchNumber() const { return matchNumber_; }
    void setMatchNumber(const OUCH::fields::MatchNumber& v) { matchNumber_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads OrderExecuted::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "Timestamp", false },
        { "UserRefNum", false },
        { "ExecutedQuantity", false },
        { "Price", false },
        { "LiquidityFlag", false },
        { "MatchNumber", false },
    };

private:
    OUCH::fields::Timestamp timestamp_;
    OUCH::fields::UserRefNum userRefNum_;
    OUCH::fields::ExecutedQuantity executedQuantity_;
    OUCH::fields::Price price_;
    OUCH::fields::LiquidityFlag liquidityFlag_;
    OUCH::fields::MatchNumber matchNumber_;
};

} // namespace OUCH::messages