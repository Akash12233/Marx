// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from enumerations.xml by protocol/generator/generate.py
#pragma once

#include <cstdint>
#include <string>
#include <stdexcept>

namespace OUCH::enumerations {
enum class SideValue {
    BUY,
    SELL,
    SELL_SHORT,
    SELL_SHORT_EXEMPT
};

class Side {
public:
    explicit Side(SideValue v) : value_(v) {}

    SideValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case SideValue::BUY: return "BUY";
            case SideValue::SELL: return "SELL";
            case SideValue::SELL_SHORT: return "SELL_SHORT";
            case SideValue::SELL_SHORT_EXEMPT: return "SELL_SHORT_EXEMPT";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case SideValue::BUY: return 'B';
            case SideValue::SELL: return 'S';
            case SideValue::SELL_SHORT: return 'T';
            case SideValue::SELL_SHORT_EXEMPT: return 'E';
        }
        return char{};
    }

    static Side fromRaw(char raw) {
        switch (raw) {
            case 'B': return Side(SideValue::BUY);
            case 'S': return Side(SideValue::SELL);
            case 'T': return Side(SideValue::SELL_SHORT);
            case 'E': return Side(SideValue::SELL_SHORT_EXEMPT);
        }
        throw std::invalid_argument("Unknown raw value for enum Side");
    }

    static Side fromName(const std::string& name) {
        if (name == "BUY") return Side(SideValue::BUY);
        if (name == "SELL") return Side(SideValue::SELL);
        if (name == "SELL_SHORT") return Side(SideValue::SELL_SHORT);
        if (name == "SELL_SHORT_EXEMPT") return Side(SideValue::SELL_SHORT_EXEMPT);
        throw std::invalid_argument("Unknown name for enum Side: " + name);
    }

private:
    SideValue value_;
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
enum class DisplayValue {
    VISIBLE,
    HIDDEN,
    ATTRIBUTED
};

class Display {
public:
    explicit Display(DisplayValue v) : value_(v) {}

    DisplayValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case DisplayValue::VISIBLE: return "VISIBLE";
            case DisplayValue::HIDDEN: return "HIDDEN";
            case DisplayValue::ATTRIBUTED: return "ATTRIBUTED";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case DisplayValue::VISIBLE: return 'Y';
            case DisplayValue::HIDDEN: return 'N';
            case DisplayValue::ATTRIBUTED: return 'A';
        }
        return char{};
    }

    static Display fromRaw(char raw) {
        switch (raw) {
            case 'Y': return Display(DisplayValue::VISIBLE);
            case 'N': return Display(DisplayValue::HIDDEN);
            case 'A': return Display(DisplayValue::ATTRIBUTED);
        }
        throw std::invalid_argument("Unknown raw value for enum Display");
    }

    static Display fromName(const std::string& name) {
        if (name == "VISIBLE") return Display(DisplayValue::VISIBLE);
        if (name == "HIDDEN") return Display(DisplayValue::HIDDEN);
        if (name == "ATTRIBUTED") return Display(DisplayValue::ATTRIBUTED);
        throw std::invalid_argument("Unknown name for enum Display: " + name);
    }

private:
    DisplayValue value_;
};
enum class CapacityValue {
    AGENCY,
    PRINCIPAL,
    RISKLESS,
    OTHER
};

class Capacity {
public:
    explicit Capacity(CapacityValue v) : value_(v) {}

    CapacityValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case CapacityValue::AGENCY: return "AGENCY";
            case CapacityValue::PRINCIPAL: return "PRINCIPAL";
            case CapacityValue::RISKLESS: return "RISKLESS";
            case CapacityValue::OTHER: return "OTHER";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case CapacityValue::AGENCY: return 'A';
            case CapacityValue::PRINCIPAL: return 'P';
            case CapacityValue::RISKLESS: return 'R';
            case CapacityValue::OTHER: return 'O';
        }
        return char{};
    }

    static Capacity fromRaw(char raw) {
        switch (raw) {
            case 'A': return Capacity(CapacityValue::AGENCY);
            case 'P': return Capacity(CapacityValue::PRINCIPAL);
            case 'R': return Capacity(CapacityValue::RISKLESS);
            case 'O': return Capacity(CapacityValue::OTHER);
        }
        throw std::invalid_argument("Unknown raw value for enum Capacity");
    }

    static Capacity fromName(const std::string& name) {
        if (name == "AGENCY") return Capacity(CapacityValue::AGENCY);
        if (name == "PRINCIPAL") return Capacity(CapacityValue::PRINCIPAL);
        if (name == "RISKLESS") return Capacity(CapacityValue::RISKLESS);
        if (name == "OTHER") return Capacity(CapacityValue::OTHER);
        throw std::invalid_argument("Unknown name for enum Capacity: " + name);
    }

