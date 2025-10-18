#include "network_adapter.h"
#include "Icommand.h"

NetworkAdapter::NetworkAdapter(GenerateCommandPtr _generateCommand, ReaderPtr reader, const size_t& countPackageInBolock)
    : _reader(std::move(reader)),
     _generateCommand(std::move(_generateCommand)),
     _countPackageInBolock(countPackageInBolock)
{}

void NetworkAdapter::ReadPackage()
{
    for (size_t i = 0; i < _countPackageInBolock; i++)
    {
        ICommand* command = _generateCommand->CreateCommnad();
        command->SetCommnad(_reader->Read());
        //block->Push(_reader->Read());
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