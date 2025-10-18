#pragma once

#include <string>
#include "Iblock.h"

class BlockStatic : public IBlock
{
public:
    BlockStatic() = default;
public:
    bool Push(CommandPtr& command) override;
    void SetSizeBlock(size_t size) override;
    size_t GetSizeBlock() override;
    const std::deque<CommandPtr>& GetCommands() override;
    void Clear() override;
    bool Empty() override;
private:
    std::deque<CommandPtr> _dequeCommand;
    size_t _nested;
    size_t _size = 3; // default number
};