private:
    CapacityValue value_;
};
enum class IntermarketSweepEligibilityValue {
    ELIGIBLE,
    NOT_ELIGIBLE
};

class IntermarketSweepEligibility {
public:
    explicit IntermarketSweepEligibility(IntermarketSweepEligibilityValue v) : value_(v) {}

    IntermarketSweepEligibilityValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case IntermarketSweepEligibilityValue::ELIGIBLE: return "ELIGIBLE";
            case IntermarketSweepEligibilityValue::NOT_ELIGIBLE: return "NOT_ELIGIBLE";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case IntermarketSweepEligibilityValue::ELIGIBLE: return 'Y';
            case IntermarketSweepEligibilityValue::NOT_ELIGIBLE: return 'N';
        }
        return char{};
    }

    static IntermarketSweepEligibility fromRaw(char raw) {
        switch (raw) {
            case 'Y': return IntermarketSweepEligibility(IntermarketSweepEligibilityValue::ELIGIBLE);
            case 'N': return IntermarketSweepEligibility(IntermarketSweepEligibilityValue::NOT_ELIGIBLE);
        }
        throw std::invalid_argument("Unknown raw value for enum IntermarketSweepEligibility");
    }

    static IntermarketSweepEligibility fromName(const std::string& name) {
        if (name == "ELIGIBLE") return IntermarketSweepEligibility(IntermarketSweepEligibilityValue::ELIGIBLE);
        if (name == "NOT_ELIGIBLE") return IntermarketSweepEligibility(IntermarketSweepEligibilityValue::NOT_ELIGIBLE);
        throw std::invalid_argument("Unknown name for enum IntermarketSweepEligibility: " + name);
    }

private:
    IntermarketSweepEligibilityValue value_;
};
enum class CrossTypeValue {
    CONTINUOUS_MARKET,
    OPENING_CROSS,
    CLOSING_CROSS,
    IPO_CROSS,
    HALT_CROSS,
    RETAIL_CROSS
};

class CrossType {
public:
    explicit CrossType(CrossTypeValue v) : value_(v) {}

    CrossTypeValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case CrossTypeValue::CONTINUOUS_MARKET: return "CONTINUOUS_MARKET";
            case CrossTypeValue::OPENING_CROSS: return "OPENING_CROSS";
            case CrossTypeValue::CLOSING_CROSS: return "CLOSING_CROSS";
            case CrossTypeValue::IPO_CROSS: return "IPO_CROSS";
            case CrossTypeValue::HALT_CROSS: return "HALT_CROSS";
            case CrossTypeValue::RETAIL_CROSS: return "RETAIL_CROSS";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case CrossTypeValue::CONTINUOUS_MARKET: return 'N';
            case CrossTypeValue::OPENING_CROSS: return 'O';
            case CrossTypeValue::CLOSING_CROSS: return 'C';
            case CrossTypeValue::IPO_CROSS: return 'I';
            case CrossTypeValue::HALT_CROSS: return 'H';
            case CrossTypeValue::RETAIL_CROSS: return 'R';
        }
        return char{};
    }

    static CrossType fromRaw(char raw) {
        switch (raw) {
            case 'N': return CrossType(CrossTypeValue::CONTINUOUS_MARKET);
            case 'O': return CrossType(CrossTypeValue::OPENING_CROSS);
            case 'C': return CrossType(CrossTypeValue::CLOSING_CROSS);
            case 'I': return CrossType(CrossTypeValue::IPO_CROSS);
            case 'H': return CrossType(CrossTypeValue::HALT_CROSS);
            case 'R': return CrossType(CrossTypeValue::RETAIL_CROSS);
        }
        throw std::invalid_argument("Unknown raw value for enum CrossType");
    }

    static CrossType fromName(const std::string& name) {
        if (name == "CONTINUOUS_MARKET") return CrossType(CrossTypeValue::CONTINUOUS_MARKET);
        if (name == "OPENING_CROSS") return CrossType(CrossTypeValue::OPENING_CROSS);
        if (name == "CLOSING_CROSS") return CrossType(CrossTypeValue::CLOSING_CROSS);
        if (name == "IPO_CROSS") return CrossType(CrossTypeValue::IPO_CROSS);
        if (name == "HALT_CROSS") return CrossType(CrossTypeValue::HALT_CROSS);
        if (name == "RETAIL_CROSS") return CrossType(CrossTypeValue::RETAIL_CROSS);
        throw std::invalid_argument("Unknown name for enum CrossType: " + name);
    }

