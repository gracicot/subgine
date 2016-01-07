#include "circle.h"
#include <limits>

#include <iostream>

using namespace std;

namespace sbg {

Circle::Circle() : _provider{makeZeroPositionProvider2D()}
{

}

Circle::Circle(PositionProvider2D provider): _provider{provider}
{
	
}

Vector2d Circle::getPosition() const
{
	return _provider.getPosition();
}

shape::Circle Circle::getShape() const
{
	return _shape;
}

void Circle::setShape(const shape::Circle& shape)
{
	_shape = shape;
}

void Circle::setShape(shape::Circle&& shape)
{
	_shape = move(shape);
}

bool Circle::isPointInside(Vector2d point) const
{
	double radius = _shape.getRadius();
	return (getPosition() - point).length() < radius;
}

pair<double, double> Circle::projection(double angle) const
{
	double proj;
	double radius = _shape.getRadius();
	Vector2d axis = {cos(angle), sin(angle) };

	proj = axis.dot(getPosition());


	return {proj - radius, proj + radius};
}

Vector2d Circle::overlap(const SAT_able& other) const
{
	Vector2d overlap;
	double angle = (other.getNearestPoint(getPosition()) - getPosition()).angle();

	pair<double, double> projectionThis = this->projection(angle);
	pair<double, double> projectionOther = other.projection(angle);

	if ((projectionThis.second < projectionOther.first) || projectionThis.first > projectionOther.second) {
		return {};
	} else {
		if (overlap.null() || overlap > projectionThis.first - projectionOther.second) {
			overlap = {projectionThis.second - projectionOther.first, 0};
			overlap.applyAngle(projectionThis.first < projectionOther.first ? angle:-angle);
		}
	}

	return overlap;
}

void Circle::setPositionProvider(PositionProvider2D provider)
{
	_provider = provider;
}

Vector2d Circle::getNearestPoint(Vector2d point) const
{
	double radius = _shape.getRadius();
	Vector2d nearest(radius, 0);
	nearest.applyAngle((point - getPosition()).angle());
	return nearest + getPosition();
}

std::pair<Vector2d, Vector2d> Circle::getBoundingBox() const
{
	double radius = _shape.getRadius();
	return {Vector2d{-radius, -radius} + getPosition(), Vector2d{radius, radius} + getPosition()};
}

}
