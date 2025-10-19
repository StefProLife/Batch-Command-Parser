#include "block_dynamic.h"

bool DynamicBlock::Push(CommandPtr& command)
{
    if (command->GetCommnad() == _strEOF)
    {
        _dequeCommand.clear();
        return false;
    }
    else if (command->GetCommnad() == _beginDynamicBlock)
    {
        _numberNested++;
        return true;
    }
    else if (command->GetCommnad() == _endDynamicBlock)
    {
        _numberNested--;
        if (_numberNested != 0)
            return true;
        else
            return false;
    }

    _dequeCommand.push_back(std::move(command));

    return true;
}