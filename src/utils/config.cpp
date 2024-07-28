#include "config.h"
#include "logger.h"
#include <fstream>

Config::Config(const std::string& filepath) : filepath(filepath) {}

bool Config::load() {
    std::ifstream configFile(filepath, std::ifstream::binary);
    if (!configFile.is_open()) {
        Logger::error("Cannot open configuration file: " + filepath);
        return false;
    }

    configFile >> configData;
    Logger::info("Configuration loaded from: " + filepath);
    return true;
}
