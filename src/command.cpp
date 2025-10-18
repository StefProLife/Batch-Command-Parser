#include "command.h"

void Command::SetCommnad(const std::string& name)
{
    auto nowClock = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(nowClock);

    _command = name;
    _time = std::ctime(&time);
    _time.erase(std::remove(_time.begin(), _time.end(), '\n'), _time.end());

    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(time);
    auto duration = timePoint.time_since_epoch();
    _tick = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

const std::string& Command::GetCommnad()
{
    return _command;
}

const std::string& Command::GetDataTime()
{
    return _time;
}

long long Command::GetTick()
{
    return _tick;
}
