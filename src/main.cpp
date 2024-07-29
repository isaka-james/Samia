#include <iostream>
#include <thread>
#include <chrono>
// #include <string>
// #include <vector>
// #include <memory>
#include "server/http3_server.h"
#include "utils/logger.h"
#include "utils/config.h"

int main(int argc, char* argv[]) {
    // Load server configuration
    Config config("../config/server_config.json");
    if (!config.load()) {
        Logger::error("Failed to load configuration");
        return 1;
    }

    // Initialize the server
    Http3Server server(config);
    if (!server.initialize()) {
        Logger::error("Failed to initialize the server");
        return 1;
    }

    // Start the server
    server.start();

    // Prevent the main thread from exiting
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}