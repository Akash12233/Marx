// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from fields.xml by protocol/generator/generate.py
#pragma once

#include <cstdint>
#include <string>

#include "FIX/enumerations/Enumerations.hpp"

namespace FIX::fields {

namespace detail {
    // Trims leading/trailing whitespace - used by toString() on fixed-width
    // style string fields. toStringData() returns the untrimmed original.
    inline std::string trim(const std::string& s) {
        const auto start = s.find_first_not_of(" \t\n\r");
        if (start == std::string::npos) return "";
        const auto end = s.find_last_not_of(" \t\n\r");
        return s.substr(start, end - start + 1);
    }
}
class BeginString {
public:
    BeginString() = default;
    explicit BeginString(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class BodyLength {
public:
    BodyLength() = default;
    explicit BodyLength(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class MsgType {
public:
    MsgType() = default;
    explicit MsgType(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class SenderCompID {
public:
    SenderCompID() = default;
    explicit SenderCompID(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class TargetCompID {
public:
    TargetCompID() = default;
    explicit TargetCompID(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class MsgSeqNum {
public:
    MsgSeqNum() = default;
    explicit MsgSeqNum(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class SendingTime {
public:
    SendingTime() = default;
    explicit SendingTime(std::int64_t v) : value_(v) {}
    std::int64_t get() const { return value_; }
    void set(std::int64_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int64_t value_{};
};
class PossDupFlag {
public:
    PossDupFlag() = default;
    explicit PossDupFlag(bool v) : value_(v) {}
    bool get() const { return value_; }
    void set(bool v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    bool value_{};
};
class PossResend {
public:
    PossResend() = default;
    explicit PossResend(bool v) : value_(v) {}
    bool get() const { return value_; }
    void set(bool v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    bool value_{};
};
class OrigSendingTime {
public:
    OrigSendingTime() = default;
    explicit OrigSendingTime(std::int64_t v) : value_(v) {}
    std::int64_t get() const { return value_; }
    void set(std::int64_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int64_t value_{};
};
class CheckSum {
public:
    CheckSum() = default;
    explicit CheckSum(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class EncryptMethod {
public:
    EncryptMethod() = default;
    explicit EncryptMethod(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class HeartBtInt {
public:
    HeartBtInt() = default;
    explicit HeartBtInt(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class ResetSeqNumFlag {
public:
    ResetSeqNumFlag() = default;
    explicit ResetSeqNumFlag(bool v) : value_(v) {}
    bool get() const { return value_; }
    void set(bool v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    bool value_{};
};
class TestReqID {
public:
    TestReqID() = default;
    explicit TestReqID(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class BeginSeqNo {
public:
    BeginSeqNo() = default;
    explicit BeginSeqNo(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class EndSeqNo {
public:
    EndSeqNo() = default;
    explicit EndSeqNo(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class NewSeqNo {
public:
    NewSeqNo() = default;
    explicit NewSeqNo(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class RefSeqNum {
public:
    RefSeqNum() = default;
    explicit RefSeqNum(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class Text {
public:
    Text() = default;
    explicit Text(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class ClOrdID {
public:
    ClOrdID() = default;
    explicit ClOrdID(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class OrigClOrdID {
public:
    OrigClOrdID() = default;
    explicit OrigClOrdID(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class OrderID {
public:
    OrderID() = default;
    explicit OrderID(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class ExecID {
public:
    ExecID() = default;
    explicit ExecID(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class Account {
public:
    Account() = default;
    explicit Account(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class Side {
public:
    Side() = default;
    explicit Side(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    FIX::enumerations::Side value() const {
        return FIX::enumerations::Side::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class OrdType {
public:
    OrdType() = default;
    explicit OrdType(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    FIX::enumerations::OrdType value() const {
        return FIX::enumerations::OrdType::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class OrdStatus {
public:
    OrdStatus() = default;
    explicit OrdStatus(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    FIX::enumerations::OrdStatus value() const {
        return FIX::enumerations::OrdStatus::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class ExecType {
public:
    ExecType() = default;
    explicit ExecType(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    FIX::enumerations::ExecType value() const {
        return FIX::enumerations::ExecType::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class TimeInForce {
public:
    TimeInForce() = default;
    explicit TimeInForce(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    FIX::enumerations::TimeInForce value() const {
        return FIX::enumerations::TimeInForce::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class OrderQty {
public:
    OrderQty() = default;
    explicit OrderQty(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class LeavesQty {
public:
    LeavesQty() = default;
    explicit LeavesQty(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class CumQty {
public:
    CumQty() = default;
    explicit CumQty(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class LastQty {
public:
    LastQty() = default;
    explicit LastQty(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class Price {
public:
    Price() = default;
    explicit Price(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class StopPx {
public:
    StopPx() = default;
    explicit StopPx(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class AvgPx {
public:
    AvgPx() = default;
    explicit AvgPx(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class LastPx {
public:
    LastPx() = default;
    explicit LastPx(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class TransactTime {
public:
    TransactTime() = default;
    explicit TransactTime(std::int64_t v) : value_(v) {}
    std::int64_t get() const { return value_; }
    void set(std::int64_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int64_t value_{};
};
class Symbol {
public:
    Symbol() = default;
    explicit Symbol(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class SecurityID {
public:
    SecurityID() = default;
    explicit SecurityID(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class SecurityIDSource {
public:
    SecurityIDSource() = default;
    explicit SecurityIDSource(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class SecurityExchange {
public:
    SecurityExchange() = default;
    explicit SecurityExchange(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class SecurityType {
public:
    SecurityType() = default;
    explicit SecurityType(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class Currency {
public:
    Currency() = default;
    explicit Currency(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class ExecTransType {
public:
    ExecTransType() = default;
    explicit ExecTransType(char v) : value_(v) {}
    char get() const { return value_; }
    void set(char v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    char value_{};
};
class ExecRefID {
public:
    ExecRefID() = default;
    explicit ExecRefID(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class OrdRejReason {
public:
    OrdRejReason() = default;
    explicit OrdRejReason(int raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    int get() const { return value_; }
    void set(int raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    FIX::enumerations::OrdRejReason value() const {
        return FIX::enumerations::OrdRejReason::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::to_string(value_); }

private:
    int value_{};
};
class ExecRestatementReason {
public:
    ExecRestatementReason() = default;
    explicit ExecRestatementReason(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class ExecInst {
public:
    ExecInst() = default;
    explicit ExecInst(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    FIX::enumerations::ExecInst value() const {
        return FIX::enumerations::ExecInst::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class MDReqID {
public:
    MDReqID() = default;
    explicit MDReqID(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class SubscriptionRequestType {
public:
    SubscriptionRequestType() = default;
    explicit SubscriptionRequestType(char v) : value_(v) {}
    char get() const { return value_; }
    void set(char v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    char value_{};
};
class MarketDepth {
public:
    MarketDepth() = default;
    explicit MarketDepth(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class MDUpdateType {
public:
    MDUpdateType() = default;
    explicit MDUpdateType(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class NoMDEntryTypes {
public:
    NoMDEntryTypes() = default;
    explicit NoMDEntryTypes(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class NoMDEntries {
public:
    NoMDEntries() = default;
    explicit NoMDEntries(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class MDEntryType {
public:
    MDEntryType() = default;
    explicit MDEntryType(char v) : value_(v) {}
    char get() const { return value_; }
    void set(char v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    char value_{};
};
class MDEntryPx {
public:
    MDEntryPx() = default;
    explicit MDEntryPx(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class MDEntrySize {
public:
    MDEntrySize() = default;
    explicit MDEntrySize(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class MDEntryDate {
public:
    MDEntryDate() = default;
    explicit MDEntryDate(std::int32_t v) : value_(v) {}
    std::int32_t get() const { return value_; }
    void set(std::int32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int32_t value_{};
};
class MDEntryTime {
public:
    MDEntryTime() = default;
    explicit MDEntryTime(std::int64_t v) : value_(v) {}
    std::int64_t get() const { return value_; }
    void set(std::int64_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int64_t value_{};
};
class NoRelatedSym {
public:
    NoRelatedSym() = default;
    explicit NoRelatedSym(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class SessionRejectReason {
public:
    SessionRejectReason() = default;
    explicit SessionRejectReason(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class BusinessRejectReason {
public:
    BusinessRejectReason() = default;
    explicit BusinessRejectReason(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class BusinessRejectRefID {
public:
    BusinessRejectRefID() = default;
    explicit BusinessRejectRefID(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class RefTagID {
public:
    RefTagID() = default;
    explicit RefTagID(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class RefMsgType {
public:
    RefMsgType() = default;
    explicit RefMsgType(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class GapFillFlag {
public:
    GapFillFlag() = default;
    explicit GapFillFlag(bool v) : value_(v) {}
    bool get() const { return value_; }
    void set(bool v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    bool value_{};
};
class TradeDate {
public:
    TradeDate() = default;
    explicit TradeDate(std::int32_t v) : value_(v) {}
    std::int32_t get() const { return value_; }
    void set(std::int32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int32_t value_{};
};
class SettlDate {
public:
    SettlDate() = default;
    explicit SettlDate(std::int32_t v) : value_(v) {}
    std::int32_t get() const { return value_; }
    void set(std::int32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int32_t value_{};
};
class ExDestination {
public:
    ExDestination() = default;
    explicit ExDestination(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class HandlInst {
public:
    HandlInst() = default;
    explicit HandlInst(char v) : value_(v) {}
    char get() const { return value_; }
    void set(char v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    char value_{};
};
class ClientID {
public:
    ClientID() = default;
    explicit ClientID(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
} // namespace FIX::fields