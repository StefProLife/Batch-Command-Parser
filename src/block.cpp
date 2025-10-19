#include "block.h"

size_t Block::GetSizeBlock()
{
    return _dequeCommand.size();
}

const std::deque<CommandPtr>& Block::GetCommands()
{
    return _dequeCommand;
}

void Block::Clear()
{
    _dequeCommand.clear();
}

bool Block::Empty()
{
    return _dequeCommand.empty();
}