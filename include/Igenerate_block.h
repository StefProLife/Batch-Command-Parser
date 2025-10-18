#include <memory>

class IBlock;

class IGenerateBolck
{
public:
    virtual ~IGenerateBolck() = default;
public:
    virtual IBlock* CreateBlock() = 0;
};

using GenerateBolckPtr = std::unique_ptr<IGenerateBolck>;