private:
    CrossTypeValue value_;
};
enum class OrderStateValue {
    NEW,
    LIVE,
    PARTIALLY_FILLED,
    FILLED,
    CANCEL_PENDING,
    CANCELED,
    REPLACED,
    REJECTED,
    EXPIRED,
    DONE_FOR_DAY
};

class OrderState {
public:
    explicit OrderState(OrderStateValue v) : value_(v) {}

    OrderStateValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case OrderStateValue::NEW: return "NEW";
            case OrderStateValue::LIVE: return "LIVE";
            case OrderStateValue::PARTIALLY_FILLED: return "PARTIALLY_FILLED";
            case OrderStateValue::FILLED: return "FILLED";
            case OrderStateValue::CANCEL_PENDING: return "CANCEL_PENDING";
            case OrderStateValue::CANCELED: return "CANCELED";
            case OrderStateValue::REPLACED: return "REPLACED";
            case OrderStateValue::REJECTED: return "REJECTED";
            case OrderStateValue::EXPIRED: return "EXPIRED";
            case OrderStateValue::DONE_FOR_DAY: return "DONE_FOR_DAY";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case OrderStateValue::NEW: return '0';
            case OrderStateValue::LIVE: return '1';
            case OrderStateValue::PARTIALLY_FILLED: return '2';
            case OrderStateValue::FILLED: return '3';
            case OrderStateValue::CANCEL_PENDING: return '4';
            case OrderStateValue::CANCELED: return '5';
            case OrderStateValue::REPLACED: return '6';
            case OrderStateValue::REJECTED: return '7';
            case OrderStateValue::EXPIRED: return '8';
            case OrderStateValue::DONE_FOR_DAY: return '9';
        }
        return char{};
    }

    static OrderState fromRaw(char raw) {
        switch (raw) {
            case '0': return OrderState(OrderStateValue::NEW);
            case '1': return OrderState(OrderStateValue::LIVE);
            case '2': return OrderState(OrderStateValue::PARTIALLY_FILLED);
            case '3': return OrderState(OrderStateValue::FILLED);
            case '4': return OrderState(OrderStateValue::CANCEL_PENDING);
            case '5': return OrderState(OrderStateValue::CANCELED);
            case '6': return OrderState(OrderStateValue::REPLACED);
            case '7': return OrderState(OrderStateValue::REJECTED);
            case '8': return OrderState(OrderStateValue::EXPIRED);
            case '9': return OrderState(OrderStateValue::DONE_FOR_DAY);
        }
        throw std::invalid_argument("Unknown raw value for enum OrderState");
    }

    static OrderState fromName(const std::string& name) {
        if (name == "NEW") return OrderState(OrderStateValue::NEW);
        if (name == "LIVE") return OrderState(OrderStateValue::LIVE);
        if (name == "PARTIALLY_FILLED") return OrderState(OrderStateValue::PARTIALLY_FILLED);
        if (name == "FILLED") return OrderState(OrderStateValue::FILLED);
        if (name == "CANCEL_PENDING") return OrderState(OrderStateValue::CANCEL_PENDING);
        if (name == "CANCELED") return OrderState(OrderStateValue::CANCELED);
        if (name == "REPLACED") return OrderState(OrderStateValue::REPLACED);
        if (name == "REJECTED") return OrderState(OrderStateValue::REJECTED);
        if (name == "EXPIRED") return OrderState(OrderStateValue::EXPIRED);
        if (name == "DONE_FOR_DAY") return OrderState(OrderStateValue::DONE_FOR_DAY);
        throw std::invalid_argument("Unknown name for enum OrderState: " + name);
    }

private:
    OrderStateValue value_;
};
enum class LiquidityFlagValue {
    ADDED,
    REMOVED,
    OPENING_CROSS,
    CLOSING_CROSS,
    HALT_CROSS,
    RETAIL,
    UNKNOWN
};

class LiquidityFlag {
public:
    explicit LiquidityFlag(LiquidityFlagValue v) : value_(v) {}

    LiquidityFlagValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case LiquidityFlagValue::ADDED: return "ADDED";
            case LiquidityFlagValue::REMOVED: return "REMOVED";
            case LiquidityFlagValue::OPENING_CROSS: return "OPENING_CROSS";
            case LiquidityFlagValue::CLOSING_CROSS: return "CLOSING_CROSS";
            case LiquidityFlagValue::HALT_CROSS: return "HALT_CROSS";
            case LiquidityFlagValue::RETAIL: return "RETAIL";
            case LiquidityFlagValue::UNKNOWN: return "UNKNOWN";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case LiquidityFlagValue::ADDED: return 'A';
            case LiquidityFlagValue::REMOVED: return 'R';
            case LiquidityFlagValue::OPENING_CROSS: return 'O';
            case LiquidityFlagValue::CLOSING_CROSS: return 'C';
            case LiquidityFlagValue::HALT_CROSS: return 'H';
            case LiquidityFlagValue::RETAIL: return 'T';
            case LiquidityFlagValue::UNKNOWN: return 'U';
        }
        return char{};
    }

    static LiquidityFlag fromRaw(char raw) {
        switch (raw) {
            case 'A': return LiquidityFlag(LiquidityFlagValue::ADDED);
            case 'R': return LiquidityFlag(LiquidityFlagValue::REMOVED);
            case 'O': return LiquidityFlag(LiquidityFlagValue::OPENING_CROSS);
            case 'C': return LiquidityFlag(LiquidityFlagValue::CLOSING_CROSS);
            case 'H': return LiquidityFlag(LiquidityFlagValue::HALT_CROSS);
            case 'T': return LiquidityFlag(LiquidityFlagValue::RETAIL);
            case 'U': return LiquidityFlag(LiquidityFlagValue::UNKNOWN);
        }
        throw std::invalid_argument("Unknown raw value for enum LiquidityFlag");
    }

    static LiquidityFlag fromName(const std::string& name) {
        if (name == "ADDED") return LiquidityFlag(LiquidityFlagValue::ADDED);
        if (name == "REMOVED") return LiquidityFlag(LiquidityFlagValue::REMOVED);
        if (name == "OPENING_CROSS") return LiquidityFlag(LiquidityFlagValue::OPENING_CROSS);
        if (name == "CLOSING_CROSS") return LiquidityFlag(LiquidityFlagValue::CLOSING_CROSS);
        if (name == "HALT_CROSS") return LiquidityFlag(LiquidityFlagValue::HALT_CROSS);
        if (name == "RETAIL") return LiquidityFlag(LiquidityFlagValue::RETAIL);
        if (name == "UNKNOWN") return LiquidityFlag(LiquidityFlagValue::UNKNOWN);
        throw std::invalid_argument("Unknown name for enum LiquidityFlag: " + name);
    }

private:
    LiquidityFlagValue value_;
};
enum class EventCodeValue {
    START_OF_DAY,
    END_OF_DAY,
    START_OF_SYSTEM,
    END_OF_SYSTEM
};

class EventCode {
public:
    explicit EventCode(EventCodeValue v) : value_(v) {}

    EventCodeValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case EventCodeValue::START_OF_DAY: return "START_OF_DAY";
            case EventCodeValue::END_OF_DAY: return "END_OF_DAY";
            case EventCodeValue::START_OF_SYSTEM: return "START_OF_SYSTEM";
            case EventCodeValue::END_OF_SYSTEM: return "END_OF_SYSTEM";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case EventCodeValue::START_OF_DAY: return 'S';
            case EventCodeValue::END_OF_DAY: return 'E';
            case EventCodeValue::START_OF_SYSTEM: return 'A';
            case EventCodeValue::END_OF_SYSTEM: return 'Z';
        }
        return char{};
    }

    static EventCode fromRaw(char raw) {
        switch (raw) {
            case 'S': return EventCode(EventCodeValue::START_OF_DAY);
            case 'E': return EventCode(EventCodeValue::END_OF_DAY);
            case 'A': return EventCode(EventCodeValue::START_OF_SYSTEM);
            case 'Z': return EventCode(EventCodeValue::END_OF_SYSTEM);
        }
        throw std::invalid_argument("Unknown raw value for enum EventCode");
    }

    static EventCode fromName(const std::string& name) {
        if (name == "START_OF_DAY") return EventCode(EventCodeValue::START_OF_DAY);
        if (name == "END_OF_DAY") return EventCode(EventCodeValue::END_OF_DAY);
        if (name == "START_OF_SYSTEM") return EventCode(EventCodeValue::START_OF_SYSTEM);
        if (name == "END_OF_SYSTEM") return EventCode(EventCodeValue::END_OF_SYSTEM);
        throw std::invalid_argument("Unknown name for enum EventCode: " + name);
    }

