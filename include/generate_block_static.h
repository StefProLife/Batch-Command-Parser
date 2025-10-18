#pragma once

#include "Igenerate_block.h"

class GenerateBlockStatic : public IGenerateBlock
{
public:
    GenerateBlockStatic() = default;
public:
    IBlock* CreateBlock() override;
};