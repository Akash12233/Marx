// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from enumerations.xml by protocol/generator/generate.py
#pragma once

#include <cstdint>
#include <string>
#include <stdexcept>

namespace FIX::enumerations {
enum class SideValue {
    BUY,
    SELL,
    BUY_MINUS,
    SELL_PLUS,
    SELL_SHORT,
    SELL_SHORT_EXEMPT,
    UNDISCLOSED,
    CROSS,
    CROSS_SHORT,
    CROSS_SHORT_EXEMPT,
    AS_DEFINED,
    OPPOSITE,
    SUBSCRIBE,
    REDEEM,
    LEND,
    BORROW
};

class Side {
public:
    explicit Side(SideValue v) : value_(v) {}

    SideValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case SideValue::BUY: return "BUY";
            case SideValue::SELL: return "SELL";
            case SideValue::BUY_MINUS: return "BUY_MINUS";
            case SideValue::SELL_PLUS: return "SELL_PLUS";
            case SideValue::SELL_SHORT: return "SELL_SHORT";
            case SideValue::SELL_SHORT_EXEMPT: return "SELL_SHORT_EXEMPT";
            case SideValue::UNDISCLOSED: return "UNDISCLOSED";
            case SideValue::CROSS: return "CROSS";
            case SideValue::CROSS_SHORT: return "CROSS_SHORT";
            case SideValue::CROSS_SHORT_EXEMPT: return "CROSS_SHORT_EXEMPT";
            case SideValue::AS_DEFINED: return "AS_DEFINED";
            case SideValue::OPPOSITE: return "OPPOSITE";
            case SideValue::SUBSCRIBE: return "SUBSCRIBE";
            case SideValue::REDEEM: return "REDEEM";
            case SideValue::LEND: return "LEND";
            case SideValue::BORROW: return "BORROW";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case SideValue::BUY: return '1';
            case SideValue::SELL: return '2';
            case SideValue::BUY_MINUS: return '3';
            case SideValue::SELL_PLUS: return '4';
            case SideValue::SELL_SHORT: return '5';
            case SideValue::SELL_SHORT_EXEMPT: return '6';
            case SideValue::UNDISCLOSED: return '7';
            case SideValue::CROSS: return '8';
            case SideValue::CROSS_SHORT: return '9';
            case SideValue::CROSS_SHORT_EXEMPT: return 'A';
            case SideValue::AS_DEFINED: return 'B';
            case SideValue::OPPOSITE: return 'C';
            case SideValue::SUBSCRIBE: return 'D';
            case SideValue::REDEEM: return 'E';
            case SideValue::LEND: return 'F';
            case SideValue::BORROW: return 'G';
        }
        return char{};
    }

    static Side fromRaw(char raw) {
        switch (raw) {
            case '1': return Side(SideValue::BUY);
            case '2': return Side(SideValue::SELL);
            case '3': return Side(SideValue::BUY_MINUS);
            case '4': return Side(SideValue::SELL_PLUS);
            case '5': return Side(SideValue::SELL_SHORT);
            case '6': return Side(SideValue::SELL_SHORT_EXEMPT);
            case '7': return Side(SideValue::UNDISCLOSED);
            case '8': return Side(SideValue::CROSS);
            case '9': return Side(SideValue::CROSS_SHORT);
            case 'A': return Side(SideValue::CROSS_SHORT_EXEMPT);
            case 'B': return Side(SideValue::AS_DEFINED);
            case 'C': return Side(SideValue::OPPOSITE);
            case 'D': return Side(SideValue::SUBSCRIBE);
            case 'E': return Side(SideValue::REDEEM);
            case 'F': return Side(SideValue::LEND);
            case 'G': return Side(SideValue::BORROW);
        }
        throw std::invalid_argument("Unknown raw value for enum Side");
    }

    static Side fromName(const std::string& name) {
        if (name == "BUY") return Side(SideValue::BUY);
        if (name == "SELL") return Side(SideValue::SELL);
        if (name == "BUY_MINUS") return Side(SideValue::BUY_MINUS);
        if (name == "SELL_PLUS") return Side(SideValue::SELL_PLUS);
        if (name == "SELL_SHORT") return Side(SideValue::SELL_SHORT);
        if (name == "SELL_SHORT_EXEMPT") return Side(SideValue::SELL_SHORT_EXEMPT);
        if (name == "UNDISCLOSED") return Side(SideValue::UNDISCLOSED);
        if (name == "CROSS") return Side(SideValue::CROSS);
        if (name == "CROSS_SHORT") return Side(SideValue::CROSS_SHORT);
        if (name == "CROSS_SHORT_EXEMPT") return Side(SideValue::CROSS_SHORT_EXEMPT);
        if (name == "AS_DEFINED") return Side(SideValue::AS_DEFINED);
        if (name == "OPPOSITE") return Side(SideValue::OPPOSITE);
        if (name == "SUBSCRIBE") return Side(SideValue::SUBSCRIBE);
        if (name == "REDEEM") return Side(SideValue::REDEEM);
        if (name == "LEND") return Side(SideValue::LEND);
        if (name == "BORROW") return Side(SideValue::BORROW);
        throw std::invalid_argument("Unknown name for enum Side: " + name);
    }

private:
    SideValue value_;
};
enum class OrdTypeValue {
    MARKET,
    LIMIT,
    STOP,
    STOP_LIMIT,
    MARKET_ON_CLOSE,
    WITH_OR_WITHOUT,
    LIMIT_OR_BETTER,
    LIMIT_WITH_OR_WITHOUT,
    ON_BASIS,
    ON_CLOSE,
    LIMIT_ON_CLOSE,
    FOREX_MARKET,
    PREVIOUSLY_QUOTED,
    PREVIOUSLY_INDICATED,
    FOREX_LIMIT,
    FOREX_SWAP,
    FOREX_PREVIOUSLY_QUOTED,
    FUNARI,
    MARKET_IF_TOUCHED,
    MARKET_WITH_LEFTOVER_AS_LIMIT,
    PREVIOUS_FUND_VALUATION_POINT,
    NEXT_FUND_VALUATION_POINT,
    PEGGED
};

class OrdType {
public:
    explicit OrdType(OrdTypeValue v) : value_(v) {}

    OrdTypeValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case OrdTypeValue::MARKET: return "MARKET";
            case OrdTypeValue::LIMIT: return "LIMIT";
            case OrdTypeValue::STOP: return "STOP";
            case OrdTypeValue::STOP_LIMIT: return "STOP_LIMIT";
            case OrdTypeValue::MARKET_ON_CLOSE: return "MARKET_ON_CLOSE";
            case OrdTypeValue::WITH_OR_WITHOUT: return "WITH_OR_WITHOUT";
            case OrdTypeValue::LIMIT_OR_BETTER: return "LIMIT_OR_BETTER";
            case OrdTypeValue::LIMIT_WITH_OR_WITHOUT: return "LIMIT_WITH_OR_WITHOUT";
            case OrdTypeValue::ON_BASIS: return "ON_BASIS";
            case OrdTypeValue::ON_CLOSE: return "ON_CLOSE";
            case OrdTypeValue::LIMIT_ON_CLOSE: return "LIMIT_ON_CLOSE";
            case OrdTypeValue::FOREX_MARKET: return "FOREX_MARKET";
            case OrdTypeValue::PREVIOUSLY_QUOTED: return "PREVIOUSLY_QUOTED";
            case OrdTypeValue::PREVIOUSLY_INDICATED: return "PREVIOUSLY_INDICATED";
            case OrdTypeValue::FOREX_LIMIT: return "FOREX_LIMIT";
            case OrdTypeValue::FOREX_SWAP: return "FOREX_SWAP";
            case OrdTypeValue::FOREX_PREVIOUSLY_QUOTED: return "FOREX_PREVIOUSLY_QUOTED";
            case OrdTypeValue::FUNARI: return "FUNARI";
            case OrdTypeValue::MARKET_IF_TOUCHED: return "MARKET_IF_TOUCHED";
            case OrdTypeValue::MARKET_WITH_LEFTOVER_AS_LIMIT: return "MARKET_WITH_LEFTOVER_AS_LIMIT";
            case OrdTypeValue::PREVIOUS_FUND_VALUATION_POINT: return "PREVIOUS_FUND_VALUATION_POINT";
            case OrdTypeValue::NEXT_FUND_VALUATION_POINT: return "NEXT_FUND_VALUATION_POINT";
            case OrdTypeValue::PEGGED: return "PEGGED";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case OrdTypeValue::MARKET: return '1';
            case OrdTypeValue::LIMIT: return '2';
            case OrdTypeValue::STOP: return '3';
            case OrdTypeValue::STOP_LIMIT: return '4';
            case OrdTypeValue::MARKET_ON_CLOSE: return '5';
            case OrdTypeValue::WITH_OR_WITHOUT: return '6';
            case OrdTypeValue::LIMIT_OR_BETTER: return '7';
            case OrdTypeValue::LIMIT_WITH_OR_WITHOUT: return '8';
            case OrdTypeValue::ON_BASIS: return '9';
            case OrdTypeValue::ON_CLOSE: return 'A';
            case OrdTypeValue::LIMIT_ON_CLOSE: return 'B';
            case OrdTypeValue::FOREX_MARKET: return 'C';
            case OrdTypeValue::PREVIOUSLY_QUOTED: return 'D';
            case OrdTypeValue::PREVIOUSLY_INDICATED: return 'E';
            case OrdTypeValue::FOREX_LIMIT: return 'F';
            case OrdTypeValue::FOREX_SWAP: return 'G';
            case OrdTypeValue::FOREX_PREVIOUSLY_QUOTED: return 'H';
            case OrdTypeValue::FUNARI: return 'I';
            case OrdTypeValue::MARKET_IF_TOUCHED: return 'J';
            case OrdTypeValue::MARKET_WITH_LEFTOVER_AS_LIMIT: return 'K';
            case OrdTypeValue::PREVIOUS_FUND_VALUATION_POINT: return 'L';
            case OrdTypeValue::NEXT_FUND_VALUATION_POINT: return 'M';
            case OrdTypeValue::PEGGED: return 'P';
        }
        return char{};
    }

    static OrdType fromRaw(char raw) {
        switch (raw) {
            case '1': return OrdType(OrdTypeValue::MARKET);
            case '2': return OrdType(OrdTypeValue::LIMIT);
            case '3': return OrdType(OrdTypeValue::STOP);
            case '4': return OrdType(OrdTypeValue::STOP_LIMIT);
            case '5': return OrdType(OrdTypeValue::MARKET_ON_CLOSE);
            case '6': return OrdType(OrdTypeValue::WITH_OR_WITHOUT);
            case '7': return OrdType(OrdTypeValue::LIMIT_OR_BETTER);
            case '8': return OrdType(OrdTypeValue::LIMIT_WITH_OR_WITHOUT);
            case '9': return OrdType(OrdTypeValue::ON_BASIS);
            case 'A': return OrdType(OrdTypeValue::ON_CLOSE);
            case 'B': return OrdType(OrdTypeValue::LIMIT_ON_CLOSE);
            case 'C': return OrdType(OrdTypeValue::FOREX_MARKET);
            case 'D': return OrdType(OrdTypeValue::PREVIOUSLY_QUOTED);
            case 'E': return OrdType(OrdTypeValue::PREVIOUSLY_INDICATED);
            case 'F': return OrdType(OrdTypeValue::FOREX_LIMIT);
            case 'G': return OrdType(OrdTypeValue::FOREX_SWAP);
            case 'H': return OrdType(OrdTypeValue::FOREX_PREVIOUSLY_QUOTED);
            case 'I': return OrdType(OrdTypeValue::FUNARI);
            case 'J': return OrdType(OrdTypeValue::MARKET_IF_TOUCHED);
            case 'K': return OrdType(OrdTypeValue::MARKET_WITH_LEFTOVER_AS_LIMIT);
            case 'L': return OrdType(OrdTypeValue::PREVIOUS_FUND_VALUATION_POINT);
            case 'M': return OrdType(OrdTypeValue::NEXT_FUND_VALUATION_POINT);
            case 'P': return OrdType(OrdTypeValue::PEGGED);
        }
        throw std::invalid_argument("Unknown raw value for enum OrdType");
    }

    static OrdType fromName(const std::string& name) {
        if (name == "MARKET") return OrdType(OrdTypeValue::MARKET);
        if (name == "LIMIT") return OrdType(OrdTypeValue::LIMIT);
        if (name == "STOP") return OrdType(OrdTypeValue::STOP);
        if (name == "STOP_LIMIT") return OrdType(OrdTypeValue::STOP_LIMIT);
        if (name == "MARKET_ON_CLOSE") return OrdType(OrdTypeValue::MARKET_ON_CLOSE);
        if (name == "WITH_OR_WITHOUT") return OrdType(OrdTypeValue::WITH_OR_WITHOUT);
        if (name == "LIMIT_OR_BETTER") return OrdType(OrdTypeValue::LIMIT_OR_BETTER);
        if (name == "LIMIT_WITH_OR_WITHOUT") return OrdType(OrdTypeValue::LIMIT_WITH_OR_WITHOUT);
        if (name == "ON_BASIS") return OrdType(OrdTypeValue::ON_BASIS);
        if (name == "ON_CLOSE") return OrdType(OrdTypeValue::ON_CLOSE);
        if (name == "LIMIT_ON_CLOSE") return OrdType(OrdTypeValue::LIMIT_ON_CLOSE);
        if (name == "FOREX_MARKET") return OrdType(OrdTypeValue::FOREX_MARKET);
        if (name == "PREVIOUSLY_QUOTED") return OrdType(OrdTypeValue::PREVIOUSLY_QUOTED);
        if (name == "PREVIOUSLY_INDICATED") return OrdType(OrdTypeValue::PREVIOUSLY_INDICATED);
        if (name == "FOREX_LIMIT") return OrdType(OrdTypeValue::FOREX_LIMIT);
        if (name == "FOREX_SWAP") return OrdType(OrdTypeValue::FOREX_SWAP);
        if (name == "FOREX_PREVIOUSLY_QUOTED") return OrdType(OrdTypeValue::FOREX_PREVIOUSLY_QUOTED);
        if (name == "FUNARI") return OrdType(OrdTypeValue::FUNARI);
        if (name == "MARKET_IF_TOUCHED") return OrdType(OrdTypeValue::MARKET_IF_TOUCHED);
        if (name == "MARKET_WITH_LEFTOVER_AS_LIMIT") return OrdType(OrdTypeValue::MARKET_WITH_LEFTOVER_AS_LIMIT);
        if (name == "PREVIOUS_FUND_VALUATION_POINT") return OrdType(OrdTypeValue::PREVIOUS_FUND_VALUATION_POINT);
        if (name == "NEXT_FUND_VALUATION_POINT") return OrdType(OrdTypeValue::NEXT_FUND_VALUATION_POINT);
        if (name == "PEGGED") return OrdType(OrdTypeValue::PEGGED);
        throw std::invalid_argument("Unknown name for enum OrdType: " + name);
    }

