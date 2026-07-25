#pragma once

#include "abstract/ClientSession.h"
#include "protocol/fix/Fix.h"
#include "protocol/fix/SequenceManager.h"
#include "protocol/fix/HeartbeatManager.h"
#include "protocol/fix/FixDecoder.h"
#include "protocol/fix/FixEncoder.h"

#include "abstract/ConfigLoader.h"

namespace marx {
class Router;
}

namespace marx::client::fix {

class FixClient : public ClientSession {
public:
    explicit FixClient(SessionContext ctx, Router* router = nullptr);
    FixClient(const ConfigLoader& config, const std::string& prefix, Router* router = nullptr);
    ~FixClient() override;

    // CDM Routing Interface (Polymorphic dispatch overrides)
    void routeCDM(const MODEL::messages::CreateOrderExecution& msg) override;
    void routeCDM(const MODEL::messages::CreateOrderReject& msg) override;
    void routeCDM(const MODEL::messages::ReplaceOrderExecution& msg) override;
    void routeCDM(const MODEL::messages::ReplaceOrderReject& msg) override;
    void routeCDM(const MODEL::messages::CancelOrderExecution& msg) override;
    void routeCDM(const MODEL::messages::CancelOrderReject& msg) override;
    void routeCDM(const MODEL::messages::FillOrderExecution& msg) override;

    // Expose for testing/data feed
    void onData(const char* data, std::size_t len) override;

protected:
    // From ClientSession
    void initiateLogon() override;

private:
    void handleIncomingMessage(const marx::fix::FixMessage& msg);
    void sendAdminMessage(const std::string& msgType, const std::vector<marx::fix::FixField>& bodyFields = {});

    // Composed protocol components
    marx::fix::Fix             fix_;
    marx::fix::SequenceManager  seqManager_;
    marx::fix::HeartbeatManager hbManager_;
    marx::fix::FixDecoder       decoder_;
    marx::fix::FixEncoder       encoder_;

    Router* router_ = nullptr;
};

} // namespace marx::client::fix
