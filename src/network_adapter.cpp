#include "network_adapter.h"
#include "Icommand.h"
#include "Iblock.h"

NetworkAdapter::NetworkAdapter(GenerateCommandPtr generateCommand, GenerateBolckPtr generateBolck, ReaderPtr reader, const size_t& countPackageInBolock)
    : _reader(std::move(reader)),
     _generateCommand(std::move(generateCommand)),
     _generateBolck(std::move(generateBolck)),
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