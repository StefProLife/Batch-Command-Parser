#pragma once

#include "Istd_writer.h"

class StdWriter : public IWriter
{
public:
    StdWriter() = default;
public:
    void Write(const std::string& str) override;
};