private:
    EventCodeValue value_;
};
enum class RejectReasonValue {
    UNKNOWN,
    INVALID_SYMBOL,
    INVALID_PRICE,
    INVALID_QUANTITY,
    UNKNOWN_ORDER,
    DUPLICATE_ORDER,
    ORDER_ALREADY_CLOSED,
    INVALID_TIME_IN_FORCE,
    INVALID_SIDE,
    INSUFFICIENT_PERMISSIONS,
    RISK_REJECT,
    SYSTEM_ERROR
};

class RejectReason {
public:
    explicit RejectReason(RejectReasonValue v) : value_(v) {}

    RejectReasonValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case RejectReasonValue::UNKNOWN: return "UNKNOWN";
            case RejectReasonValue::INVALID_SYMBOL: return "INVALID_SYMBOL";
            case RejectReasonValue::INVALID_PRICE: return "INVALID_PRICE";
            case RejectReasonValue::INVALID_QUANTITY: return "INVALID_QUANTITY";
            case RejectReasonValue::UNKNOWN_ORDER: return "UNKNOWN_ORDER";
            case RejectReasonValue::DUPLICATE_ORDER: return "DUPLICATE_ORDER";
            case RejectReasonValue::ORDER_ALREADY_CLOSED: return "ORDER_ALREADY_CLOSED";
            case RejectReasonValue::INVALID_TIME_IN_FORCE: return "INVALID_TIME_IN_FORCE";
            case RejectReasonValue::INVALID_SIDE: return "INVALID_SIDE";
            case RejectReasonValue::INSUFFICIENT_PERMISSIONS: return "INSUFFICIENT_PERMISSIONS";
            case RejectReasonValue::RISK_REJECT: return "RISK_REJECT";
            case RejectReasonValue::SYSTEM_ERROR: return "SYSTEM_ERROR";
        }
        return "";
    }

    int raw() const {
        switch (value_) {
            case RejectReasonValue::UNKNOWN: return 0;
            case RejectReasonValue::INVALID_SYMBOL: return 1;
            case RejectReasonValue::INVALID_PRICE: return 2;
            case RejectReasonValue::INVALID_QUANTITY: return 3;
            case RejectReasonValue::UNKNOWN_ORDER: return 4;
            case RejectReasonValue::DUPLICATE_ORDER: return 5;
            case RejectReasonValue::ORDER_ALREADY_CLOSED: return 6;
            case RejectReasonValue::INVALID_TIME_IN_FORCE: return 7;
            case RejectReasonValue::INVALID_SIDE: return 8;
            case RejectReasonValue::INSUFFICIENT_PERMISSIONS: return 9;
            case RejectReasonValue::RISK_REJECT: return 10;
            case RejectReasonValue::SYSTEM_ERROR: return 11;
        }
        return int{};
    }

    static RejectReason fromRaw(int raw) {
        switch (raw) {
            case 0: return RejectReason(RejectReasonValue::UNKNOWN);
            case 1: return RejectReason(RejectReasonValue::INVALID_SYMBOL);
            case 2: return RejectReason(RejectReasonValue::INVALID_PRICE);
            case 3: return RejectReason(RejectReasonValue::INVALID_QUANTITY);
            case 4: return RejectReason(RejectReasonValue::UNKNOWN_ORDER);
            case 5: return RejectReason(RejectReasonValue::DUPLICATE_ORDER);
            case 6: return RejectReason(RejectReasonValue::ORDER_ALREADY_CLOSED);
            case 7: return RejectReason(RejectReasonValue::INVALID_TIME_IN_FORCE);
            case 8: return RejectReason(RejectReasonValue::INVALID_SIDE);
            case 9: return RejectReason(RejectReasonValue::INSUFFICIENT_PERMISSIONS);
            case 10: return RejectReason(RejectReasonValue::RISK_REJECT);
            case 11: return RejectReason(RejectReasonValue::SYSTEM_ERROR);
        }
        throw std::invalid_argument("Unknown raw value for enum RejectReason");
    }

    static RejectReason fromName(const std::string& name) {
        if (name == "UNKNOWN") return RejectReason(RejectReasonValue::UNKNOWN);
        if (name == "INVALID_SYMBOL") return RejectReason(RejectReasonValue::INVALID_SYMBOL);
        if (name == "INVALID_PRICE") return RejectReason(RejectReasonValue::INVALID_PRICE);
        if (name == "INVALID_QUANTITY") return RejectReason(RejectReasonValue::INVALID_QUANTITY);
        if (name == "UNKNOWN_ORDER") return RejectReason(RejectReasonValue::UNKNOWN_ORDER);
        if (name == "DUPLICATE_ORDER") return RejectReason(RejectReasonValue::DUPLICATE_ORDER);
        if (name == "ORDER_ALREADY_CLOSED") return RejectReason(RejectReasonValue::ORDER_ALREADY_CLOSED);
        if (name == "INVALID_TIME_IN_FORCE") return RejectReason(RejectReasonValue::INVALID_TIME_IN_FORCE);
        if (name == "INVALID_SIDE") return RejectReason(RejectReasonValue::INVALID_SIDE);
        if (name == "INSUFFICIENT_PERMISSIONS") return RejectReason(RejectReasonValue::INSUFFICIENT_PERMISSIONS);
        if (name == "RISK_REJECT") return RejectReason(RejectReasonValue::RISK_REJECT);
        if (name == "SYSTEM_ERROR") return RejectReason(RejectReasonValue::SYSTEM_ERROR);
        throw std::invalid_argument("Unknown name for enum RejectReason: " + name);
    }

