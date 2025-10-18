#pragma once

#include "network_adapter.h"
#include "Icommand.h"
#include "Iblock.h"

NetworkAdapter::NetworkAdapter(IGenerateCommand* pGenerateCommand, IGenerateBlock* pGenerateBolck, IReader* pReader, const size_t& countPackageInBolock)
    : _generateCommand(GenerateCommandPtr(pGenerateCommand)),
      _generateBolck(GenerateBlockPtr(pGenerateBolck)),
      _reader(ReaderPtr(pReader)),
      _countPackageInBolock(countPackageInBolock)
{}

BlockPtr NetworkAdapter::ReadPackage()
{
    if (_countPackageInBolock == 0)
        throw std::invalid_argument("_countPackageInBolock don't be equal 0");

    IBlock* pBlock = _generateBolck->CreateBlock();
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