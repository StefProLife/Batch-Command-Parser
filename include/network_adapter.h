#pragma once

#include "Inetwork_adapter.h"
#include "Igenerate_command.h"

class NetworkAdapter : public INetworkAdapter
{
public:
    NetworkAdapter(GenerateCommandPtr generateCommand, ReaderPtr reader, const size_t& countPackageInBolock);
public:
    void ReadPackage() override;
    const size_t& GetCountPackageInBolock() override;
    const ReaderPtr& GetReader() const override;
private:
    ReaderPtr _reader;
    GenerateCommandPtr _generateCommand;
    size_t _countPackageInBolock;
};