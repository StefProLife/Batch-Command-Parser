#pragma once

#include <memory>

class IBlock;

class IGenerateBlock
{
public:
    virtual ~IGenerateBlock() = default;
public:
    virtual IBlock* CreateBlock() = 0;
};

using GenerateBlockPtr = std::unique_ptr<IGenerateBlock>;