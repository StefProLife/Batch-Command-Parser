#include "file_logger.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <format>

namespace fs = std::filesystem;

std::string Logger::_extension = ".log";
std::string Logger::_prefix = "bulk";
std::string Logger::_homeDir = InitPathHomeDir();
std::string Logger::_nameFolder = "Parser";

// Ћоги в данный момент сохран€ютс€ в р€дом с приложением.
// ѕо большому счету все сделано, дл€ того чтобы сохран€ть в папке пользовател€.
// Ќет возможности спокойно отладитьс€ на 2-х системах.
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

void Logger::Log(BlockPtr block)
{
    if(block->Empty()) return;
    if (block->GetIgnore()) return;

    fs::path dirPath = _nameFolder;

    try
    {
        if (!fs::exists(dirPath)) fs::create_directory(dirPath);
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error creating directory: " << ex.what() << std::endl;
    }

    const auto& commands = block->GetCommands();
    std::string strName = std::format("{}{}{}",
        Logger::_prefix,
        (*commands.begin())->GetTick(),
        Logger::_extension);

    std::ofstream logFile(strName);

    if (logFile.is_open())
    {
        // TODO :: ѕо-хорошему сделать бы проход по IBlock, но не хочетс€ оборачивать
        // итератор.
        for (const auto& it : commands)
            logFile << std::format("{} | {}", it->GetDataTime(), it->GetCommnad()) << std::endl;
    }

    logFile.close();
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