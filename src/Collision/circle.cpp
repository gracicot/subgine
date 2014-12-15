#include "circle.h"
#include <limits>

#include <iostream>

using namespace std;

namespace sbg {

Circle::Circle() : _provider(make_shared<ZeroPositionProvider2D>())
{

}

Circle::Circle(shared_ptr<sbg::PositionProvider2D> provider): _provider(provider)
{
	
}

Vector2d Circle::getPosition() const
{
	return _provider->getPosition();
}

std::shared_ptr<shape::Circle> Circle::getShape() const
{
	return _shape;
}

void Circle::setShape(std::shared_ptr<shape::Circle> shape)
{
	_shape = shape;
}

bool Circle::isPointInside(Vector2d point) const
{
	double radius = _shape->getRadius();
	return (getPosition() - point).getLength() < radius;
}

Vector2d Circle::projection(double angle) const
{
	double proj;
	double radius = _shape->getRadius();
	Vector2d axis = {cos(angle), sin(angle) };

	proj = axis.dot(getPosition());


	return Vector2d(proj - radius, proj + radius);
}

CollisionEntity* Circle::clone() const
{
	return new Circle(*this);
}

Vector2d Circle::overlap(const SAT_able& other) const
{
	Vector2d overlap(0, 0);
	double angle = (other.getNearestPoint(getPosition()) - getPosition()).getAngle();

	Vector2d projectionThis = this->projection(angle);
	Vector2d projectionOther = other.projection(angle);

	if ((projectionThis.y < projectionOther.x) || projectionThis.x > projectionOther.y) {
		return Vector2d();
	} else {
		if (!overlap.notZero() || overlap > projectionThis.y - projectionOther.x) {
			overlap = {projectionThis.y - projectionOther.x, 0};
			overlap.setAngle(angle);
		}
	}

	return overlap;
}

Vector2d Circle::setPositionProvider(shared_ptr<PositionProvider2D> provider)
{
	_provider = provider;
}

Vector2d Circle::getNearestPoint(Vector2d point) const
{
	double radius = _shape->getRadius();
	Vector2d nearest(radius, 0);
	nearest.setAngle((point - getPosition()).getAngle());
	return nearest + getPosition();
}

std::pair< Vector2d, Vector2d > Circle::getBoundingBox() const
{
	double radius = _shape->getRadius();
	return {Vector2d{-radius, -radius} + getPosition(), Vector2d{radius, radius} + getPosition()};
}

}
