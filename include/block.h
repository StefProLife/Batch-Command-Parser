#pragma once

#include "Iblock.h"

class Block : public IBlock
{
public:
    virtual ~Block() = default;
public:
    virtual bool Push(CommandPtr& command) = 0;
    size_t GetSizeBlock() override;
    const std::deque<CommandPtr>& GetCommands() override;
    void Clear() override;
    bool Empty() override;
protected:
    std::deque<CommandPtr> _dequeCommand;
};
