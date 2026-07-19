#include "abstract/Logger.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>

namespace marx {

Logger& Logger::instance() {
    static Logger inst;
    return inst;
}

Logger::~Logger() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (clientStream_.is_open()) clientStream_.close();
    if (venueStream_.is_open()) venueStream_.close();
    if (appStream_.is_open()) appStream_.close();
}

void Logger::init(const std::string& clientFile, const std::string& venueFile, const std::string& appFile) {
    std::lock_guard<std::mutex> lock(mutex_);
    
    if (clientStream_.is_open()) clientStream_.close();
    clientStream_.open(clientFile, std::ios::out | std::ios::app);
    if (!clientStream_.is_open()) {
        std::cerr << "Failed to open client log file: " << clientFile << "\n";
    }

    if (venueStream_.is_open()) venueStream_.close();
    venueStream_.open(venueFile, std::ios::out | std::ios::app);
    if (!venueStream_.is_open()) {
        std::cerr << "Failed to open venue log file: " << venueFile << "\n";
    }

    if (appStream_.is_open()) appStream_.close();
    appStream_.open(appFile, std::ios::out | std::ios::app);
    if (!appStream_.is_open()) {
        std::cerr << "Failed to open application log file: " << appFile << "\n";
    }
}

std::string Logger::getTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S")
       << '.' << std::setfill('0') << std::setw(3) << ms.count();
    return ss.str();
}

std::string Logger::levelToString(Level level) {
    switch (level) {
        case Level::INFO: return "INFO";
        case Level::WARNING: return "WARN";
        case Level::ERROR: return "ERROR";
        case Level::DEBUG: return "DEBG";
    }
    return "UNKN";
}

void Logger::logClient(const std::string& direction, const std::string& sessionId, const std::string& message) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::string line = "[" + getTimestamp() + "] [" + direction + "] [" + sessionId + "] " + message + "\n";
    if (clientStream_.is_open()) {
        clientStream_ << line;
        clientStream_.flush();
    }
    std::cout << "[CLIENT] " << line;
}

void Logger::logVenue(const std::string& direction, const std::string& sessionId, const std::string& message) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::string line = "[" + getTimestamp() + "] [" + direction + "] [" + sessionId + "] " + message + "\n";
    if (venueStream_.is_open()) {
        venueStream_ << line;
        venueStream_.flush();
    }
    std::cout << "[VENUE] " << line;
}

void Logger::logApp(Level level, const std::string& component, const std::string& message) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::string line = "[" + getTimestamp() + "] [" + levelToString(level) + "] [" + component + "] " + message + "\n";
    if (appStream_.is_open()) {
        appStream_ << line;
        appStream_.flush();
    }
    std::cout << line;
}

} // namespace marx
