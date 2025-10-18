#pragma once

#include "IWriter.h"

class StdWriter : public IWriter
{
public:
    StdWriter() = default;
public:
    void Write(BlockPtr str) override;
};