#include "circle.h"
#include <limits>

namespace Collisionnable
{

Circle::Circle()
{

}

bool Circle::isPointInside(Vector2 point) const
{
	return (_position - point).getLenght() < _radius;
}

Vector2 Circle::projection(double angle) const
{
	double proj;
	Vector2 axis = {cos(angle), sin(angle)};

	proj = axis.dot(_position);

	//std::cerr << Vector2(proj-_radius, proj+_radius) << std::endl;


	return Vector2(proj - _radius, proj + _radius);
}

Circle::~Circle()
{

}

Vector2 Circle::overlap(const SAT_able& other) const
{
	Vector2 overlap;
	overlap.setLenght(std::numeric_limits< double >().max());
	double angle = (_position - other.getNearestPoint(_position)).getAngle();

	Vector2 projectionThis = this->projection(angle);
	Vector2 projectionOther = other.projection(angle);

	if((projectionThis.y < projectionOther.x) || projectionThis.x > projectionOther.y)
	{
		return Vector2();
	}
	else
	{
		if(overlap.getLenght() > projectionThis.y - projectionOther.x)
		{
			overlap = {projectionThis.y - projectionOther.x, 0};
			overlap.setAngle(angle);
		}
	}
	return overlap;
}

Vector2 Circle::getNearestPoint(Vector2 point) const
{
	Vector2 nearest(_radius, 0);
	nearest.setAngle((point - _position).getAngle());
	return nearest + _position;
}


}

