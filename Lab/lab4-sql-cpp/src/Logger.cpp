#include "../include/Logger.h"
#include <sstream>

Logger::Logger() {
    logFile.open("log.txt", std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Warning: Cannot open log.txt for writing\n";
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(const std::string& operation, const std::string& details) {
    auto now = std::time(nullptr);
    auto tm = *std::localtime(&now);
    
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << " | "
        << operation << " | " << details << '\n';
    
    std::cout << oss.str();  // также выводим в консоль
    
    if (logFile.is_open()) {
        logFile << oss.str();
        logFile.flush();
    }
}

void Logger::logError(const std::string& operation, const std::string& error) {
    log("ERROR: " + operation, error);
}