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
    enum class BlockType : uint16_t
    {
        staticBlock = 0,
        dynamicBlock = 1
    };
private:
    IBlock* makeBlock(BlockType type);
private:
    GenerateCommandPtr _generateCommand;
    ReaderPtr _reader;
    size_t _countPackageInBolock;
private:
    std::string _beginDynamicBlock = "{";
    std::string _endDynamicBlock = "}";
    std::string _strEOF = "EOF";
    size_t _numberNested = 0;
};