private:
    OrdTypeValue value_;
};
enum class TimeInForceValue {
    DAY,
    GOOD_TILL_CANCEL,
    AT_THE_OPENING,
    IMMEDIATE_OR_CANCEL,
    FILL_OR_KILL,
    GOOD_TILL_CROSSING,
    GOOD_TILL_DATE,
    AT_THE_CLOSE
};

class TimeInForce {
public:
    explicit TimeInForce(TimeInForceValue v) : value_(v) {}

    TimeInForceValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case TimeInForceValue::DAY: return "DAY";
            case TimeInForceValue::GOOD_TILL_CANCEL: return "GOOD_TILL_CANCEL";
            case TimeInForceValue::AT_THE_OPENING: return "AT_THE_OPENING";
            case TimeInForceValue::IMMEDIATE_OR_CANCEL: return "IMMEDIATE_OR_CANCEL";
            case TimeInForceValue::FILL_OR_KILL: return "FILL_OR_KILL";
            case TimeInForceValue::GOOD_TILL_CROSSING: return "GOOD_TILL_CROSSING";
            case TimeInForceValue::GOOD_TILL_DATE: return "GOOD_TILL_DATE";
            case TimeInForceValue::AT_THE_CLOSE: return "AT_THE_CLOSE";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case TimeInForceValue::DAY: return '0';
            case TimeInForceValue::GOOD_TILL_CANCEL: return '1';
            case TimeInForceValue::AT_THE_OPENING: return '2';
            case TimeInForceValue::IMMEDIATE_OR_CANCEL: return '3';
            case TimeInForceValue::FILL_OR_KILL: return '4';
            case TimeInForceValue::GOOD_TILL_CROSSING: return '5';
            case TimeInForceValue::GOOD_TILL_DATE: return '6';
            case TimeInForceValue::AT_THE_CLOSE: return '7';
        }
        return char{};
    }

    static TimeInForce fromRaw(char raw) {
        switch (raw) {
            case '0': return TimeInForce(TimeInForceValue::DAY);
            case '1': return TimeInForce(TimeInForceValue::GOOD_TILL_CANCEL);
            case '2': return TimeInForce(TimeInForceValue::AT_THE_OPENING);
            case '3': return TimeInForce(TimeInForceValue::IMMEDIATE_OR_CANCEL);
            case '4': return TimeInForce(TimeInForceValue::FILL_OR_KILL);
            case '5': return TimeInForce(TimeInForceValue::GOOD_TILL_CROSSING);
            case '6': return TimeInForce(TimeInForceValue::GOOD_TILL_DATE);
            case '7': return TimeInForce(TimeInForceValue::AT_THE_CLOSE);
        }
        throw std::invalid_argument("Unknown raw value for enum TimeInForce");
    }

    static TimeInForce fromName(const std::string& name) {
        if (name == "DAY") return TimeInForce(TimeInForceValue::DAY);
        if (name == "GOOD_TILL_CANCEL") return TimeInForce(TimeInForceValue::GOOD_TILL_CANCEL);
        if (name == "AT_THE_OPENING") return TimeInForce(TimeInForceValue::AT_THE_OPENING);
        if (name == "IMMEDIATE_OR_CANCEL") return TimeInForce(TimeInForceValue::IMMEDIATE_OR_CANCEL);
        if (name == "FILL_OR_KILL") return TimeInForce(TimeInForceValue::FILL_OR_KILL);
        if (name == "GOOD_TILL_CROSSING") return TimeInForce(TimeInForceValue::GOOD_TILL_CROSSING);
        if (name == "GOOD_TILL_DATE") return TimeInForce(TimeInForceValue::GOOD_TILL_DATE);
        if (name == "AT_THE_CLOSE") return TimeInForce(TimeInForceValue::AT_THE_CLOSE);
        throw std::invalid_argument("Unknown name for enum TimeInForce: " + name);
    }

private:
    TimeInForceValue value_;
};
enum class OrdStatusValue {
    NEW,
    PARTIALLY_FILLED,
    FILLED,
    DONE_FOR_DAY,
    CANCELED,
    REPLACED,
    PENDING_CANCEL,
    STOPPED,
    REJECTED,
    SUSPENDED,
    PENDING_NEW,
    CALCULATED,
    EXPIRED,
    ACCEPTED_FOR_BIDDING,
    PENDING_REPLACE
};

class OrdStatus {
public:
    explicit OrdStatus(OrdStatusValue v) : value_(v) {}

    OrdStatusValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case OrdStatusValue::NEW: return "NEW";
            case OrdStatusValue::PARTIALLY_FILLED: return "PARTIALLY_FILLED";
            case OrdStatusValue::FILLED: return "FILLED";
            case OrdStatusValue::DONE_FOR_DAY: return "DONE_FOR_DAY";
            case OrdStatusValue::CANCELED: return "CANCELED";
            case OrdStatusValue::REPLACED: return "REPLACED";
            case OrdStatusValue::PENDING_CANCEL: return "PENDING_CANCEL";
            case OrdStatusValue::STOPPED: return "STOPPED";
            case OrdStatusValue::REJECTED: return "REJECTED";
            case OrdStatusValue::SUSPENDED: return "SUSPENDED";
            case OrdStatusValue::PENDING_NEW: return "PENDING_NEW";
            case OrdStatusValue::CALCULATED: return "CALCULATED";
            case OrdStatusValue::EXPIRED: return "EXPIRED";
            case OrdStatusValue::ACCEPTED_FOR_BIDDING: return "ACCEPTED_FOR_BIDDING";
            case OrdStatusValue::PENDING_REPLACE: return "PENDING_REPLACE";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case OrdStatusValue::NEW: return '0';
            case OrdStatusValue::PARTIALLY_FILLED: return '1';
            case OrdStatusValue::FILLED: return '2';
            case OrdStatusValue::DONE_FOR_DAY: return '3';
            case OrdStatusValue::CANCELED: return '4';
            case OrdStatusValue::REPLACED: return '5';
            case OrdStatusValue::PENDING_CANCEL: return '6';
            case OrdStatusValue::STOPPED: return '7';
            case OrdStatusValue::REJECTED: return '8';
            case OrdStatusValue::SUSPENDED: return '9';
            case OrdStatusValue::PENDING_NEW: return 'A';
            case OrdStatusValue::CALCULATED: return 'B';
            case OrdStatusValue::EXPIRED: return 'C';
            case OrdStatusValue::ACCEPTED_FOR_BIDDING: return 'D';
            case OrdStatusValue::PENDING_REPLACE: return 'E';
        }
        return char{};
    }

    static OrdStatus fromRaw(char raw) {
        switch (raw) {
            case '0': return OrdStatus(OrdStatusValue::NEW);
            case '1': return OrdStatus(OrdStatusValue::PARTIALLY_FILLED);
            case '2': return OrdStatus(OrdStatusValue::FILLED);
            case '3': return OrdStatus(OrdStatusValue::DONE_FOR_DAY);
            case '4': return OrdStatus(OrdStatusValue::CANCELED);
            case '5': return OrdStatus(OrdStatusValue::REPLACED);
            case '6': return OrdStatus(OrdStatusValue::PENDING_CANCEL);
            case '7': return OrdStatus(OrdStatusValue::STOPPED);
            case '8': return OrdStatus(OrdStatusValue::REJECTED);
            case '9': return OrdStatus(OrdStatusValue::SUSPENDED);
            case 'A': return OrdStatus(OrdStatusValue::PENDING_NEW);
            case 'B': return OrdStatus(OrdStatusValue::CALCULATED);
            case 'C': return OrdStatus(OrdStatusValue::EXPIRED);
            case 'D': return OrdStatus(OrdStatusValue::ACCEPTED_FOR_BIDDING);
            case 'E': return OrdStatus(OrdStatusValue::PENDING_REPLACE);
        }
        throw std::invalid_argument("Unknown raw value for enum OrdStatus");
    }

    static OrdStatus fromName(const std::string& name) {
        if (name == "NEW") return OrdStatus(OrdStatusValue::NEW);
        if (name == "PARTIALLY_FILLED") return OrdStatus(OrdStatusValue::PARTIALLY_FILLED);
        if (name == "FILLED") return OrdStatus(OrdStatusValue::FILLED);
        if (name == "DONE_FOR_DAY") return OrdStatus(OrdStatusValue::DONE_FOR_DAY);
        if (name == "CANCELED") return OrdStatus(OrdStatusValue::CANCELED);
        if (name == "REPLACED") return OrdStatus(OrdStatusValue::REPLACED);
        if (name == "PENDING_CANCEL") return OrdStatus(OrdStatusValue::PENDING_CANCEL);
        if (name == "STOPPED") return OrdStatus(OrdStatusValue::STOPPED);
        if (name == "REJECTED") return OrdStatus(OrdStatusValue::REJECTED);
        if (name == "SUSPENDED") return OrdStatus(OrdStatusValue::SUSPENDED);
        if (name == "PENDING_NEW") return OrdStatus(OrdStatusValue::PENDING_NEW);
        if (name == "CALCULATED") return OrdStatus(OrdStatusValue::CALCULATED);
        if (name == "EXPIRED") return OrdStatus(OrdStatusValue::EXPIRED);
        if (name == "ACCEPTED_FOR_BIDDING") return OrdStatus(OrdStatusValue::ACCEPTED_FOR_BIDDING);
        if (name == "PENDING_REPLACE") return OrdStatus(OrdStatusValue::PENDING_REPLACE);
        throw std::invalid_argument("Unknown name for enum OrdStatus: " + name);
    }

private:
    OrdStatusValue value_;
};
enum class ExecTypeValue {
    NEW,
    PARTIAL_FILL,
    FILL,
    DONE_FOR_DAY,
    CANCELED,
    REPLACE,
    PENDING_CANCEL,
    STOPPED,
    REJECTED,
    SUSPENDED,
    PENDING_NEW,
    CALCULATED,
    EXPIRED,
    RESTATED,
    PENDING_REPLACE,
    TRADE,
    TRADE_CORRECT,
    TRADE_CANCEL,
    ORDER_STATUS
};

class ExecType {
public:
    explicit ExecType(ExecTypeValue v) : value_(v) {}

    ExecTypeValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case ExecTypeValue::NEW: return "NEW";
            case ExecTypeValue::PARTIAL_FILL: return "PARTIAL_FILL";
            case ExecTypeValue::FILL: return "FILL";
            case ExecTypeValue::DONE_FOR_DAY: return "DONE_FOR_DAY";
            case ExecTypeValue::CANCELED: return "CANCELED";
            case ExecTypeValue::REPLACE: return "REPLACE";
            case ExecTypeValue::PENDING_CANCEL: return "PENDING_CANCEL";
            case ExecTypeValue::STOPPED: return "STOPPED";
            case ExecTypeValue::REJECTED: return "REJECTED";
            case ExecTypeValue::SUSPENDED: return "SUSPENDED";
            case ExecTypeValue::PENDING_NEW: return "PENDING_NEW";
            case ExecTypeValue::CALCULATED: return "CALCULATED";
            case ExecTypeValue::EXPIRED: return "EXPIRED";
            case ExecTypeValue::RESTATED: return "RESTATED";
            case ExecTypeValue::PENDING_REPLACE: return "PENDING_REPLACE";
            case ExecTypeValue::TRADE: return "TRADE";
            case ExecTypeValue::TRADE_CORRECT: return "TRADE_CORRECT";
            case ExecTypeValue::TRADE_CANCEL: return "TRADE_CANCEL";
            case ExecTypeValue::ORDER_STATUS: return "ORDER_STATUS";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case ExecTypeValue::NEW: return '0';
            case ExecTypeValue::PARTIAL_FILL: return '1';
            case ExecTypeValue::FILL: return '2';
            case ExecTypeValue::DONE_FOR_DAY: return '3';
            case ExecTypeValue::CANCELED: return '4';
            case ExecTypeValue::REPLACE: return '5';
            case ExecTypeValue::PENDING_CANCEL: return '6';
            case ExecTypeValue::STOPPED: return '7';
            case ExecTypeValue::REJECTED: return '8';
            case ExecTypeValue::SUSPENDED: return '9';
            case ExecTypeValue::PENDING_NEW: return 'A';
            case ExecTypeValue::CALCULATED: return 'B';
            case ExecTypeValue::EXPIRED: return 'C';
            case ExecTypeValue::RESTATED: return 'D';
            case ExecTypeValue::PENDING_REPLACE: return 'E';
            case ExecTypeValue::TRADE: return 'F';
            case ExecTypeValue::TRADE_CORRECT: return 'G';
            case ExecTypeValue::TRADE_CANCEL: return 'H';
            case ExecTypeValue::ORDER_STATUS: return 'I';
        }
        return char{};
    }

    static ExecType fromRaw(char raw) {
        switch (raw) {
            case '0': return ExecType(ExecTypeValue::NEW);
            case '1': return ExecType(ExecTypeValue::PARTIAL_FILL);
            case '2': return ExecType(ExecTypeValue::FILL);
            case '3': return ExecType(ExecTypeValue::DONE_FOR_DAY);
            case '4': return ExecType(ExecTypeValue::CANCELED);
            case '5': return ExecType(ExecTypeValue::REPLACE);
            case '6': return ExecType(ExecTypeValue::PENDING_CANCEL);
            case '7': return ExecType(ExecTypeValue::STOPPED);
            case '8': return ExecType(ExecTypeValue::REJECTED);
            case '9': return ExecType(ExecTypeValue::SUSPENDED);
            case 'A': return ExecType(ExecTypeValue::PENDING_NEW);
            case 'B': return ExecType(ExecTypeValue::CALCULATED);
            case 'C': return ExecType(ExecTypeValue::EXPIRED);
            case 'D': return ExecType(ExecTypeValue::RESTATED);
            case 'E': return ExecType(ExecTypeValue::PENDING_REPLACE);
            case 'F': return ExecType(ExecTypeValue::TRADE);
            case 'G': return ExecType(ExecTypeValue::TRADE_CORRECT);
            case 'H': return ExecType(ExecTypeValue::TRADE_CANCEL);
            case 'I': return ExecType(ExecTypeValue::ORDER_STATUS);
        }
        throw std::invalid_argument("Unknown raw value for enum ExecType");
    }

    static ExecType fromName(const std::string& name) {
        if (name == "NEW") return ExecType(ExecTypeValue::NEW);
        if (name == "PARTIAL_FILL") return ExecType(ExecTypeValue::PARTIAL_FILL);
        if (name == "FILL") return ExecType(ExecTypeValue::FILL);
        if (name == "DONE_FOR_DAY") return ExecType(ExecTypeValue::DONE_FOR_DAY);
        if (name == "CANCELED") return ExecType(ExecTypeValue::CANCELED);
        if (name == "REPLACE") return ExecType(ExecTypeValue::REPLACE);
        if (name == "PENDING_CANCEL") return ExecType(ExecTypeValue::PENDING_CANCEL);
        if (name == "STOPPED") return ExecType(ExecTypeValue::STOPPED);
        if (name == "REJECTED") return ExecType(ExecTypeValue::REJECTED);
        if (name == "SUSPENDED") return ExecType(ExecTypeValue::SUSPENDED);
        if (name == "PENDING_NEW") return ExecType(ExecTypeValue::PENDING_NEW);
        if (name == "CALCULATED") return ExecType(ExecTypeValue::CALCULATED);
        if (name == "EXPIRED") return ExecType(ExecTypeValue::EXPIRED);
        if (name == "RESTATED") return ExecType(ExecTypeValue::RESTATED);
        if (name == "PENDING_REPLACE") return ExecType(ExecTypeValue::PENDING_REPLACE);
        if (name == "TRADE") return ExecType(ExecTypeValue::TRADE);
        if (name == "TRADE_CORRECT") return ExecType(ExecTypeValue::TRADE_CORRECT);
        if (name == "TRADE_CANCEL") return ExecType(ExecTypeValue::TRADE_CANCEL);
        if (name == "ORDER_STATUS") return ExecType(ExecTypeValue::ORDER_STATUS);
        throw std::invalid_argument("Unknown name for enum ExecType: " + name);
    }

private:
    ExecTypeValue value_;
};
enum class OrdRejReasonValue {
    BROKER_OPTION,
    UNKNOWN_SYMBOL,
    EXCHANGE_CLOSED,
    ORDER_EXCEEDS_LIMIT,
    TOO_LATE_TO_ENTER,
    UNKNOWN_ORDER,
    DUPLICATE_ORDER,
    DUPLICATE_VERBAL_ORDER,
    STALE_ORDER,
    TRADE_ALONG_REQUIRED,
    INVALID_INVESTOR_ID,
    UNSUPPORTED_ORDER_CHARACTERISTIC,
    SURVEILLANCE_OPTION,
    INCORRECT_QUANTITY,
    INCORRECT_ALLOCATED_QUANTITY,
    UNKNOWN_ACCOUNT,
    OTHER
};

class OrdRejReason {
public:
    explicit OrdRejReason(OrdRejReasonValue v) : value_(v) {}

    OrdRejReasonValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case OrdRejReasonValue::BROKER_OPTION: return "BROKER_OPTION";
            case OrdRejReasonValue::UNKNOWN_SYMBOL: return "UNKNOWN_SYMBOL";
            case OrdRejReasonValue::EXCHANGE_CLOSED: return "EXCHANGE_CLOSED";
            case OrdRejReasonValue::ORDER_EXCEEDS_LIMIT: return "ORDER_EXCEEDS_LIMIT";
            case OrdRejReasonValue::TOO_LATE_TO_ENTER: return "TOO_LATE_TO_ENTER";
            case OrdRejReasonValue::UNKNOWN_ORDER: return "UNKNOWN_ORDER";
            case OrdRejReasonValue::DUPLICATE_ORDER: return "DUPLICATE_ORDER";
            case OrdRejReasonValue::DUPLICATE_VERBAL_ORDER: return "DUPLICATE_VERBAL_ORDER";
            case OrdRejReasonValue::STALE_ORDER: return "STALE_ORDER";
            case OrdRejReasonValue::TRADE_ALONG_REQUIRED: return "TRADE_ALONG_REQUIRED";
            case OrdRejReasonValue::INVALID_INVESTOR_ID: return "INVALID_INVESTOR_ID";
            case OrdRejReasonValue::UNSUPPORTED_ORDER_CHARACTERISTIC: return "UNSUPPORTED_ORDER_CHARACTERISTIC";
            case OrdRejReasonValue::SURVEILLANCE_OPTION: return "SURVEILLANCE_OPTION";
            case OrdRejReasonValue::INCORRECT_QUANTITY: return "INCORRECT_QUANTITY";
            case OrdRejReasonValue::INCORRECT_ALLOCATED_QUANTITY: return "INCORRECT_ALLOCATED_QUANTITY";
            case OrdRejReasonValue::UNKNOWN_ACCOUNT: return "UNKNOWN_ACCOUNT";
            case OrdRejReasonValue::OTHER: return "OTHER";
        }
        return "";
    }

    int raw() const {
        switch (value_) {
            case OrdRejReasonValue::BROKER_OPTION: return 0;
            case OrdRejReasonValue::UNKNOWN_SYMBOL: return 1;
            case OrdRejReasonValue::EXCHANGE_CLOSED: return 2;
            case OrdRejReasonValue::ORDER_EXCEEDS_LIMIT: return 3;
            case OrdRejReasonValue::TOO_LATE_TO_ENTER: return 4;
            case OrdRejReasonValue::UNKNOWN_ORDER: return 5;
            case OrdRejReasonValue::DUPLICATE_ORDER: return 6;
            case OrdRejReasonValue::DUPLICATE_VERBAL_ORDER: return 7;
            case OrdRejReasonValue::STALE_ORDER: return 8;
            case OrdRejReasonValue::TRADE_ALONG_REQUIRED: return 9;
            case OrdRejReasonValue::INVALID_INVESTOR_ID: return 10;
            case OrdRejReasonValue::UNSUPPORTED_ORDER_CHARACTERISTIC: return 11;
            case OrdRejReasonValue::SURVEILLANCE_OPTION: return 12;
            case OrdRejReasonValue::INCORRECT_QUANTITY: return 13;
            case OrdRejReasonValue::INCORRECT_ALLOCATED_QUANTITY: return 14;
            case OrdRejReasonValue::UNKNOWN_ACCOUNT: return 15;
            case OrdRejReasonValue::OTHER: return 99;
        }
        return int{};
    }

    static OrdRejReason fromRaw(int raw) {
        switch (raw) {
            case 0: return OrdRejReason(OrdRejReasonValue::BROKER_OPTION);
            case 1: return OrdRejReason(OrdRejReasonValue::UNKNOWN_SYMBOL);
            case 2: return OrdRejReason(OrdRejReasonValue::EXCHANGE_CLOSED);
            case 3: return OrdRejReason(OrdRejReasonValue::ORDER_EXCEEDS_LIMIT);
            case 4: return OrdRejReason(OrdRejReasonValue::TOO_LATE_TO_ENTER);
            case 5: return OrdRejReason(OrdRejReasonValue::UNKNOWN_ORDER);
            case 6: return OrdRejReason(OrdRejReasonValue::DUPLICATE_ORDER);
            case 7: return OrdRejReason(OrdRejReasonValue::DUPLICATE_VERBAL_ORDER);
            case 8: return OrdRejReason(OrdRejReasonValue::STALE_ORDER);
            case 9: return OrdRejReason(OrdRejReasonValue::TRADE_ALONG_REQUIRED);
            case 10: return OrdRejReason(OrdRejReasonValue::INVALID_INVESTOR_ID);
            case 11: return OrdRejReason(OrdRejReasonValue::UNSUPPORTED_ORDER_CHARACTERISTIC);
            case 12: return OrdRejReason(OrdRejReasonValue::SURVEILLANCE_OPTION);
            case 13: return OrdRejReason(OrdRejReasonValue::INCORRECT_QUANTITY);
            case 14: return OrdRejReason(OrdRejReasonValue::INCORRECT_ALLOCATED_QUANTITY);
            case 15: return OrdRejReason(OrdRejReasonValue::UNKNOWN_ACCOUNT);
            case 99: return OrdRejReason(OrdRejReasonValue::OTHER);
        }
        throw std::invalid_argument("Unknown raw value for enum OrdRejReason");
    }

    static OrdRejReason fromName(const std::string& name) {
        if (name == "BROKER_OPTION") return OrdRejReason(OrdRejReasonValue::BROKER_OPTION);
        if (name == "UNKNOWN_SYMBOL") return OrdRejReason(OrdRejReasonValue::UNKNOWN_SYMBOL);
        if (name == "EXCHANGE_CLOSED") return OrdRejReason(OrdRejReasonValue::EXCHANGE_CLOSED);
        if (name == "ORDER_EXCEEDS_LIMIT") return OrdRejReason(OrdRejReasonValue::ORDER_EXCEEDS_LIMIT);
        if (name == "TOO_LATE_TO_ENTER") return OrdRejReason(OrdRejReasonValue::TOO_LATE_TO_ENTER);
        if (name == "UNKNOWN_ORDER") return OrdRejReason(OrdRejReasonValue::UNKNOWN_ORDER);
        if (name == "DUPLICATE_ORDER") return OrdRejReason(OrdRejReasonValue::DUPLICATE_ORDER);
        if (name == "DUPLICATE_VERBAL_ORDER") return OrdRejReason(OrdRejReasonValue::DUPLICATE_VERBAL_ORDER);
        if (name == "STALE_ORDER") return OrdRejReason(OrdRejReasonValue::STALE_ORDER);
        if (name == "TRADE_ALONG_REQUIRED") return OrdRejReason(OrdRejReasonValue::TRADE_ALONG_REQUIRED);
        if (name == "INVALID_INVESTOR_ID") return OrdRejReason(OrdRejReasonValue::INVALID_INVESTOR_ID);
        if (name == "UNSUPPORTED_ORDER_CHARACTERISTIC") return OrdRejReason(OrdRejReasonValue::UNSUPPORTED_ORDER_CHARACTERISTIC);
        if (name == "SURVEILLANCE_OPTION") return OrdRejReason(OrdRejReasonValue::SURVEILLANCE_OPTION);
        if (name == "INCORRECT_QUANTITY") return OrdRejReason(OrdRejReasonValue::INCORRECT_QUANTITY);
        if (name == "INCORRECT_ALLOCATED_QUANTITY") return OrdRejReason(OrdRejReasonValue::INCORRECT_ALLOCATED_QUANTITY);
        if (name == "UNKNOWN_ACCOUNT") return OrdRejReason(OrdRejReasonValue::UNKNOWN_ACCOUNT);
        if (name == "OTHER") return OrdRejReason(OrdRejReasonValue::OTHER);
        throw std::invalid_argument("Unknown name for enum OrdRejReason: " + name);
    }

private:
    OrdRejReasonValue value_;
};
enum class ExecInstValue {
    STAY_ON_OFFERSIDE,
    NOT_HELD,
    WORK,
    GO_ALONG,
    OVER_THE_DAY,
    HELD,
    PARTICIPATE_DONT_INITIATE,
    STRICT_SCALE,
    TRY_TO_SCALE,
    STAY_ON_BIDSIDE,
    NO_CROSS,
    OK_TO_CROSS,
    CALL_FIRST,
    PERCENT_OF_VOLUME,
    DO_NOT_INCREASE,
    DO_NOT_REDUCE,
    ALL_OR_NONE,
    INSTITUTIONS_ONLY,
    LAST_PEG,
    MID_PRICE_PEG,
    NON_NEGOTIABLE,
    OPENING_PEG,
    MARKET_PEG,
    PRIMARY_PEG,
    SUSPEND,
    FIXED_PEG_TO_LOCAL_BEST_BID_OR_OFFER,
    CUSTOMER_DISPLAY_INSTRUCTION,
    NETTING,
    PEG_TO_VWAP,
    TRADE_ALONG,
    TRY_TO_STOP,
    CANCEL_IF_NOT_BEST,
    TRAILING_STOP_PEG,
    STRICT_LIMIT,
    IGNORE_PRICE_VALIDITY_CHECKS,
    PEG_TO_LIMIT_PRICE
};

