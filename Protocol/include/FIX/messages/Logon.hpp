// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "FIX/fields/Fields.hpp"

namespace FIX::messages {

class Logon {
public:
    Logon() = default;

    const FIX::fields::EncryptMethod& getEncryptMethod() const { return encryptMethod_; }
    void setEncryptMethod(const FIX::fields::EncryptMethod& v) { encryptMethod_ = v; }
    const FIX::fields::HeartBtInt& getHeartBtInt() const { return heartBtInt_; }
    void setHeartBtInt(const FIX::fields::HeartBtInt& v) { heartBtInt_ = v; }
    const FIX::fields::ResetSeqNumFlag& getResetSeqNumFlag() const { return resetSeqNumFlag_; }
    void setResetSeqNumFlag(const FIX::fields::ResetSeqNumFlag& v) { resetSeqNumFlag_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads Logon::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "EncryptMethod", true },
        { "HeartBtInt", true },
        { "ResetSeqNumFlag", false },
    };

private:
    FIX::fields::EncryptMethod encryptMethod_;
    FIX::fields::HeartBtInt heartBtInt_;
    FIX::fields::ResetSeqNumFlag resetSeqNumFlag_;
};

} // namespace FIX::messages