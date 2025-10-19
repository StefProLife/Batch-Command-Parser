#pragma once

#include <string>
#include "Iblock.h"

class BlockStatic : public IBlock
{
public:
    BlockStatic(size_t sizeBlock);
public:
    bool Push(CommandPtr& command) override;
    size_t GetSizeBlock() override;
    const std::deque<CommandPtr>& GetCommands() override;
    void Clear() override;
    bool Empty() override;
private:
    std::deque<CommandPtr> _dequeCommand;
    size_t _sizeBlock = 3; // default number
};