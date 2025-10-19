#pragma once

#include <memory>
#include <deque>
#include "Icommand.h"

class IBlock
{
public:
    virtual ~IBlock() = default;
public:
    virtual bool Push(CommandPtr& command) = 0;
    virtual bool GetIgnore() = 0;
    virtual void SetIgnore(bool bIgnore) = 0;
    virtual size_t GetSizeBlock() = 0;
    virtual const std::deque<CommandPtr>& GetCommands() = 0;
    virtual void Clear() = 0;
    virtual bool Empty() = 0;
};

using BlockPtr = std::shared_ptr<IBlock>;