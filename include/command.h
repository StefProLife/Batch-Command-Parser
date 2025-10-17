#pragma once

#include "Icommand.h"

class Command : public ICommand
{
public:
    Command(const std::string& name);
public:
    const std::string& GetCommnad() override;
    const std::string& GetTime() override;
private:
    std::string _command;
    std::string _time;
};
