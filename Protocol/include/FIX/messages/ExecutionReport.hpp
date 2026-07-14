// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class ExecutionReport {
public:
    ExecutionReport() = default;

    const FIX::fields::OrderID& getOrderID() const { return orderID_; }
    void setOrderID(const FIX::fields::OrderID& v) { orderID_ = v; }
    const FIX::fields::ClOrdID& getClOrdID() const { return clOrdID_; }
    void setClOrdID(const FIX::fields::ClOrdID& v) { clOrdID_ = v; }
    const FIX::fields::OrigClOrdID& getOrigClOrdID() const { return origClOrdID_; }
    void setOrigClOrdID(const FIX::fields::OrigClOrdID& v) { origClOrdID_ = v; }
    const FIX::fields::ExecID& getExecID() const { return execID_; }
    void setExecID(const FIX::fields::ExecID& v) { execID_ = v; }
    const FIX::fields::ExecType& getExecType() const { return execType_; }
    void setExecType(const FIX::fields::ExecType& v) { execType_ = v; }
    const FIX::fields::OrdStatus& getOrdStatus() const { return ordStatus_; }
    void setOrdStatus(const FIX::fields::OrdStatus& v) { ordStatus_ = v; }
    const FIX::fields::OrdRejReason& getOrdRejReason() const { return ordRejReason_; }
    void setOrdRejReason(const FIX::fields::OrdRejReason& v) { ordRejReason_ = v; }
    const FIX::fields::Symbol& getSymbol() const { return symbol_; }
    void setSymbol(const FIX::fields::Symbol& v) { symbol_ = v; }
    const FIX::fields::Side& getSide() const { return side_; }
    void setSide(const FIX::fields::Side& v) { side_ = v; }
    const FIX::fields::OrderQty& getOrderQty() const { return orderQty_; }
    void setOrderQty(const FIX::fields::OrderQty& v) { orderQty_ = v; }
    const FIX::fields::LeavesQty& getLeavesQty() const { return leavesQty_; }
    void setLeavesQty(const FIX::fields::LeavesQty& v) { leavesQty_ = v; }
    const FIX::fields::CumQty& getCumQty() const { return cumQty_; }
    void setCumQty(const FIX::fields::CumQty& v) { cumQty_ = v; }
    const FIX::fields::LastQty& getLastQty() const { return lastQty_; }
    void setLastQty(const FIX::fields::LastQty& v) { lastQty_ = v; }
    const FIX::fields::LastPx& getLastPx() const { return lastPx_; }
    void setLastPx(const FIX::fields::LastPx& v) { lastPx_ = v; }
    const FIX::fields::AvgPx& getAvgPx() const { return avgPx_; }
    void setAvgPx(const FIX::fields::AvgPx& v) { avgPx_ = v; }
    const FIX::fields::Price& getPrice() const { return price_; }
    void setPrice(const FIX::fields::Price& v) { price_ = v; }
    const FIX::fields::TransactTime& getTransactTime() const { return transactTime_; }
    void setTransactTime(const FIX::fields::TransactTime& v) { transactTime_ = v; }
    const FIX::fields::Text& getText() const { return text_; }
    void setText(const FIX::fields::Text& v) { text_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads ExecutionReport::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "OrderID", true },
        { "ClOrdID", false },
        { "OrigClOrdID", false },
        { "ExecID", true },
        { "ExecType", true },
        { "OrdStatus", true },
        { "OrdRejReason", false },
        { "Symbol", true },
        { "Side", true },
        { "OrderQty", false },
        { "LeavesQty", true },
        { "CumQty", true },
        { "LastQty", false },
        { "LastPx", false },
        { "AvgPx", true },
        { "Price", false },
        { "TransactTime", false },
        { "Text", false },
    };

private:
    FIX::fields::OrderID orderID_;
    FIX::fields::ClOrdID clOrdID_;
    FIX::fields::OrigClOrdID origClOrdID_;
    FIX::fields::ExecID execID_;
    FIX::fields::ExecType execType_;
    FIX::fields::OrdStatus ordStatus_;
    FIX::fields::OrdRejReason ordRejReason_;
    FIX::fields::Symbol symbol_;
    FIX::fields::Side side_;
    FIX::fields::OrderQty orderQty_;
    FIX::fields::LeavesQty leavesQty_;
    FIX::fields::CumQty cumQty_;
    FIX::fields::LastQty lastQty_;
    FIX::fields::LastPx lastPx_;
    FIX::fields::AvgPx avgPx_;
    FIX::fields::Price price_;
    FIX::fields::TransactTime transactTime_;
    FIX::fields::Text text_;
};

} // namespace FIX::messages