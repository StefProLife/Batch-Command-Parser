#pragma once

#include "Inetwork_adapter.h"

class NetworkAdapter : public INetworkAdapter
{
public:
    NetworkAdapter(ReaderPtr reader, const size_t& countPackageInBolock);
public:
    void ReadPackage() override;
    const size_t& GetCountPackageInBolock() override;
    const ReaderPtr& GetReader() const override;
private:
    ReaderPtr _reader;
    size_t _countPackageInBolock;
};