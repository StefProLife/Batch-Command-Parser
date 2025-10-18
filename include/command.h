#pragma once

#include "Icommand.h"

class Command : public ICommand
{
public:
    Command() = default;
public:
    void SetCommnad(const std::string& name) override;
    const std::string& GetCommnad() override;
    const std::string& GetDataTime() override;
    long long GetTick() override;
private:
    std::string _command;
    std::string _time;
    long long _tick;
};
