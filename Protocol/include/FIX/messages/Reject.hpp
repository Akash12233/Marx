// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class Reject {
public:
    Reject() = default;

    const FIX::fields::RefSeqNum& getRefSeqNum() const { return refSeqNum_; }
    void setRefSeqNum(const FIX::fields::RefSeqNum& v) { refSeqNum_ = v; }
    const FIX::fields::RefTagID& getRefTagID() const { return refTagID_; }
    void setRefTagID(const FIX::fields::RefTagID& v) { refTagID_ = v; }
    const FIX::fields::RefMsgType& getRefMsgType() const { return refMsgType_; }
    void setRefMsgType(const FIX::fields::RefMsgType& v) { refMsgType_ = v; }
    const FIX::fields::SessionRejectReason& getSessionRejectReason() const { return sessionRejectReason_; }
    void setSessionRejectReason(const FIX::fields::SessionRejectReason& v) { sessionRejectReason_ = v; }
    const FIX::fields::Text& getText() const { return text_; }
    void setText(const FIX::fields::Text& v) { text_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads Reject::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "RefSeqNum", true },
        { "RefTagID", false },
        { "RefMsgType", false },
        { "SessionRejectReason", false },
        { "Text", false },
    };

private:
    FIX::fields::RefSeqNum refSeqNum_;
    FIX::fields::RefTagID refTagID_;
    FIX::fields::RefMsgType refMsgType_;
    FIX::fields::SessionRejectReason sessionRejectReason_;
    FIX::fields::Text text_;
};

} // namespace FIX::messages