#include "block_static.h"

BlockStatic::BlockStatic(size_t sizeBlock)
    :_sizeBlock(sizeBlock)
{}

bool BlockStatic::Push(CommandPtr& command)
{
    _dequeCommand.push_back(std::move(command));

    if (command->GetCommnad() == _strEOF)
        return false;
    if (command->GetCommnad() == _beginDynamicBlock)
        return false;
    else if(_dequeCommand.size() == _sizeBlock)
        return false;

    return true;
}