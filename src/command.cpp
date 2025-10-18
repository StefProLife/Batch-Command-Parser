#include "command.h"

void Command::SetCommnad(const std::string& name)
{
    auto nowClock = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(nowClock);

    _command = name;
    _time = std::ctime(&time);
}

const std::string& Command::GetCommnad()
{
    return _command;
}

const std::string& Command::GetTime()
{
    return _time;
}