#pragma once

#include <iostream>
#include <memory>

class IReader
{
public:
    virtual ~IReader() = default;
public:
    virtual std::string Read() = 0;
};

using ReaderPtr = std::unique_ptr<IReader>;