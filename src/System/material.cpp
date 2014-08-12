#include "material.h"

#include <algorithm>

namespace subgine {

Material::Material(double restitution, double density, double staticFriction, double dynamicFriction) : _density(density), _staticFriction(staticFriction), _dynamicFriction(dynamicFriction)
{
	setRestitution(restitution);
}

double Material::getDensity() const
{
	return _density;
}

double Material::getDynamicFriction() const
{
	return _dynamicFriction;
}

double Material::getRestitution() const
{
	return _restitution;
}

double Material::getStaticFriction() const
{
	return _staticFriction;
}

void Material::setDensity(double density)
{
	_density = density;
}

void Material::setDynamicFriction(double dynamicFriction)
{
	_dynamicFriction = dynamicFriction;
}

void Material::setRestitution(double restitution)
{
	_restitution = std::min(restitution, 1.0);
}

void Material::setStaticFriction(double staticFriction)
{
	_staticFriction = staticFriction;
}

}