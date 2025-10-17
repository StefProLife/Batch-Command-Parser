#pragma once

#include <memory>
#include "Inetwork_adapter.h"
#include "Ilogger.h"
#include "Iwriter.h"

class Parser
{
public:
    Parser(NetworkAdapterPtr networkAdapter, LoggerPtr logger, WriterrPtr writer);
    const NetworkAdapterPtr& GetNetworkAdapter() const;
    const LoggerPtr& GetLogger() const;
    const WriterrPtr& GetWriter() const;
private:
    NetworkAdapterPtr _networkAdapter;
    LoggerPtr _logger;
    WriterrPtr _writer;
};