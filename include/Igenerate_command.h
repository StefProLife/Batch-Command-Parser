#pragma once

#include <memory>

class ICommand;

class IGenerateCommand
{
public:
    virtual ~IGenerateCommand() = default;
public:
    virtual ICommand* CreateCommnad() = 0;
};

using GenerateCommandPtr = std::unique_ptr<IGenerateCommand>;