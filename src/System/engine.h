#pragma once

namespace sbg
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

