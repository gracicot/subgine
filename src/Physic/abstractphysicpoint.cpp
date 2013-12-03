#include "abstractphysicpoint.h"

namespace subgine
{
namespace physic
{

AbstractPhysicPoint::AbstractPhysicPoint() : _mass(1)
{

}

double AbstractPhysicPoint::getMass() const
{
	return _mass;
}

void AbstractPhysicPoint::setMass(const double mass)
{
	_mass = mass;
}

}
}
