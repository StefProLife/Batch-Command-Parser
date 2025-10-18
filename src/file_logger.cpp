#include "file_logger.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

std::string Logger::_extension = ".log";
std::string Logger::_prefix = "bulk";
std::string Logger::_homeDir = InitPathHomeDir();
std::string Logger::_nameFolder = "Parser";

std::string Logger::InitPathHomeDir()
{
    fs::path homeDir;

#ifdef _WIN32
    if (const char* env_p = std::getenv("USERPROFILE"))
        homeDir = fs::path(env_p);
    else
        std::cerr << "Error: Could not determine home directory." << std::endl;
#else
    if (const char* env_p = std::getenv("HOME"))
        homeDir = fs::path(env_p);
    else
        std::cerr << "Error: Could not determine home directory." << std::endl;;
#endif

    return homeDir.string();
}

void Logger::Log(BlockPtr command)
{
    fs::path dirPath = _nameFolder;

    try
    {
        if (!fs::exists(dirPath))
        {
            fs::create_directory(dirPath);
            std::cout << "Directory created successfully: " << dirPath << std::endl;
        }
        else
        {
            std::cout << "Directory already exists: " << dirPath << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error creating directory: " << ex.what() << std::endl;
    }

    //// FIX_ME :: Переделать, должен принимать IBlock;
    //std::string strName = std::format("{}{}{}",
    //                                  Logger::_prefix,
    //                                  command.GetTime(),
    //                                  Logger::_extension);
    //std::ofstream logFile(strName);
    //if (logFile.is_open())
    //{
    //    logFile << command.GetCommnad();
    //    logFile.close();
    //}
}

const std::string& Logger::GetExtension()
{
    return Logger::_extension;
}

const std::string& Logger::GetPrefix()
{
    return Logger::_prefix;
}

const std::string& Logger::GetPathHome()
{
    return Logger::_homeDir;
}

const std::string& Logger::GetNameFolder()
{
    return Logger::_nameFolder;
}