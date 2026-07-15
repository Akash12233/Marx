// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "MODEL/fields/Fields.hpp"

namespace MODEL::messages {

class CancelOrderRequest {
public:
    CancelOrderRequest() = default;

    const MODEL::fields::ClientOrderId& getClientOrderId() const { return clientOrderId_; }
    void setClientOrderId(const MODEL::fields::ClientOrderId& v) { clientOrderId_ = v; }
    const MODEL::fields::OriginalClientOrderId& getOriginalClientOrderId() const { return originalClientOrderId_; }
    void setOriginalClientOrderId(const MODEL::fields::OriginalClientOrderId& v) { originalClientOrderId_ = v; }
    const MODEL::fields::Symbol& getSymbol() const { return symbol_; }
    void setSymbol(const MODEL::fields::Symbol& v) { symbol_ = v; }
    const MODEL::fields::Side& getSide() const { return side_; }
    void setSide(const MODEL::fields::Side& v) { side_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads CancelOrderRequest::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "ClientOrderId", false },
        { "OriginalClientOrderId", false },
        { "Symbol", false },
        { "Side", false },
    };

private:
    MODEL::fields::ClientOrderId clientOrderId_;
    MODEL::fields::OriginalClientOrderId originalClientOrderId_;
    MODEL::fields::Symbol symbol_;
    MODEL::fields::Side side_;
};

} // namespace MODEL::messages