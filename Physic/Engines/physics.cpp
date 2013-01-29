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

for(auto i : getContent())
	{
		if(!i->isLock())
		{
			i->applyRules(); //apply rules
		}
	}
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
