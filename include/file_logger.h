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
    void Log(BlockPtr command) override;
    const std::string& GetExtension() override;
    const std::string& GetPrefix() override;
    const std::string& GetPathHome() override;
    const std::string& GetNameFolder() override;
private:
    static std::string _extension;
    static std::string _prefix;
    static std::string _homeDir;
    static std::string _nameFolder;
private:
    static std::string InitPathHomeDir();
private:
    Logger() = default;
    ~Logger() = default;
private:
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger &operator=(const Logger&) = delete;
    Logger &operator=(Logger&&) = delete;
};