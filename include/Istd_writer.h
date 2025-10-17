#pragma once

#include <iostream>

class IWriter
{
public:
    virtual ~IWriter() = default;
public:
    virtual void Write(const std::string& str) = 0;
};