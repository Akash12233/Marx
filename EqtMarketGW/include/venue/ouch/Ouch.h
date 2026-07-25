#pragma once

#include "abstract/VenueSession.h"
#include "protocol/ouch/Ouch.h"
#include "protocol/ouch/OuchDecoder.h"
#include "protocol/ouch/OuchEncoder.h"

#include "abstract/ConfigLoader.h"

namespace marx {
class Router;
}

namespace marx::venue::ouch {

class OuchVenue : public VenueSession {
public:
    OuchVenue(SessionContext ctx, Router* router = nullptr);
    OuchVenue(const ConfigLoader& config, const std::string& prefix, Router* router = nullptr);
    ~OuchVenue() override = default;

    // CDM Routing Interface (Polymorphic dispatch overrides)
    void routeCDM(const MODEL::messages::NewOrderRequest& msg) override;
    void routeCDM(const MODEL::messages::ReplaceOrderRequest& msg) override;
    void routeCDM(const MODEL::messages::CancelOrderRequest& msg) override;

protected:
    // From VenueSession
    void respondToLogon() override;
    void onConnected() override;

    // From Session
    void onData(const char* data, std::size_t len) override;

private:
    void handleIncomingMessage(const marx::ouch::OuchMessage& msg);

    // Composed protocol components
    marx::ouch::Ouch             ouch_;
    marx::ouch::OuchDecoder      decoder_;
    marx::ouch::OuchEncoder      encoder_;
    
    Router* router_ = nullptr;
};

} // namespace marx::venue::ouch
