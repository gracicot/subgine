#include "circle.h"
#include <limits>

namespace subgine
{
namespace collision
{

Circle::Circle()
{

}

bool Circle::isPointInside(Vector2 point) const
{
	return (_position - point).getLength() < _radius;
}

Vector2 Circle::projection(double angle) const
{
	double proj;
	Vector2 axis = {cos(angle), sin(angle) };

	proj = axis.dot(_position);

	//std::cerr << Vector2(proj-_radius, proj+_radius) << std::endl;


	return Vector2(proj - _radius, proj + _radius);
}

Vector2 Circle::projection(double angle)
{
	double proj;
	Vector2 axis = {cos(angle), sin(angle) };

	proj = axis.dot(_position);

	//std::cerr << Vector2(proj-_radius, proj+_radius) << std::endl;


	return Vector2(proj - _radius, proj + _radius);
}

Vector2 Circle::overlap(const SAT_able& other)
{
	Vector2 overlap;
	overlap.setLenght(std::numeric_limits< double >().max());
	double angle = (_position - other.getNearestPoint(_position)).getAngle();

	Vector2 projectionThis = this->projection(angle);
	Vector2 projectionOther = other.projection(angle);

	if ((projectionThis.y < projectionOther.x) || projectionThis.x > projectionOther.y) {
		return Vector2();
	} else {
		if (overlap.getLength() > projectionThis.y - projectionOther.x) {
			overlap = {projectionThis.y - projectionOther.x, 0};
			overlap.setAngle(angle);
		}
	}

	return overlap;
}

CollisionEntity* Circle::clone() const
{
	return new Circle(*this);
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

	if ((projectionThis.y < projectionOther.x) || projectionThis.x > projectionOther.y) {
		return Vector2();
	} else {
		if (overlap.getLength() > projectionThis.y - projectionOther.x) {
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

Vector2d Circle::boxOverlap(const AABB_able& other) const
{
	return {};
}

std::pair< Vector2d, Vector2d > Circle::getBoundingBox() const
{
	return {};
}

}
}
