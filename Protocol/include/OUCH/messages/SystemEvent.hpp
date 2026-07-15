// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "OUCH/fields/Fields.hpp"

namespace OUCH::messages {

class SystemEvent {
public:
    SystemEvent() = default;

    const OUCH::fields::Timestamp& getTimestamp() const { return timestamp_; }
    void setTimestamp(const OUCH::fields::Timestamp& v) { timestamp_ = v; }
    const OUCH::fields::EventCode& getEventCode() const { return eventCode_; }
    void setEventCode(const OUCH::fields::EventCode& v) { eventCode_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads SystemEvent::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "Timestamp", false },
        { "EventCode", false },
    };

private:
    OUCH::fields::Timestamp timestamp_;
    OUCH::fields::EventCode eventCode_;
};

} // namespace OUCH::messages