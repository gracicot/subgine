#include "physics.h"

#include <algorithm>

using namespace std;

namespace sbg {

Physics::Physics()
{

}

Physics::~Physics()
{

}

void Physics::addPhysicEntity(AbstractPhysicPoint* entity)
{
	_entites.push_back(entity);
}

void Physics::removePhysicEntity(AbstractPhysicPoint* entity)
{
	_entites.erase(remove(_entites.begin(), _entites.end(), entity));
}

void Physics::execute(const double time)
{
	for (auto i : _entites)
		i->update(time); //apply rules
}

}
