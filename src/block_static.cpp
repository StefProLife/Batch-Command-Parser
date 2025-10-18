#include "block_static.h"

void BlockStatic::Push(CommandPtr& command)
{
    _queCommand.push_back(std::move(command));
}

size_t BlockStatic::GetSizeBlock()
{
    return _queCommand.size();
}