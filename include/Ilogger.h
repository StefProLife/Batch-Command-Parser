#pragma once

#include <string>
#include <memory>
#include "Iblock.h"

class ILogger
{
public:
    virtual ~ILogger() = default;
public:
    void virtual Log(BlockPtr command) = 0;
    const virtual std::string& GetExtension() = 0;
    const virtual std::string& GetPrefix() = 0;
    const virtual std::string& GetPathHome() = 0;
    const virtual std::string& GetNameFolder() = 0;
};

using LoggerPtr = std::unique_ptr<ILogger>;