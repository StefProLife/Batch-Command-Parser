#pragma once

#include <iostream>
#include "Ireader.h"

class INetworkAdapter
{
public:
    virtual ~INetworkAdapter() = default;
public:
    virtual void ReadPackage() = 0;
    virtual size_t GetCountPackageInBolock() = 0;
    virtual const ReaderPtr& GetReader() const = 0;
};