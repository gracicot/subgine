#include "physics.h"

Physics::Physics()
{

}

Physics::~Physics()
{

}

void Physics::execute(const float time)
{

for(auto i : getContent())
	{
		if(!i->isLock())
		{
			i->applyRules(); //apply rules
		}
	}

for(auto i : getContent())
	{
		if(!i->isLock())
		{
			i->updateVelocity(time); //update velocity

		}
	}

for(auto i : getContent())
	{
		if(!i->isLock())
		{
			i->updatePosition(time); //update position

		}
	}
}

