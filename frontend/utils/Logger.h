//
// Created by Alexandru Pestritu on 23.11.2024.
//

#ifndef LOGGER_H
#define LOGGER_H
#include <string>

class Logger {
public:
    static std::string getTimestamp();
    static void logError(const std::string& message);
};

#endif //LOGGER_H
