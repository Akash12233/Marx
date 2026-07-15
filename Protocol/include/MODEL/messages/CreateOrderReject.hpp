// AUTO-GENERATED FILE - DO NOT EDIT BY HAND
// Generated from payloads.xml by protocol/generator/generate.py
#pragma once

#include "MODEL/fields/Fields.hpp"

namespace MODEL::messages {

class CreateOrderReject {
public:
    CreateOrderReject() = default;

    const MODEL::fields::ClientOrderId& getClientOrderId() const { return clientOrderId_; }
    void setClientOrderId(const MODEL::fields::ClientOrderId& v) { clientOrderId_ = v; }
    const MODEL::fields::VenueOrderId& getVenueOrderId() const { return venueOrderId_; }
    void setVenueOrderId(const MODEL::fields::VenueOrderId& v) { venueOrderId_ = v; }
    const MODEL::fields::ExecutionId& getExecutionId() const { return executionId_; }
    void setExecutionId(const MODEL::fields::ExecutionId& v) { executionId_ = v; }
    const MODEL::fields::ExecutionType& getExecutionType() const { return executionType_; }
    void setExecutionType(const MODEL::fields::ExecutionType& v) { executionType_ = v; }
    const MODEL::fields::OrderStatus& getOrderStatus() const { return orderStatus_; }
    void setOrderStatus(const MODEL::fields::OrderStatus& v) { orderStatus_ = v; }
    const MODEL::fields::OrderQty& getOrderQty() const { return orderQty_; }
    void setOrderQty(const MODEL::fields::OrderQty& v) { orderQty_ = v; }
    const MODEL::fields::FilledQuantity& getFilledQuantity() const { return filledQuantity_; }
    void setFilledQuantity(const MODEL::fields::FilledQuantity& v) { filledQuantity_ = v; }
    const MODEL::fields::RemainingQuantity& getRemainingQuantity() const { return remainingQuantity_; }
    void setRemainingQuantity(const MODEL::fields::RemainingQuantity& v) { remainingQuantity_ = v; }
    const MODEL::fields::AveragePrice& getAveragePrice() const { return averagePrice_; }
    void setAveragePrice(const MODEL::fields::AveragePrice& v) { averagePrice_ = v; }
    const MODEL::fields::Text& getText() const { return text_; }
    void setText(const MODEL::fields::Text& v) { text_ = v; }
    const MODEL::fields::RejectReason& getRejectReason() const { return rejectReason_; }
    void setRejectReason(const MODEL::fields::RejectReason& v) { rejectReason_ = v; }

    // Field metadata (required / defaultValue) is intentionally not enforced
    // here - validation happens in the decoder / execution engine, which
    // reads CreateOrderReject::Meta below.
    struct FieldMeta { const char* name; bool required; };
    static constexpr FieldMeta Meta[] = {
        { "ClientOrderId", false },
        { "VenueOrderId", false },
        { "ExecutionId", false },
        { "ExecutionType", false },
        { "OrderStatus", false },
        { "OrderQty", false },
        { "FilledQuantity", false },
        { "RemainingQuantity", false },
        { "AveragePrice", false },
        { "Text", false },
        { "RejectReason", false },
    };

private:
    MODEL::fields::ClientOrderId clientOrderId_;
    MODEL::fields::VenueOrderId venueOrderId_;
    MODEL::fields::ExecutionId executionId_;
    MODEL::fields::ExecutionType executionType_;
    MODEL::fields::OrderStatus orderStatus_;
    MODEL::fields::OrderQty orderQty_;
    MODEL::fields::FilledQuantity filledQuantity_;
    MODEL::fields::RemainingQuantity remainingQuantity_;
    MODEL::fields::AveragePrice averagePrice_;
    MODEL::fields::Text text_;
    MODEL::fields::RejectReason rejectReason_;
};

} // namespace MODEL::messages