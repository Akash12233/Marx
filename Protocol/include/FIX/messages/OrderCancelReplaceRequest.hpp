// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class OrderCancelReplaceRequest {
public:
    OrderCancelReplaceRequest() = default;

    const FIX::fields::OrigClOrdID& getOrigClOrdID() const { return origClOrdID_; }
    void setOrigClOrdID(const FIX::fields::OrigClOrdID& v) { origClOrdID_ = v; }
    const FIX::fields::ClOrdID& getClOrdID() const { return clOrdID_; }
    void setClOrdID(const FIX::fields::ClOrdID& v) { clOrdID_ = v; }
    const FIX::fields::Symbol& getSymbol() const { return symbol_; }
    void setSymbol(const FIX::fields::Symbol& v) { symbol_ = v; }
    const FIX::fields::Side& getSide() const { return side_; }
    void setSide(const FIX::fields::Side& v) { side_ = v; }
    const FIX::fields::TransactTime& getTransactTime() const { return transactTime_; }
    void setTransactTime(const FIX::fields::TransactTime& v) { transactTime_ = v; }
    const FIX::fields::OrdType& getOrdType() const { return ordType_; }
    void setOrdType(const FIX::fields::OrdType& v) { ordType_ = v; }
    const FIX::fields::OrderQty& getOrderQty() const { return orderQty_; }
    void setOrderQty(const FIX::fields::OrderQty& v) { orderQty_ = v; }
    const FIX::fields::Price& getPrice() const { return price_; }
    void setPrice(const FIX::fields::Price& v) { price_ = v; }
    const FIX::fields::StopPx& getStopPx() const { return stopPx_; }
    void setStopPx(const FIX::fields::StopPx& v) { stopPx_ = v; }
    const FIX::fields::TimeInForce& getTimeInForce() const { return timeInForce_; }
    void setTimeInForce(const FIX::fields::TimeInForce& v) { timeInForce_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads OrderCancelReplaceRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "OrigClOrdID", true },
        { "ClOrdID", true },
        { "Symbol", true },
        { "Side", true },
        { "TransactTime", true },
        { "OrdType", true },
        { "OrderQty", true },
        { "Price", false },
        { "StopPx", false },
        { "TimeInForce", false },
    };

private:
    FIX::fields::OrigClOrdID origClOrdID_;
    FIX::fields::ClOrdID clOrdID_;
    FIX::fields::Symbol symbol_;
    FIX::fields::Side side_;
    FIX::fields::TransactTime transactTime_;
    FIX::fields::OrdType ordType_;
    FIX::fields::OrderQty orderQty_;
    FIX::fields::Price price_;
    FIX::fields::StopPx stopPx_;
    FIX::fields::TimeInForce timeInForce_;
};

} // namespace FIX::messages