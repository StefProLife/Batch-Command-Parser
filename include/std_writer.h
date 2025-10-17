#pragma once

#include "IWriter.h"

class StdWriter : public IWriter
{
public:
    StdWriter() = default;
public:
    void Write(const std::string& str) override;
};