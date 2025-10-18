#include "block_static.h"

void BlockStatic::Push(CommandPtr& command)
{
    _dequeCommand.push_back(std::move(command));
}

size_t BlockStatic::GetSizeBlock()
{
    return _dequeCommand.size();
}

const std::deque<CommandPtr>& BlockStatic::GetCommands()
{
    return _dequeCommand;
}

void BlockStatic::Clear()
{
    _dequeCommand.clear();
}

bool BlockStatic::Empty()
{
    return _dequeCommand.empty();
}