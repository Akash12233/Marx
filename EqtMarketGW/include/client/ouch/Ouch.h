#pragma once

#include "abstract/ClientSession.h"
#include "protocol/ouch/Ouch.h"
#include "protocol/ouch/OuchDecoder.h"
#include "protocol/ouch/OuchEncoder.h"

#include "abstract/ConfigLoader.h"

namespace marx {
class Router;
}

namespace marx::client::ouch {

class OuchClient : public ClientSession {
public:
    OuchClient(SessionContext ctx, Router* router = nullptr);
    OuchClient(const ConfigLoader& config, const std::string& prefix, Router* router = nullptr);
    ~OuchClient() override = default;

    // CDM Routing Interface (Polymorphic dispatch overrides)
    void routeCDM(const MODEL::messages::NewOrderRequest& msg) override;
    void routeCDM(const MODEL::messages::ReplaceOrderRequest& msg) override;
    void routeCDM(const MODEL::messages::CancelOrderRequest& msg) override;

protected:
    // From ClientSession
    void initiateLogon() override;

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

} // namespace marx::client::ouch
