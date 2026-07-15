// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "OUCH/fields/Fields.hpp"

namespace OUCH::messages {

class OrderAccepted {
public:
    OrderAccepted() = default;

    const OUCH::fields::Timestamp& getTimestamp() const { return timestamp_; }
    void setTimestamp(const OUCH::fields::Timestamp& v) { timestamp_ = v; }
    const OUCH::fields::UserRefNum& getUserRefNum() const { return userRefNum_; }
    void setUserRefNum(const OUCH::fields::UserRefNum& v) { userRefNum_ = v; }
    const OUCH::fields::OrderReferenceNumber& getOrderReferenceNumber() const { return orderReferenceNumber_; }
    void setOrderReferenceNumber(const OUCH::fields::OrderReferenceNumber& v) { orderReferenceNumber_ = v; }
    const OUCH::fields::Side& getSide() const { return side_; }
    void setSide(const OUCH::fields::Side& v) { side_ = v; }
    const OUCH::fields::Symbol& getSymbol() const { return symbol_; }
    void setSymbol(const OUCH::fields::Symbol& v) { symbol_ = v; }
    const OUCH::fields::Quantity& getQuantity() const { return quantity_; }
    void setQuantity(const OUCH::fields::Quantity& v) { quantity_ = v; }
    const OUCH::fields::Price& getPrice() const { return price_; }
    void setPrice(const OUCH::fields::Price& v) { price_ = v; }
    const OUCH::fields::TimeInForce& getTimeInForce() const { return timeInForce_; }
    void setTimeInForce(const OUCH::fields::TimeInForce& v) { timeInForce_ = v; }
    const OUCH::fields::Display& getDisplay() const { return display_; }
    void setDisplay(const OUCH::fields::Display& v) { display_ = v; }
    const OUCH::fields::OrderState& getOrderState() const { return orderState_; }
    void setOrderState(const OUCH::fields::OrderState& v) { orderState_ = v; }
    const OUCH::fields::ClOrdID& getClOrdID() const { return clOrdID_; }
    void setClOrdID(const OUCH::fields::ClOrdID& v) { clOrdID_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads OrderAccepted::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "Timestamp", false },
        { "UserRefNum", false },
        { "OrderReferenceNumber", false },
        { "Side", false },
        { "Symbol", false },
        { "Quantity", false },
        { "Price", false },
        { "TimeInForce", false },
        { "Display", false },
        { "OrderState", false },
        { "ClOrdID", false },
    };

private:
    OUCH::fields::Timestamp timestamp_;
    OUCH::fields::UserRefNum userRefNum_;
    OUCH::fields::OrderReferenceNumber orderReferenceNumber_;
    OUCH::fields::Side side_;
    OUCH::fields::Symbol symbol_;
    OUCH::fields::Quantity quantity_;
    OUCH::fields::Price price_;
    OUCH::fields::TimeInForce timeInForce_;
    OUCH::fields::Display display_;
    OUCH::fields::OrderState orderState_;
    OUCH::fields::ClOrdID clOrdID_;
};

} // namespace OUCH::messages