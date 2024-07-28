#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <nlohmann/json.hpp> 

class Config {
public:
    Config(const std::string& filepath);
    bool load();
    // Add more configuration-related methods

private:
    std::string filepath;
    nlohmann::json configData;
};

#endif // CONFIG_H