class ExecInst {
public:
    explicit ExecInst(ExecInstValue v) : value_(v) {}

    ExecInstValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case ExecInstValue::STAY_ON_OFFERSIDE: return "STAY_ON_OFFERSIDE";
            case ExecInstValue::NOT_HELD: return "NOT_HELD";
            case ExecInstValue::WORK: return "WORK";
            case ExecInstValue::GO_ALONG: return "GO_ALONG";
            case ExecInstValue::OVER_THE_DAY: return "OVER_THE_DAY";
            case ExecInstValue::HELD: return "HELD";
            case ExecInstValue::PARTICIPATE_DONT_INITIATE: return "PARTICIPATE_DONT_INITIATE";
            case ExecInstValue::STRICT_SCALE: return "STRICT_SCALE";
            case ExecInstValue::TRY_TO_SCALE: return "TRY_TO_SCALE";
            case ExecInstValue::STAY_ON_BIDSIDE: return "STAY_ON_BIDSIDE";
            case ExecInstValue::NO_CROSS: return "NO_CROSS";
            case ExecInstValue::OK_TO_CROSS: return "OK_TO_CROSS";
            case ExecInstValue::CALL_FIRST: return "CALL_FIRST";
            case ExecInstValue::PERCENT_OF_VOLUME: return "PERCENT_OF_VOLUME";
            case ExecInstValue::DO_NOT_INCREASE: return "DO_NOT_INCREASE";
            case ExecInstValue::DO_NOT_REDUCE: return "DO_NOT_REDUCE";
            case ExecInstValue::ALL_OR_NONE: return "ALL_OR_NONE";
            case ExecInstValue::INSTITUTIONS_ONLY: return "INSTITUTIONS_ONLY";
            case ExecInstValue::LAST_PEG: return "LAST_PEG";
            case ExecInstValue::MID_PRICE_PEG: return "MID_PRICE_PEG";
            case ExecInstValue::NON_NEGOTIABLE: return "NON_NEGOTIABLE";
            case ExecInstValue::OPENING_PEG: return "OPENING_PEG";
            case ExecInstValue::MARKET_PEG: return "MARKET_PEG";
            case ExecInstValue::PRIMARY_PEG: return "PRIMARY_PEG";
            case ExecInstValue::SUSPEND: return "SUSPEND";
            case ExecInstValue::FIXED_PEG_TO_LOCAL_BEST_BID_OR_OFFER: return "FIXED_PEG_TO_LOCAL_BEST_BID_OR_OFFER";
            case ExecInstValue::CUSTOMER_DISPLAY_INSTRUCTION: return "CUSTOMER_DISPLAY_INSTRUCTION";
            case ExecInstValue::NETTING: return "NETTING";
            case ExecInstValue::PEG_TO_VWAP: return "PEG_TO_VWAP";
            case ExecInstValue::TRADE_ALONG: return "TRADE_ALONG";
            case ExecInstValue::TRY_TO_STOP: return "TRY_TO_STOP";
            case ExecInstValue::CANCEL_IF_NOT_BEST: return "CANCEL_IF_NOT_BEST";
            case ExecInstValue::TRAILING_STOP_PEG: return "TRAILING_STOP_PEG";
            case ExecInstValue::STRICT_LIMIT: return "STRICT_LIMIT";
            case ExecInstValue::IGNORE_PRICE_VALIDITY_CHECKS: return "IGNORE_PRICE_VALIDITY_CHECKS";
            case ExecInstValue::PEG_TO_LIMIT_PRICE: return "PEG_TO_LIMIT_PRICE";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case ExecInstValue::STAY_ON_OFFERSIDE: return '0';
            case ExecInstValue::NOT_HELD: return '1';
            case ExecInstValue::WORK: return '2';
            case ExecInstValue::GO_ALONG: return '3';
            case ExecInstValue::OVER_THE_DAY: return '4';
            case ExecInstValue::HELD: return '5';
            case ExecInstValue::PARTICIPATE_DONT_INITIATE: return '6';
            case ExecInstValue::STRICT_SCALE: return '7';
            case ExecInstValue::TRY_TO_SCALE: return '8';
            case ExecInstValue::STAY_ON_BIDSIDE: return '9';
            case ExecInstValue::NO_CROSS: return 'A';
            case ExecInstValue::OK_TO_CROSS: return 'B';
            case ExecInstValue::CALL_FIRST: return 'C';
            case ExecInstValue::PERCENT_OF_VOLUME: return 'D';
            case ExecInstValue::DO_NOT_INCREASE: return 'E';
            case ExecInstValue::DO_NOT_REDUCE: return 'F';
            case ExecInstValue::ALL_OR_NONE: return 'G';
            case ExecInstValue::INSTITUTIONS_ONLY: return 'H';
            case ExecInstValue::LAST_PEG: return 'I';
            case ExecInstValue::MID_PRICE_PEG: return 'J';
            case ExecInstValue::NON_NEGOTIABLE: return 'K';
            case ExecInstValue::OPENING_PEG: return 'L';
            case ExecInstValue::MARKET_PEG: return 'M';
            case ExecInstValue::PRIMARY_PEG: return 'N';
            case ExecInstValue::SUSPEND: return 'O';
            case ExecInstValue::FIXED_PEG_TO_LOCAL_BEST_BID_OR_OFFER: return 'P';
            case ExecInstValue::CUSTOMER_DISPLAY_INSTRUCTION: return 'Q';
            case ExecInstValue::NETTING: return 'R';
            case ExecInstValue::PEG_TO_VWAP: return 'S';
            case ExecInstValue::TRADE_ALONG: return 'T';
            case ExecInstValue::TRY_TO_STOP: return 'U';
            case ExecInstValue::CANCEL_IF_NOT_BEST: return 'V';
            case ExecInstValue::TRAILING_STOP_PEG: return 'W';
            case ExecInstValue::STRICT_LIMIT: return 'X';
            case ExecInstValue::IGNORE_PRICE_VALIDITY_CHECKS: return 'Y';
            case ExecInstValue::PEG_TO_LIMIT_PRICE: return 'Z';
        }
        return char{};
    }

    static ExecInst fromRaw(char raw) {
        switch (raw) {
            case '0': return ExecInst(ExecInstValue::STAY_ON_OFFERSIDE);
            case '1': return ExecInst(ExecInstValue::NOT_HELD);
            case '2': return ExecInst(ExecInstValue::WORK);
            case '3': return ExecInst(ExecInstValue::GO_ALONG);
            case '4': return ExecInst(ExecInstValue::OVER_THE_DAY);
            case '5': return ExecInst(ExecInstValue::HELD);
            case '6': return ExecInst(ExecInstValue::PARTICIPATE_DONT_INITIATE);
            case '7': return ExecInst(ExecInstValue::STRICT_SCALE);
            case '8': return ExecInst(ExecInstValue::TRY_TO_SCALE);
            case '9': return ExecInst(ExecInstValue::STAY_ON_BIDSIDE);
            case 'A': return ExecInst(ExecInstValue::NO_CROSS);
            case 'B': return ExecInst(ExecInstValue::OK_TO_CROSS);
            case 'C': return ExecInst(ExecInstValue::CALL_FIRST);
            case 'D': return ExecInst(ExecInstValue::PERCENT_OF_VOLUME);
            case 'E': return ExecInst(ExecInstValue::DO_NOT_INCREASE);
            case 'F': return ExecInst(ExecInstValue::DO_NOT_REDUCE);
            case 'G': return ExecInst(ExecInstValue::ALL_OR_NONE);
            case 'H': return ExecInst(ExecInstValue::INSTITUTIONS_ONLY);
            case 'I': return ExecInst(ExecInstValue::LAST_PEG);
            case 'J': return ExecInst(ExecInstValue::MID_PRICE_PEG);
            case 'K': return ExecInst(ExecInstValue::NON_NEGOTIABLE);
            case 'L': return ExecInst(ExecInstValue::OPENING_PEG);
            case 'M': return ExecInst(ExecInstValue::MARKET_PEG);
            case 'N': return ExecInst(ExecInstValue::PRIMARY_PEG);
            case 'O': return ExecInst(ExecInstValue::SUSPEND);
            case 'P': return ExecInst(ExecInstValue::FIXED_PEG_TO_LOCAL_BEST_BID_OR_OFFER);
            case 'Q': return ExecInst(ExecInstValue::CUSTOMER_DISPLAY_INSTRUCTION);
            case 'R': return ExecInst(ExecInstValue::NETTING);
            case 'S': return ExecInst(ExecInstValue::PEG_TO_VWAP);
            case 'T': return ExecInst(ExecInstValue::TRADE_ALONG);
            case 'U': return ExecInst(ExecInstValue::TRY_TO_STOP);
            case 'V': return ExecInst(ExecInstValue::CANCEL_IF_NOT_BEST);
            case 'W': return ExecInst(ExecInstValue::TRAILING_STOP_PEG);
            case 'X': return ExecInst(ExecInstValue::STRICT_LIMIT);
            case 'Y': return ExecInst(ExecInstValue::IGNORE_PRICE_VALIDITY_CHECKS);
            case 'Z': return ExecInst(ExecInstValue::PEG_TO_LIMIT_PRICE);
        }
        throw std::invalid_argument("Unknown raw value for enum ExecInst");
    }

    static ExecInst fromName(const std::string& name) {
        if (name == "STAY_ON_OFFERSIDE") return ExecInst(ExecInstValue::STAY_ON_OFFERSIDE);
        if (name == "NOT_HELD") return ExecInst(ExecInstValue::NOT_HELD);
        if (name == "WORK") return ExecInst(ExecInstValue::WORK);
        if (name == "GO_ALONG") return ExecInst(ExecInstValue::GO_ALONG);
        if (name == "OVER_THE_DAY") return ExecInst(ExecInstValue::OVER_THE_DAY);
        if (name == "HELD") return ExecInst(ExecInstValue::HELD);
        if (name == "PARTICIPATE_DONT_INITIATE") return ExecInst(ExecInstValue::PARTICIPATE_DONT_INITIATE);
        if (name == "STRICT_SCALE") return ExecInst(ExecInstValue::STRICT_SCALE);
        if (name == "TRY_TO_SCALE") return ExecInst(ExecInstValue::TRY_TO_SCALE);
        if (name == "STAY_ON_BIDSIDE") return ExecInst(ExecInstValue::STAY_ON_BIDSIDE);
        if (name == "NO_CROSS") return ExecInst(ExecInstValue::NO_CROSS);
        if (name == "OK_TO_CROSS") return ExecInst(ExecInstValue::OK_TO_CROSS);
        if (name == "CALL_FIRST") return ExecInst(ExecInstValue::CALL_FIRST);
        if (name == "PERCENT_OF_VOLUME") return ExecInst(ExecInstValue::PERCENT_OF_VOLUME);
        if (name == "DO_NOT_INCREASE") return ExecInst(ExecInstValue::DO_NOT_INCREASE);
        if (name == "DO_NOT_REDUCE") return ExecInst(ExecInstValue::DO_NOT_REDUCE);
        if (name == "ALL_OR_NONE") return ExecInst(ExecInstValue::ALL_OR_NONE);
        if (name == "INSTITUTIONS_ONLY") return ExecInst(ExecInstValue::INSTITUTIONS_ONLY);
        if (name == "LAST_PEG") return ExecInst(ExecInstValue::LAST_PEG);
        if (name == "MID_PRICE_PEG") return ExecInst(ExecInstValue::MID_PRICE_PEG);
        if (name == "NON_NEGOTIABLE") return ExecInst(ExecInstValue::NON_NEGOTIABLE);
        if (name == "OPENING_PEG") return ExecInst(ExecInstValue::OPENING_PEG);
        if (name == "MARKET_PEG") return ExecInst(ExecInstValue::MARKET_PEG);
        if (name == "PRIMARY_PEG") return ExecInst(ExecInstValue::PRIMARY_PEG);
        if (name == "SUSPEND") return ExecInst(ExecInstValue::SUSPEND);
        if (name == "FIXED_PEG_TO_LOCAL_BEST_BID_OR_OFFER") return ExecInst(ExecInstValue::FIXED_PEG_TO_LOCAL_BEST_BID_OR_OFFER);
        if (name == "CUSTOMER_DISPLAY_INSTRUCTION") return ExecInst(ExecInstValue::CUSTOMER_DISPLAY_INSTRUCTION);
        if (name == "NETTING") return ExecInst(ExecInstValue::NETTING);
        if (name == "PEG_TO_VWAP") return ExecInst(ExecInstValue::PEG_TO_VWAP);
        if (name == "TRADE_ALONG") return ExecInst(ExecInstValue::TRADE_ALONG);
        if (name == "TRY_TO_STOP") return ExecInst(ExecInstValue::TRY_TO_STOP);
        if (name == "CANCEL_IF_NOT_BEST") return ExecInst(ExecInstValue::CANCEL_IF_NOT_BEST);
        if (name == "TRAILING_STOP_PEG") return ExecInst(ExecInstValue::TRAILING_STOP_PEG);
        if (name == "STRICT_LIMIT") return ExecInst(ExecInstValue::STRICT_LIMIT);
        if (name == "IGNORE_PRICE_VALIDITY_CHECKS") return ExecInst(ExecInstValue::IGNORE_PRICE_VALIDITY_CHECKS);
        if (name == "PEG_TO_LIMIT_PRICE") return ExecInst(ExecInstValue::PEG_TO_LIMIT_PRICE);
        throw std::invalid_argument("Unknown name for enum ExecInst: " + name);
    }

private:
    ExecInstValue value_;
};
} // namespace FIX::enumerations