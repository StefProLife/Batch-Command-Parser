#pragma once

#include<Icommand.h>

class IBlock
{
public:
    virtual ~IBlock() = default;
public:
    virtual void Push(CommandPtr& command) = 0;
    virtual size_t GetSizeBlock() = 0;
};