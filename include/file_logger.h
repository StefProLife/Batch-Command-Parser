#pragma once

#include "Ilogger.h"

class Logger : public ILogger
{
public:
    static ILogger& GetInstance()
    {
        static Logger instance;
        return instance;
    }
public:
    void Log(ICommand& command) override;
    const std::string& GetExtension() override;
    const std::string& GetPrefix() override;
private:
    static std::string _extension;
    static std::string _prefix;
private:
    Logger() = default;
    ~Logger() = default;
private:
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger &operator=(const Logger&) = delete;
    Logger &operator=(Logger&&) = delete;
};