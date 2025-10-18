#pragma once

#include "Inetwork_adapter.h"
#include "Igenerate_command.h"
#include "Igenerate_block.h"

class NetworkAdapter : public INetworkAdapter
{
public:
    NetworkAdapter(GenerateCommandPtr generateCommand, GenerateBolckPtr generateBolck, ReaderPtr reader, const size_t& countPackageInBolock);
public:
    BlockPtr ReadPackage() override;
    const size_t& GetCountPackageInBolock() override;
    const ReaderPtr& GetReader() const override;
private:
    ReaderPtr _reader;
    GenerateCommandPtr _generateCommand;
    GenerateBolckPtr _generateBolck;
    size_t _countPackageInBolock;
};