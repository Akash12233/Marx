#pragma once

#include "abstract/ClientSession.h"
#include "protocol/fix/Fix.h"
#include "protocol/fix/SequenceManager.h"
#include "protocol/fix/HeartbeatManager.h"
#include "protocol/fix/FixDecoder.h"
#include "protocol/fix/FixEncoder.h"

#include "abstract/ConfigLoader.h"

namespace marx::client::fix {

class FixClient : public ClientSession {
public:
    explicit FixClient(SessionContext ctx);
    FixClient(const ConfigLoader& config, const std::string& prefix);
    ~FixClient() override;

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
};

} // namespace marx::client::fix
