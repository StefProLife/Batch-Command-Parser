#pragma once

#include "Iblock.h"
#include <string>

class Block : public IBlock
{
public:
    virtual ~Block() = default;
public:
    virtual bool Push(CommandPtr& command) = 0;
    virtual bool GetIgnore() = 0;
    virtual void SetIgnore(bool bIgnore) = 0;
    size_t GetSizeBlock() override;
    const std::deque<CommandPtr>& GetCommands() override;
    void Clear() override;
    bool Empty() override;
protected:
    bool _bIgnore = false;
    std::deque<CommandPtr> _dequeCommand;
};
