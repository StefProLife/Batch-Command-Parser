#pragma once

#include "Inetwork_adapter.h"
#include "Igenerate_command.h"
#include "Igenerate_block.h"

class NetworkAdapter : public INetworkAdapter
{
public:
    NetworkAdapter(IGenerateCommand* pGenerateCommand, IGenerateBolck* pGenerateBolck, IReader* pReader, const size_t& countPackageInBolock);
public:
    BlockPtr ReadPackage() override;
    const size_t& GetCountPackageInBolock() override;
    const ReaderPtr& GetReader() const override;
private:
    GenerateCommandPtr _generateCommand;
    GenerateBolckPtr _generateBolck;
    ReaderPtr _reader;
    size_t _countPackageInBolock;
};