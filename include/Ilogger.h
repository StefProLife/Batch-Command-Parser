#include <string>
#include "Icommand.h"

class ILogger
{
public:
    virtual ~ILogger() = default;
public:
    void virtual Log(ICommand& command) = 0;
    const virtual std::string& GetExtension() = 0;
    const virtual std::string& GetPrefix() = 0;
};