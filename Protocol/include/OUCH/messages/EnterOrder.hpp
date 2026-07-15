// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "OUCH/fields/Fields.hpp"

namespace OUCH::messages {

class EnterOrder {
public:
    EnterOrder() = default;

    const OUCH::fields::UserRefNum& getUserRefNum() const { return userRefNum_; }
    void setUserRefNum(const OUCH::fields::UserRefNum& v) { userRefNum_ = v; }
    const OUCH::fields::Side& getSide() const { return side_; }
    void setSide(const OUCH::fields::Side& v) { side_ = v; }
    const OUCH::fields::Quantity& getQuantity() const { return quantity_; }
    void setQuantity(const OUCH::fields::Quantity& v) { quantity_ = v; }
    const OUCH::fields::Symbol& getSymbol() const { return symbol_; }
    void setSymbol(const OUCH::fields::Symbol& v) { symbol_ = v; }
    const OUCH::fields::Price& getPrice() const { return price_; }
    void setPrice(const OUCH::fields::Price& v) { price_ = v; }
    const OUCH::fields::TimeInForce& getTimeInForce() const { return timeInForce_; }
    void setTimeInForce(const OUCH::fields::TimeInForce& v) { timeInForce_ = v; }
    const OUCH::fields::Display& getDisplay() const { return display_; }
    void setDisplay(const OUCH::fields::Display& v) { display_ = v; }
    const OUCH::fields::Capacity& getCapacity() const { return capacity_; }
    void setCapacity(const OUCH::fields::Capacity& v) { capacity_ = v; }
    const OUCH::fields::IntermarketSweepEligibility& getIntermarketSweepEligibility() const { return intermarketSweepEligibility_; }
    void setIntermarketSweepEligibility(const OUCH::fields::IntermarketSweepEligibility& v) { intermarketSweepEligibility_ = v; }
    const OUCH::fields::CrossType& getCrossType() const { return crossType_; }
    void setCrossType(const OUCH::fields::CrossType& v) { crossType_ = v; }
    const OUCH::fields::ClOrdID& getClOrdID() const { return clOrdID_; }
    void setClOrdID(const OUCH::fields::ClOrdID& v) { clOrdID_ = v; }
    const OUCH::fields::Firm& getFirm() const { return firm_; }
    void setFirm(const OUCH::fields::Firm& v) { firm_ = v; }
    const OUCH::fields::MinQty& getMinQty() const { return minQty_; }
    void setMinQty(const OUCH::fields::MinQty& v) { minQty_ = v; }
    const OUCH::fields::MaxFloor& getMaxFloor() const { return maxFloor_; }
    void setMaxFloor(const OUCH::fields::MaxFloor& v) { maxFloor_ = v; }
    const OUCH::fields::PegOffset& getPegOffset() const { return pegOffset_; }
    void setPegOffset(const OUCH::fields::PegOffset& v) { pegOffset_ = v; }
    const OUCH::fields::ExpireTime& getExpireTime() const { return expireTime_; }
    void setExpireTime(const OUCH::fields::ExpireTime& v) { expireTime_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads EnterOrder::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "UserRefNum", false },
        { "Side", false },
        { "Quantity", false },
        { "Symbol", false },
        { "Price", false },
        { "TimeInForce", false },
        { "Display", false },
        { "Capacity", false },
        { "IntermarketSweepEligibility", false },
        { "CrossType", false },
        { "ClOrdID", false },
        { "Firm", false },
        { "MinQty", false },
        { "MaxFloor", false },
        { "PegOffset", false },
        { "ExpireTime", false },
    };

private:
    OUCH::fields::UserRefNum userRefNum_;
    OUCH::fields::Side side_;
    OUCH::fields::Quantity quantity_;
    OUCH::fields::Symbol symbol_;
    OUCH::fields::Price price_;
    OUCH::fields::TimeInForce timeInForce_;
    OUCH::fields::Display display_;
    OUCH::fields::Capacity capacity_;
    OUCH::fields::IntermarketSweepEligibility intermarketSweepEligibility_;
    OUCH::fields::CrossType crossType_;
    OUCH::fields::ClOrdID clOrdID_;
    OUCH::fields::Firm firm_;
    OUCH::fields::MinQty minQty_;
    OUCH::fields::MaxFloor maxFloor_;
    OUCH::fields::PegOffset pegOffset_;
    OUCH::fields::ExpireTime expireTime_;
};

} // namespace OUCH::messages