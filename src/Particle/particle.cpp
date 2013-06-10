#include "particle.h"

Particle::Particle(const double lifetime) : _lifetime(lifetime > 0 ? lifetime : 1)
{

}

double Particle::getLifetime() const
{
	return _lifetime;
}

void Particle::setLifeTime(const double lifetime)
{
	_lifetime = lifetime > 0 ? lifetime : _lifetime;
}

