#pragma once

#include "Inetwork_adapter.h"
#include "Igenerate_command.h"

class NetworkAdapter : public INetworkAdapter
{
public:
    NetworkAdapter(IGenerateCommand* pGenerateCommand, IReader* pReader, const size_t& countPackageInBolock);
public:
    BlockPtr ReadPackage() override;
    const size_t& GetCountPackageInBolock() override;
    const ReaderPtr& GetReader() const override;
private:
    enum class BlockType
    {
        staticBlock,
        dynamicBlock
    };
private:
    IBlock* makeBlock(BlockType type);
private:
    GenerateCommandPtr _generateCommand;
    ReaderPtr _reader;
    size_t _countPackageInBolock;
};