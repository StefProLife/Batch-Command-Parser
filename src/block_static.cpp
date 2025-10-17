#include "block_static.h"

void BlockStatic::Push(CommandPtr& command)
{
    _dequeCommand.push_back(std::move(command));
}

size_t BlockStatic::GetSizeBlock()
{
    return _dequeCommand.size();
}