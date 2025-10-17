#include "parser.h"

Parser::Parser(NetworkAdapterPtr networkAdapter, LoggerPtr logger, WriterrPtr writer)
    : _networkAdapter(std::move(networkAdapter)),
      _logger(std::move(logger)),
      _writer(std::move(writer))
{}

void Parser::Run()
{
    while (true)
    {
        _networkAdapter->ReadPackage();
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