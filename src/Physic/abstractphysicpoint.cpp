#include "abstractphysicpoint.h"

namespace subgine
{
namespace physic
{

AbstractPhysicPoint::AbstractPhysicPoint() : _mass(1), _lock(false)
{

}

void AbstractPhysicPoint::lock(const bool lock)
{
	_lock = lock;
}

bool AbstractPhysicPoint::isLock() const
{
	return _lock;
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
