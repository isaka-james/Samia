#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    static void info(const std::string& message);
    static void error(const std::string& message);
    // Add more logging levels if needed
};

#endif // LOGGER_H
