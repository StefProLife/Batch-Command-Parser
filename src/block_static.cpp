#include "block_static.h"

bool BlockStatic::Push(CommandPtr& command)
{
    if (command->GetCommnad() == "EOF")
    {
        return false;
    }
    else if (command->GetCommnad() == "{")
    {
        if(_nested == 0) return false;
        _nested++;
    }
    else if (command->GetCommnad() == "}")
    {
        _nested--;
        if (_nested == 0) return false;
    }

    _dequeCommand.push_back(std::move(command));

    if (_dequeCommand.size() == _size && _nested == 0)
        return false;

    return true;
}

void BlockStatic::SetSizeBlock(size_t size)
{
    _size = size;
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