#pragma once

#include <string>
#include "block.h"

class DynamicBlock : public Block
{
 public:
    DynamicBlock() = default;
public:
    bool Push(CommandPtr& command) override;
    bool GetIgnore() override;
    void SetIgnore(bool bIgnore) override;
};