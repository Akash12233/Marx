#include "abstract/SessionContext.h"
#include "abstract/ConfigLoader.h"
#include "routing/OrderStore.h"
#include "routing/OrderLifecycleEngine.h"
#include "routing/EndpointRegistry.h"
#include "routing/Router.h"
#include "client/fix/Fix.h"
#include "venue/ouch/Ouch.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>
#include <atomic>

#include "abstract/Logger.h"

// Flag to coordinate graceful shutdown on SIGINT/SIGTERM
std::atomic<bool> g_running{true};

void signalHandler(int signum) {
    marx::LOG_WARN("System", "Signal (" + std::to_string(signum) + ") received. Initiating graceful shutdown...");
    g_running = false;
}

int main(int argc, char** argv) {
    // Initialize central Logger
    marx::Logger::instance().init("client_messages.log", "venue_messages.log", "application.log");
    
    marx::LOG_INFO("System", "Starting Marx Execution Management System...");

    // Register signal handlers for clean exit
    std::signal(SIGINT, signalHandler);
    std::signal(SIGTERM, signalHandler);

    // Resolve config filepath
    std::string configPath = "gateway.conf";
    if (argc > 1) {
        configPath = argv[1];
    }
    marx::LOG_INFO("System", "Loading configuration from: " + configPath);

    try {
        // 1. Initialize central EMS core
        marx::LOG_INFO("System", "Initializing EMS Core components...");
        marx::OrderStore store;
        marx::OrderLifecycleEngine engine(store);
        marx::EndpointRegistry registry;
        marx::Router router(registry, engine, store);

        // 2. Load configurations via ConfigLoader
        marx::ConfigLoader config(configPath);

        // 3. Instantiate Sessions directly from config
        marx::LOG_INFO("System", "Creating FIX Client Session...");
        marx::client::fix::FixClient fixClient(config, "fix", &router);
        registry.registerSession(fixClient.context().sessionId, &fixClient);

        marx::LOG_INFO("System", "Creating OUCH Venue Session...");
        marx::venue::ouch::OuchVenue ouchClient(config, "ouch", &router);
        registry.registerSession(ouchClient.context().sessionId, &ouchClient);

        // Configure routing destinations
        std::string defaultVenue = config.get("router.defaultVenueSessionId", ouchClient.context().sessionId);
        marx::LOG_INFO("System", "Setting default router venue destination to: " + defaultVenue);
        router.setVenueSessionId(defaultVenue);

        // 4. Start Sessions (each spins up its own background event loop thread)
        marx::LOG_INFO("System", "Starting FIX Session I/O loop...");
        fixClient.start();

        marx::LOG_INFO("System", "Starting OUCH Session I/O loop...");
        ouchClient.start();

        marx::LOG_INFO("System", "EMS Gateway started successfully. Press Ctrl+C to terminate.");
        marx::LOG_INFO("System", "--------------------------------------------------");

        // Keep main thread alive and monitor session states
        while (g_running) {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            
            // Log runtime state of active sessions
            std::stringstream ss;
            ss << fixClient.context().sessionId << ": " << toString(fixClient.state()) 
               << " (Sent=" << fixClient.stats().messagesSent.load() 
               << ", Recv=" << fixClient.stats().messagesReceived.load() << ") | "
               << ouchClient.context().sessionId << ": " << toString(ouchClient.state()) 
               << " (Sent=" << ouchClient.stats().messagesSent.load() 
               << ", Recv=" << ouchClient.stats().messagesReceived.load() << ")";
            marx::LOG_INFO("Status", ss.str());
        }

        // 5. Tear down and stop background loops gracefully
        marx::LOG_INFO("System", "Stopping active sessions...");
        fixClient.stop();
        ouchClient.stop();
        
        marx::LOG_INFO("System", "Unregistering endpoints...");
        registry.unregisterSession(fixClient.context().sessionId);
        registry.unregisterSession(ouchClient.context().sessionId);

        marx::LOG_INFO("System", "EMS Gateway stopped cleanly.");
    }
    catch (const std::exception& e) {
        marx::LOG_ERROR("System", "FATAL ERROR during gateway execution: " + std::string(e.what()));
        return 1;
    }

    return 0;
}
