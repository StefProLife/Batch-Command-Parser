#pragma once

#include <iostream>
#include <memory>
#include "Iblock.h"

class IWriter
{
public:
    virtual ~IWriter() = default;
public:
    virtual void Write(BlockPtr str) = 0;
};

using WriterrPtr = std::unique_ptr<IWriter>;