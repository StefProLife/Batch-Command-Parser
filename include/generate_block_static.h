#pragma once

#include "Igenerate_block.h"

class GenerateBolckStatic : public IGenerateBolck
{
public:
    GenerateBolckStatic() = default;
public:
    IBlock* CreateBlock() override;
};