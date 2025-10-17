#pragma once

#include "Iblock.h"
#include <deque>

class BlockStatic : public IBlock
{
public:
    BlockStatic() = default;
public:
    void Push(CommandPtr& command) override;
    size_t GetSizeBlock() override;
private:
    std::deque<CommandPtr> _dequeCommand;
};