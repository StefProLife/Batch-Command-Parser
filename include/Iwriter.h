#pragma once

#include <iostream>
#include <memory>

class IWriter
{
public:
    virtual ~IWriter() = default;
public:
    virtual void Write(const std::string& str) = 0;
};

using WriterrPtr = std::unique_ptr<IWriter>;