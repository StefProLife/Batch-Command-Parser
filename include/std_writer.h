#pragma once

#include "Iwriter.h"

class StdWriter : public IWriter
{
public:
    StdWriter() = default;
public:
    void Write(BlockPtr str) override;
};