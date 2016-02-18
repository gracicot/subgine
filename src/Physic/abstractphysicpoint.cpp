#include "abstractphysicpoint.h"

namespace sbg {

AbstractPhysicPoint::~AbstractPhysicPoint() = default;

double AbstractPhysicPoint::getMass() const
{
	return _mass;
}

void AbstractPhysicPoint::setMass(const double mass)
{
	_mass = mass;
}

}
