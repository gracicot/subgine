#pragma once

#include "const.h"

class Engine
{
public:
	Engine();
	virtual ~Engine();
	virtual void execute(const float time) = 0;

protected:

private:

};
