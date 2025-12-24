#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream>

class Logger {
private:
    std::ofstream logFile;
    std::time_t startTime;

public:
    Logger();
    ~Logger();
    
    void log(const std::string& operation, const std::string& details = "");
    void logError(const std::string& operation, const std::string& error);
};

// ГЛОБАЛЬНЫЙ МАКРОС — используй везде!
#define LOG(operation, details) logger.log(operation, details)
#define LOG_ERROR(operation, error) logger.logError(operation, error)
