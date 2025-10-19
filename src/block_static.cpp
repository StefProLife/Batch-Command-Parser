#include "block_static.h"

BlockStatic::BlockStatic(size_t sizeBlock)
    :_sizeBlock(sizeBlock)
{}

bool BlockStatic::Push(CommandPtr& command)
{
    _dequeCommand.push_back(std::move(command));

    if (_dequeCommand.size() == _sizeBlock)
        return false;

    return true;
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