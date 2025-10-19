#pragma once

#include <string>
#include "block.h"

class DynamicBlock : public Block
{
 public:
    DynamicBlock() = default;
public:
    bool Push(CommandPtr& command) override;
private:
    size_t _numberNested = 0;
};