#pragma once

#include <string>
#include "block.h"

class BlockStatic : public Block
{
public:
    BlockStatic() = default;
    BlockStatic(size_t sizeBlock);
public:
    bool Push(CommandPtr& command) override;
    bool GetIgnore() override;
    void SetIgnore(bool bIgnore) override;
private:
    size_t _sizeBlock = 3; // default number
};