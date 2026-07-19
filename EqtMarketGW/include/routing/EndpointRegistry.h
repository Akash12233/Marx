#pragma once

#include "abstract/Session.h"
#include <string>
#include <unordered_map>

namespace marx {

class EndpointRegistry {
public:
    EndpointRegistry() = default;

    void registerSession(const std::string& id, Session* session);
    void unregisterSession(const std::string& id);
    Session* lookup(const std::string& id);

private:
    std::unordered_map<std::string, Session*> sessions_;
};

} // namespace marx
