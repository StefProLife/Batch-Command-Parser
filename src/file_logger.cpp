#include "file_logger.h"
#include <fstream>

std::string Logger::_extension = ".log";
std::string Logger::_prefix = "bulk";

void Logger::Log(ICommand& command)
{
    // FIX_ME :: Переделать, должен принимать IBlock;
    std::string strName = std::format("{}{}{}",
                                      Logger::_prefix,
                                      command.GetTime(),
                                      Logger::_extension);
    std::ofstream logFile(strName);
    if (logFile.is_open())
    {
        logFile << command.GetCommnad();
        logFile.close();
    }
}

const std::string& Logger::GetExtension()
{
    return  Logger::_extension;
}

const std::string& Logger::GetPrefix()
{
    return  Logger::_prefix;
}