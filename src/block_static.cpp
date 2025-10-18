#include "block_static.h"

void BlockStatic::Push(CommandPtr& command)
{
    _queueCommand.push(std::move(command));
}

CommandPtr BlockStatic::Get()
{
    auto command = _queueCommand.front();
    _queueCommand.pop();
    return command;
}

size_t BlockStatic::GetSizeBlock()
{
    return _queueCommand.size();
}