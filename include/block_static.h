#pragma once

#include "Iblock.h"

class BlockStatic : public IBlock
{
public:
    BlockStatic() = default;
public:
    void Push(CommandPtr& command) override;
    size_t GetSizeBlock() override;
    const std::deque<CommandPtr>& GetCommands() override;
    void Clear() override;
private:
    std::deque<CommandPtr> _dequeCommand;
};