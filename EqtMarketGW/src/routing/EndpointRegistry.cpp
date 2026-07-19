#include "routing/EndpointRegistry.h"

namespace marx {

void EndpointRegistry::registerSession(const std::string& id, Session* session) {
    sessions_[id] = session;
}

void EndpointRegistry::unregisterSession(const std::string& id) {
    sessions_.erase(id);
}

Session* EndpointRegistry::lookup(const std::string& id) {
    auto it = sessions_.find(id);
    if (it != sessions_.end()) {
        return it->second;
    }
    return nullptr;
}

} // namespace marx
