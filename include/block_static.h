#pragma once

#include "Iblock.h"
#include <queue>

class BlockStatic : public IBlock
{
public:
    BlockStatic() = default;
public:
    void Push(CommandPtr& command) override;
    size_t GetSizeBlock() override;
private:
    std::queue<CommandPtr> _queueCommand;
};