#pragma once

#include "abstract/SessionContext.h"
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <algorithm>

namespace marx {

class ConfigLoader {
public:
    explicit ConfigLoader(const std::string& filepath) {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            std::cerr << "Warning: Could not open config file " << filepath << ", using defaults.\n";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            // Trim and skip comments/empty lines
            trim(line);
            if (line.empty() || line[0] == '#' || line[0] == ';') {
                continue;
            }

            auto eq = line.find('=');
            if (eq != std::string::npos) {
                std::string key = line.substr(0, eq);
                std::string val = line.substr(eq + 1);
                trim(key);
                trim(val);
                config_[key] = val;
            }
        }
    }

    std::string get(const std::string& key, const std::string& defaultVal) const {
        auto it = config_.find(key);
        return (it != config_.end()) ? it->second : defaultVal;
    }

    int getInt(const std::string& key, int defaultVal) const {
        auto it = config_.find(key);
        if (it != config_.end()) {
            try {
                return std::stoi(it->second);
            } catch (...) {}
        }
        return defaultVal;
    }

    bool loadSession(const std::string& prefix, SessionContext& ctx) const {
        ctx.sessionId = get(prefix + ".sessionId", ctx.sessionId);
        ctx.host = get(prefix + ".host", ctx.host);
        ctx.port = static_cast<std::uint16_t>(getInt(prefix + ".port", ctx.port));
        ctx.senderCompId = get(prefix + ".senderCompId", ctx.senderCompId);
        ctx.targetCompId = get(prefix + ".targetCompId", ctx.targetCompId);
        ctx.protocol = get(prefix + ".protocol", ctx.protocol);
        ctx.heartbeatIntervalSecs = getInt(prefix + ".heartbeatIntervalSecs", ctx.heartbeatIntervalSecs);
        ctx.reconnectDelaySecs = getInt(prefix + ".reconnectDelaySecs", ctx.reconnectDelaySecs);
        ctx.maxReconnectAttempts = getInt(prefix + ".maxReconnectAttempts", ctx.maxReconnectAttempts);
        ctx.isVenue = get(prefix + ".isVenue", ctx.isVenue ? "true" : "false") == "true" || getInt(prefix + ".isVenue", 0) != 0;
        return !ctx.sessionId.empty();
    }

private:
    static void trim(std::string& s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    std::unordered_map<std::string, std::string> config_;
};

} // namespace marx
