#include "config.h"
#include "logger.h"
#include <fstream>
#include <iostream>

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

std::string Config::getSSLCertPath() const {
    return configData["server"]["ssl_cert"];
}

std::string Config::getSSLKeyPath() const {
    return configData["server"]["ssl_key"];
}
