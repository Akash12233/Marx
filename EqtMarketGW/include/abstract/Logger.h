#pragma once

#include <string>
#include <fstream>
#include <mutex>

namespace marx {

class Logger {
public:
    enum class Level {
        INFO,
        WARNING,
        ERROR,
        DEBUG
    };

    static Logger& instance();

    // Initialize the logger files
    void init(const std::string& clientFile, const std::string& venueFile, const std::string& appFile);

    // Log client-side messages (incoming/outgoing wire data or CDM equivalents)
    void logClient(const std::string& direction, const std::string& sessionId, const std::string& message);

    // Log venue-side messages (incoming/outgoing wire data or CDM equivalents)
    void logVenue(const std::string& direction, const std::string& sessionId, const std::string& message);

    // Log general application level messages (info, warning, error)
    void logApp(Level level, const std::string& component, const std::string& message);

private:
    Logger() = default;
    ~Logger();
    
    // Prevent copy/move
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

    std::string getTimestamp();
    std::string levelToString(Level level);

    std::ofstream clientStream_;
    std::ofstream venueStream_;
    std::ofstream appStream_;

    std::mutex mutex_;
};

// Convenience macros/functions for application logs
inline void LOG_INFO(const std::string& comp, const std::string& msg) {
    Logger::instance().logApp(Logger::Level::INFO, comp, msg);
}

inline void LOG_WARN(const std::string& comp, const std::string& msg) {
    Logger::instance().logApp(Logger::Level::WARNING, comp, msg);
}

inline void LOG_ERROR(const std::string& comp, const std::string& msg) {
    Logger::instance().logApp(Logger::Level::ERROR, comp, msg);
}

inline void LOG_DEBUG(const std::string& comp, const std::string& msg) {
    Logger::instance().logApp(Logger::Level::DEBUG, comp, msg);
}

} // namespace marx
