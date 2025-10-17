#pragma once

#include "Ireader.h"

class StdReader : public IReader
{
public:
    StdReader() = default;
public:
    std::string Read() override;
};