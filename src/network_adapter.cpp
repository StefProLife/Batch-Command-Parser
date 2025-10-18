#pragma once

#include "network_adapter.h"
#include "Icommand.h"
#include "Iblock.h"

NetworkAdapter::NetworkAdapter(IGenerateCommand* pGenerateCommand, IGenerateBolck* pGenerateBolck, IReader* pReader, const size_t& countPackageInBolock)
    : _generateCommand(GenerateCommandPtr(pGenerateCommand)),
      _generateBolck(GenerateBolckPtr(pGenerateBolck)),
      _reader(ReaderPtr(pReader)),
      _countPackageInBolock(countPackageInBolock)
{}

BlockPtr NetworkAdapter::ReadPackage()
{
    IBlock* pBlock = _generateBolck->CreateBlock();
    for (size_t i = 0; i < _countPackageInBolock; i++)
    {
        std::string strLine = _reader->Read();
        ICommand* pCommand = _generateCommand->CreateCommnad();
        pCommand->SetCommnad(strLine);
        CommandPtr commandPtr = CommandPtr(pCommand);
        pBlock->Push(commandPtr);
    }

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