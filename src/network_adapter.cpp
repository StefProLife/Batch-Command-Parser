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

    BlockType type = static_cast<BlockType>(_numberNested);
    IBlock* pBlock = makeBlock(type);
    if (!pBlock)
        throw std::runtime_error("Undefined error");

    bool next = false;

    do
    {
        std::string strLine = _reader->Read();

        if (strLine == _strEOF && _numberNested != 0)
        {
            pBlock->SetIgnore(true);
            _numberNested = 0;
            break;
        }
        else if (strLine == _strEOF)
        {
            break;
        }
        else if (strLine == _beginDynamicBlock)
        {
            _numberNested++;
            if (_numberNested == 1) break; // begin dynamic block
            continue; // don't add symbol "{" to the block
        }
        else if (strLine == _endDynamicBlock)
        {
            _numberNested--;
            if (_numberNested == 0) break; // end dynamic block
            continue; // don't add symbol "}" to the block
        }

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