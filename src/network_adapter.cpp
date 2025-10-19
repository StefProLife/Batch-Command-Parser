#pragma once

#include "network_adapter.h"
#include "Icommand.h"
#include "block_static.h"
#include "block_dynamic.h"

NetworkAdapter::NetworkAdapter(IGenerateCommand* pGenerateCommand, IReader* pReader, const size_t& countPackageInBolock)
    : _generateCommand(pGenerateCommand),
      _reader(ReaderPtr(pReader)),
      _countPackageInBolock(countPackageInBolock)
{}

BlockPtr NetworkAdapter::ReadPackage()
{
    if (_countPackageInBolock == 0)
        throw std::invalid_argument("_countPackageInBolock don't be equal 0");

    IBlock* pBlock = makeBlock(BlockType::staticBlock);
    if (!pBlock)
        throw std::runtime_error("Undefined error");

    bool next = false;

    do
    {
        std::string strLine = _reader->Read();
        ICommand* pCommand = _generateCommand->CreateCommnad();
        pCommand->SetCommnad(strLine);
        CommandPtr commandPtr = CommandPtr(pCommand);
        next = pBlock->Push(commandPtr);
    } while (next);

    BlockPtr blockPtr = BlockPtr(pBlock);
    return blockPtr;
}

const size_t& NetworkAdapter::GetCountPackageInBolock()
{
    return _countPackageInBolock;
}

const ReaderPtr& NetworkAdapter::GetReader() const
{
    return _reader;
}

IBlock* NetworkAdapter::makeBlock(BlockType type)
{
    switch (type)
    {
        case BlockType::staticBlock:
        {
            return new BlockStatic(_countPackageInBolock);
        }
        case BlockType::dynamicBlock:
        {
            return new DynamicBlock();
        }
        default:
        {
            return nullptr;
        }
    }
}