#pragma once

#include "Iblock.h"

class DynamicBlock : public IBlock
{
 public:
    DynamicBlock() = default;
public:
    bool Push(CommandPtr& command) override;
};