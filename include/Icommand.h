#pragma once

#include <iostream>
#include <chrono>

class ICommand
{
public:
    virtual ~ICommand()= default;
public:
    virtual void SetCommnad(const std::string& name) = 0;
    virtual const std::string& GetCommnad() = 0;
    virtual const std::string& GetDataTime() = 0;
    virtual long long GetTick() = 0;
};

using CommandPtr = std::shared_ptr<ICommand>;