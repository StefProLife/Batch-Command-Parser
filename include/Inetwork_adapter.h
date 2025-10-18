#pragma once

#include <iostream>
#include <memory>
#include "Ireader.h"
#include "Iblock.h"

class INetworkAdapter
{
public:
    virtual ~INetworkAdapter() = default;
public:
    virtual BlockPtr ReadPackage() = 0;
    virtual const size_t& GetCountPackageInBolock() = 0;
    virtual const ReaderPtr& GetReader() const = 0;
};

using NetworkAdapterPtr = std::unique_ptr<INetworkAdapter>;