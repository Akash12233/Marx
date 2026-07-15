// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "OUCH/fields/Fields.hpp"

namespace OUCH::messages {

class AccountQueryRequest {
public:
    AccountQueryRequest() = default;

    const OUCH::fields::Account& getAccount() const { return account_; }
    void setAccount(const OUCH::fields::Account& v) { account_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads AccountQueryRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "Account", false },
    };

private:
    OUCH::fields::Account account_;
};

} // namespace OUCH::messages