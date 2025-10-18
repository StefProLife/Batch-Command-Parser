#include "block_static.h"

void BlockStatic::Push(CommandPtr& command)
{
    _queueCommand.push(std::move(command));
}

size_t BlockStatic::GetSizeBlock()
{
    return _queueCommand.size();
}