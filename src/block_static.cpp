#include "block_static.h"

BlockStatic::BlockStatic(size_t sizeBlock)
    :_sizeBlock(sizeBlock)
{}

bool BlockStatic::Push(CommandPtr& command)
{
    _dequeCommand.push_back(std::move(command));
    if(_dequeCommand.size() == _sizeBlock)
        return false;

    return true;
}

bool BlockStatic::GetIgnore()
{
    return false;
}

void BlockStatic::SetIgnore(bool bIgnore)
{
    bIgnore = false; // We never ignore a static block.
    _bIgnore = bIgnore;
}