#include "abstractphysicpoint.h"

void AbstractPhysicPoint::lock(bool lock)
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

void AbstractPhysicPoint::setMass(double mass)
{
	_mass = mass;
}
