#pragma once

#include <memory>
#include "Inetwork_adapter.h"
#include "Ilogger.h"
#include "Iwriter.h"

class Parser
{
public:
    Parser(INetworkAdapter* pNetworkAdapter, ILogger* pLogger, IWriter* pWriter);
public:
    void Run();
    const NetworkAdapterPtr& GetNetworkAdapter() const;
    const LoggerPtr& GetLogger() const;
    const WriterrPtr& GetWriter() const;
private:
    NetworkAdapterPtr _networkAdapter;
    LoggerPtr _logger;
    WriterrPtr _writer;
};