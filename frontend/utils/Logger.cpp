//
// Created by Alexandru Pestritu on 23.11.2024.
//
#include "Logger.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>

std::string Logger::getTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    std::ostringstream timestamp;
    timestamp << std::put_time(std::localtime(&now_time_t), "%Y-%m-%d %H:%M:%S")
              << "." << std::setfill('0') << std::setw(3) << now_ms.count();
    return timestamp.str();
}

void Logger::logError(const std::string& message) {
    std::cerr<< getTimestamp() << " " << message << std::endl;
}
