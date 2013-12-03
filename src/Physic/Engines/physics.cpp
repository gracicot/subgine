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
	for (auto i : getContent())
		i->updatePhysic(time); //apply rules
}

}
}
