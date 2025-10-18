#include "network_adapter.h"
#include "Icommand.h"
#include "Iblock.h"

NetworkAdapter::NetworkAdapter(GenerateCommandPtr generateCommand, GenerateBolckPtr generateBolck, ReaderPtr reader, const size_t& countPackageInBolock)
    : _reader(std::move(reader)),
     _generateCommand(std::move(generateCommand)),
     _generateBolck(std::move(generateBolck)),
     _countPackageInBolock(countPackageInBolock)
{}

void NetworkAdapter::ReadPackage()
{
    IBlock* pBlock = _generateBolck->CreateBlock();
    for (size_t i = 0; i < _countPackageInBolock; i++)
    {
        ICommand* pCommand = _generateCommand->CreateCommnad();
        pCommand->SetCommnad(_reader->Read());
        CommandPtr commandPtr = std::unique_ptr<ICommand>(pCommand);
        pBlock->Push(commandPtr);
    }
}

const size_t& NetworkAdapter::GetCountPackageInBolock()
{
    return _countPackageInBolock;
}

const ReaderPtr& NetworkAdapter::GetReader() const
{
    return _reader;
}