private:
    RejectReasonValue value_;
};
enum class MassCancelScopeValue {
    ALL_ORDERS,
    BY_SYMBOL,
    BY_SIDE,
    BY_ACCOUNT,
    BY_SESSION
};

class MassCancelScope {
public:
    explicit MassCancelScope(MassCancelScopeValue v) : value_(v) {}

    MassCancelScopeValue value() const { return value_; }

    std::string toString() const {
        switch (value_) {
            case MassCancelScopeValue::ALL_ORDERS: return "ALL_ORDERS";
            case MassCancelScopeValue::BY_SYMBOL: return "BY_SYMBOL";
            case MassCancelScopeValue::BY_SIDE: return "BY_SIDE";
            case MassCancelScopeValue::BY_ACCOUNT: return "BY_ACCOUNT";
            case MassCancelScopeValue::BY_SESSION: return "BY_SESSION";
        }
        return "";
    }

    char raw() const {
        switch (value_) {
            case MassCancelScopeValue::ALL_ORDERS: return 'A';
            case MassCancelScopeValue::BY_SYMBOL: return 'S';
            case MassCancelScopeValue::BY_SIDE: return 'D';
            case MassCancelScopeValue::BY_ACCOUNT: return 'C';
            case MassCancelScopeValue::BY_SESSION: return 'T';
        }
        return char{};
    }

    static MassCancelScope fromRaw(char raw) {
        switch (raw) {
            case 'A': return MassCancelScope(MassCancelScopeValue::ALL_ORDERS);
            case 'S': return MassCancelScope(MassCancelScopeValue::BY_SYMBOL);
            case 'D': return MassCancelScope(MassCancelScopeValue::BY_SIDE);
            case 'C': return MassCancelScope(MassCancelScopeValue::BY_ACCOUNT);
            case 'T': return MassCancelScope(MassCancelScopeValue::BY_SESSION);
        }
        throw std::invalid_argument("Unknown raw value for enum MassCancelScope");
    }

    static MassCancelScope fromName(const std::string& name) {
        if (name == "ALL_ORDERS") return MassCancelScope(MassCancelScopeValue::ALL_ORDERS);
        if (name == "BY_SYMBOL") return MassCancelScope(MassCancelScopeValue::BY_SYMBOL);
        if (name == "BY_SIDE") return MassCancelScope(MassCancelScopeValue::BY_SIDE);
        if (name == "BY_ACCOUNT") return MassCancelScope(MassCancelScopeValue::BY_ACCOUNT);
        if (name == "BY_SESSION") return MassCancelScope(MassCancelScopeValue::BY_SESSION);
        throw std::invalid_argument("Unknown name for enum MassCancelScope: " + name);
    }

private:
    MassCancelScopeValue value_;
};
} // namespace OUCH::enumerations