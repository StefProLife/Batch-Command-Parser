#include<iostream>

class IReader
{
public:
    virtual ~IReader() = default;
public:
    virtual std::string Read() = 0;
};