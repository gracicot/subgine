#include "circle.h"

namespace subgine {
namespace shape {

Circle::Circle(double radius) : _radius(radius) {}

Vector2d Circle::getCenterOfMass() const
{
	return {0, 0};
}

double Circle::getMomentOfInertia(double mass) const
{
	return mass * (_radius*_radius*_radius*_radius);
}

double Circle::getRadius() const
{
	return _radius;
}

void Circle::setRadius(double radius)
{
	_radius = radius;
}

}
}