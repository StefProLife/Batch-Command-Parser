#pragma once

#include <iostream>
#include <chrono>

class ICommand
{
public:
    virtual ~ICommand()= default;
public:
    virtual const std::string& GetCommnad() = 0;
    virtual const std::string& GetTime() = 0;
};

using CommandPtr = std::unique_ptr<ICommand>;