#include "physics.h"

namespace subgine
{
namespace physic
{

Physics::Physics()
{

}

Physics::~Physics()
{

}

void Physics::execute(const double time)
{

	for (auto i : getContent()) {
		if (!i->isLock()) {
			i->applyRules(); //apply rules
		}
	}

	for (auto i : getContent()) {
		if (!i->isLock()) {
			i->updateVelocity(time);  //update velocity

		}
	}

	for (auto i : getContent()) {
		if (!i->isLock()) {
			i->updatePosition(time);  //update position

		}
	}
}

}
}
