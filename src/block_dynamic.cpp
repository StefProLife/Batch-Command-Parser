#include "block_dynamic.h"

bool DynamicBlock::Push(CommandPtr& command)
{
    _dequeCommand.push_back(std::move(command));
    return true;
}

bool DynamicBlock::GetIgnore()
{
    return _bIgnore;
}

void DynamicBlock::SetIgnore(bool bIgnore)
{
    _bIgnore = bIgnore;
}