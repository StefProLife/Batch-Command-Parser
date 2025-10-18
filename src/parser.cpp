#include "parser.h"

Parser::Parser(INetworkAdapter* pNetworkAdapter, ILogger* pLogger, IWriter* pWriter)
    : _networkAdapter(NetworkAdapterPtr(pNetworkAdapter)),
      _logger(LoggerPtr(pLogger)),
      _writer(WriterrPtr(pWriter))
{}

void Parser::Run()
{
    while (true)
    {
        BlockPtr block = _networkAdapter->ReadPackage();
        _logger->Log(block);
        _writer->Write(block);
    }
}

const NetworkAdapterPtr& Parser::GetNetworkAdapter() const
{
    return _networkAdapter;
}

const LoggerPtr& Parser::GetLogger() const
{
    return _logger;
}

const WriterrPtr& Parser::GetWriter() const
{
    return _writer;
}