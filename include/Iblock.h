#pragma once

#include<Icommand.h>

class IBlock
{
public:
	virtual ~IBlock();
public:
	virtual void push(ICommand);
};