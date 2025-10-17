#include "network_adapter.h"

NetworkAdapter::NetworkAdapter(ReaderPtr reader, const size_t& countPackageInBolock)
    : _reader(std::move(reader)), _countPackageInBolock(countPackageInBolock)
{}

void NetworkAdapter::ReadPackage()
{

}

const size_t& NetworkAdapter::GetCountPackageInBolock()
{
    return _countPackageInBolock;
}

const ReaderPtr& NetworkAdapter::GetReader() const
{
    return _reader;
}