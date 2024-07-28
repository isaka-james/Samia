#include "server/http3_server.h"
#include "utils/logger.h"
#include <thread>
#include <chrono>

Http3Server::Http3Server(const Config& config) : config(config), running(false) {}

Http3Server::~Http3Server() {}

bool Http3Server::initialize() {
    // Initialization logic
    Logger::info("Server initialized");
    return true;
}

void Http3Server::start() {
    running = true;
    Logger::info("Server started");
    run();
}

void Http3Server::run() {
    while (running) {
        // Simulate server work (e.g., handling connections)
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Http3Server::stop() {
    running = false;
}
