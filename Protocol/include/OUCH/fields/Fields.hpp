// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from fields.xml by protocol/generator/generate.py
#pragma once

#include <cstdint>
#include <string>

#include "OUCH/enumerations/Enumerations.hpp"

namespace OUCH::fields {

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
class UserRefNum {
public:
    UserRefNum() = default;
    explicit UserRefNum(std::uint32_t v) : value_(v) {}
    std::uint32_t get() const { return value_; }
    void set(std::uint32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::uint32_t value_{};
};
class ExistingUserRefNum {
public:
    ExistingUserRefNum() = default;
    explicit ExistingUserRefNum(std::uint32_t v) : value_(v) {}
    std::uint32_t get() const { return value_; }
    void set(std::uint32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::uint32_t value_{};
};
class ReplacementUserRefNum {
public:
    ReplacementUserRefNum() = default;
    explicit ReplacementUserRefNum(std::uint32_t v) : value_(v) {}
    std::uint32_t get() const { return value_; }
    void set(std::uint32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::uint32_t value_{};
};
class OriginalUserRefNum {
public:
    OriginalUserRefNum() = default;
    explicit OriginalUserRefNum(std::uint32_t v) : value_(v) {}
    std::uint32_t get() const { return value_; }
    void set(std::uint32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::uint32_t value_{};
};
class OrderReferenceNumber {
public:
    OrderReferenceNumber() = default;
    explicit OrderReferenceNumber(std::uint64_t v) : value_(v) {}
    std::uint64_t get() const { return value_; }
    void set(std::uint64_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::uint64_t value_{};
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
class Side {
public:
    Side() = default;
    explicit Side(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    OUCH::enumerations::Side value() const {
        return OUCH::enumerations::Side::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class Quantity {
public:
    Quantity() = default;
    explicit Quantity(std::uint32_t v) : value_(v) {}
    std::uint32_t get() const { return value_; }
    void set(std::uint32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::uint32_t value_{};
};
class CanceledQuantity {
public:
    CanceledQuantity() = default;
    explicit CanceledQuantity(std::uint32_t v) : value_(v) {}
    std::uint32_t get() const { return value_; }
    void set(std::uint32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::uint32_t value_{};
};
class RemainingQuantity {
public:
    RemainingQuantity() = default;
    explicit RemainingQuantity(std::uint32_t v) : value_(v) {}
    std::uint32_t get() const { return value_; }
    void set(std::uint32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::uint32_t value_{};
};
class ExecutedQuantity {
public:
    ExecutedQuantity() = default;
    explicit ExecutedQuantity(std::uint32_t v) : value_(v) {}
    std::uint32_t get() const { return value_; }
    void set(std::uint32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::uint32_t value_{};
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
class TimeInForce {
public:
    TimeInForce() = default;
    explicit TimeInForce(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    OUCH::enumerations::TimeInForce value() const {
        return OUCH::enumerations::TimeInForce::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class Display {
public:
    Display() = default;
    explicit Display(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    OUCH::enumerations::Display value() const {
        return OUCH::enumerations::Display::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class Capacity {
public:
    Capacity() = default;
    explicit Capacity(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    OUCH::enumerations::Capacity value() const {
        return OUCH::enumerations::Capacity::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class IntermarketSweepEligibility {
public:
    IntermarketSweepEligibility() = default;
    explicit IntermarketSweepEligibility(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    OUCH::enumerations::IntermarketSweepEligibility value() const {
        return OUCH::enumerations::IntermarketSweepEligibility::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class CrossType {
public:
    CrossType() = default;
    explicit CrossType(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    OUCH::enumerations::CrossType value() const {
        return OUCH::enumerations::CrossType::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class MinQty {
public:
    MinQty() = default;
    explicit MinQty(std::uint32_t v) : value_(v) {}
    std::uint32_t get() const { return value_; }
    void set(std::uint32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::uint32_t value_{};
};
class MaxFloor {
public:
    MaxFloor() = default;
    explicit MaxFloor(std::uint32_t v) : value_(v) {}
    std::uint32_t get() const { return value_; }
    void set(std::uint32_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::uint32_t value_{};
};
class PegOffset {
public:
    PegOffset() = default;
    explicit PegOffset(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class ExpireTime {
public:
    ExpireTime() = default;
    explicit ExpireTime(std::int64_t v) : value_(v) {}
    std::int64_t get() const { return value_; }
    void set(std::int64_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int64_t value_{};
};
class Firm {
public:
    Firm() = default;
    explicit Firm(std::string v) : value_(std::move(v)) {}
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
class utcTimestamp {
public:
    utcTimestamp() = default;
    explicit utcTimestamp(std::int64_t v) : value_(v) {}
    std::int64_t get() const { return value_; }
    void set(std::int64_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int64_t value_{};
};
class OrderState {
public:
    OrderState() = default;
    explicit OrderState(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    OUCH::enumerations::OrderState value() const {
        return OUCH::enumerations::OrderState::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class LiquidityFlag {
public:
    LiquidityFlag() = default;
    explicit LiquidityFlag(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    OUCH::enumerations::LiquidityFlag value() const {
        return OUCH::enumerations::LiquidityFlag::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class MatchNumber {
public:
    MatchNumber() = default;
    explicit MatchNumber(std::uint64_t v) : value_(v) {}
    std::uint64_t get() const { return value_; }
    void set(std::uint64_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::uint64_t value_{};
};
class EventCode {
public:
    EventCode() = default;
    explicit EventCode(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    OUCH::enumerations::EventCode value() const {
        return OUCH::enumerations::EventCode::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class Reason {
public:
    Reason() = default;
    explicit Reason(int raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    int get() const { return value_; }
    void set(int raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    OUCH::enumerations::RejectReason value() const {
        return OUCH::enumerations::RejectReason::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::to_string(value_); }

private:
    int value_{};
};
class Scope {
public:
    Scope() = default;
    explicit Scope(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    OUCH::enumerations::MassCancelScope value() const {
        return OUCH::enumerations::MassCancelScope::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class Timestamp {
public:
    Timestamp() = default;
    explicit Timestamp(std::int64_t v) : value_(v) {}
    std::int64_t get() const { return value_; }
    void set(std::int64_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int64_t value_{};
};
} // namespace OUCH::fields