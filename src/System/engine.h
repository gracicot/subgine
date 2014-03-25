#pragma once

namespace subgine
{
class Engine
{
public:
	Engine();
	virtual ~Engine();
	virtual void execute(const double time) = 0;

protected:

private:

};
}

