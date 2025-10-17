#include "network_adapter.h"

NetworkAdapter::NetworkAdapter(ReaderPtr reader, size_t countPackageInBolock)
    : _reader(std::move(reader)), _countPackageInBolock(countPackageInBolock)
{}

void NetworkAdapter::ReadPackage()
{

}

size_t NetworkAdapter::GetCountPackageInBolock()
{
    return _countPackageInBolock;
}

const ReaderPtr& NetworkAdapter::GetReader() const
{
    return _reader;
}