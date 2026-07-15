// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from fields.xml by protocol/generator/generate.py
#pragma once

#include <cstdint>
#include <string>

#include "MODEL/enumerations/Enumerations.hpp"

namespace MODEL::fields {

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
class ClientOrderId {
public:
    ClientOrderId() = default;
    explicit ClientOrderId(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class VenueOrderId {
public:
    VenueOrderId() = default;
    explicit VenueOrderId(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class ParentOrderId {
public:
    ParentOrderId() = default;
    explicit ParentOrderId(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class ExecutionId {
public:
    ExecutionId() = default;
    explicit ExecutionId(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class TradeId {
public:
    TradeId() = default;
    explicit TradeId(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class RequestId {
public:
    RequestId() = default;
    explicit RequestId(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class CorrelationId {
public:
    CorrelationId() = default;
    explicit CorrelationId(std::string v) : value_(std::move(v)) {}
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
class ClientId {
public:
    ClientId() = default;
    explicit ClientId(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class BrokerId {
public:
    BrokerId() = default;
    explicit BrokerId(std::string v) : value_(std::move(v)) {}
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
class SecurityId {
public:
    SecurityId() = default;
    explicit SecurityId(std::string v) : value_(std::move(v)) {}
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
class Exchange {
public:
    Exchange() = default;
    explicit Exchange(std::string v) : value_(std::move(v)) {}
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
class Side {
public:
    Side() = default;
    explicit Side(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    MODEL::enumerations::Side value() const {
        return MODEL::enumerations::Side::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class OrderType {
public:
    OrderType() = default;
    explicit OrderType(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    MODEL::enumerations::OrdType value() const {
        return MODEL::enumerations::OrdType::fromRaw(value_);
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
    MODEL::enumerations::TimeInForce value() const {
        return MODEL::enumerations::TimeInForce::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class ExecutionInstruction {
public:
    ExecutionInstruction() = default;
    explicit ExecutionInstruction(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    MODEL::enumerations::ExecInst value() const {
        return MODEL::enumerations::ExecInst::fromRaw(value_);
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
    explicit OrderQty(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class CumQty {
public:
    CumQty() = default;
    explicit CumQty(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class LeavesQty {
public:
    LeavesQty() = default;
    explicit LeavesQty(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class LastQty {
public:
    LastQty() = default;
    explicit LastQty(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class FilledQuantity {
public:
    FilledQuantity() = default;
    explicit FilledQuantity(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class RemainingQuantity {
public:
    RemainingQuantity() = default;
    explicit RemainingQuantity(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class LastFillQuantity {
public:
    LastFillQuantity() = default;
    explicit LastFillQuantity(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
};
class LastFillPrice {
public:
    LastFillPrice() = default;
    explicit LastFillPrice(int v) : value_(v) {}
    int get() const { return value_; }
    void set(int v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    int value_{};
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
class StopPrice {
public:
    StopPrice() = default;
    explicit StopPrice(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class LastPrice {
public:
    LastPrice() = default;
    explicit LastPrice(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class AveragePrice {
public:
    AveragePrice() = default;
    explicit AveragePrice(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class OrderStatus {
public:
    OrderStatus() = default;
    explicit OrderStatus(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    MODEL::enumerations::OrdStatus value() const {
        return MODEL::enumerations::OrdStatus::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class ExecutionType {
public:
    ExecutionType() = default;
    explicit ExecutionType(char raw) : value_(raw) {}
    // Raw wire value, e.g. '1'
    char get() const { return value_; }
    void set(char raw) { value_ = raw; }

    // Parsed enum wrapper, e.g. Side::Buy
    MODEL::enumerations::ExecType value() const {
        return MODEL::enumerations::ExecType::fromRaw(value_);
    }

    // Decoded name, e.g. "Buy"
    std::string toString() const { return value().toString(); }
    // Raw wire value as string, e.g. "1"
    std::string toStringData() const { return std::string(1, value_); }

private:
    char value_{};
};
class RejectReason {
public:
    RejectReason() = default;
    explicit RejectReason(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class RejectCode {
public:
    RejectCode() = default;
    explicit RejectCode(int v) : value_(v) {}
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
class CreatedTime {
public:
    CreatedTime() = default;
    explicit CreatedTime(std::int64_t v) : value_(v) {}
    std::int64_t get() const { return value_; }
    void set(std::int64_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int64_t value_{};
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
class VenueTime {
public:
    VenueTime() = default;
    explicit VenueTime(std::int64_t v) : value_(v) {}
    std::int64_t get() const { return value_; }
    void set(std::int64_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int64_t value_{};
};
class TradeTime {
public:
    TradeTime() = default;
    explicit TradeTime(std::int64_t v) : value_(v) {}
    std::int64_t get() const { return value_; }
    void set(std::int64_t v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    std::int64_t value_{};
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
class Sender {
public:
    Sender() = default;
    explicit Sender(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class Receiver {
public:
    Receiver() = default;
    explicit Receiver(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class Venue {
public:
    Venue() = default;
    explicit Venue(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class Strategy {
public:
    Strategy() = default;
    explicit Strategy(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
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
class MaxFloor {
public:
    MaxFloor() = default;
    explicit MaxFloor(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class MinQty {
public:
    MinQty() = default;
    explicit MinQty(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class DisplayQty {
public:
    DisplayQty() = default;
    explicit DisplayQty(double v) : value_(v) {}
    double get() const { return value_; }
    void set(double v) { value_ = v; }

    std::string toString() const { return std::to_string(value_); }
    std::string toStringData() const { return toString(); }

private:
    double value_{};
};
class Capacity {
public:
    Capacity() = default;
    explicit Capacity(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class OriginalClientOrderId {
public:
    OriginalClientOrderId() = default;
    explicit OriginalClientOrderId(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class OriginalVenueOrderId {
public:
    OriginalVenueOrderId() = default;
    explicit OriginalVenueOrderId(std::string v) : value_(std::move(v)) {}
    const std::string& get() const { return value_; }
    void set(std::string v) { value_ = std::move(v); }

    // Trimmed value, e.g. "ABC123" from "  ABC123   "
    std::string toString() const { return detail::trim(value_); }
    // Raw, untrimmed value as stored, e.g. "  ABC123   "
    const std::string& toStringData() const { return value_; }

private:
    std::string value_{};
};
class SequenceNumber {
public:
    SequenceNumber() = default;
    explicit SequenceNumber(std::int64_t v) : value_(v) {}
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
} // namespace MODEL::fields