#include "polygon.h"

#include <limits>
#include <iostream>

namespace subgine
{
namespace collision
{


Polygon::Polygon(std::function< Vector2(void) > position, std::function< double(void) > angle, std::function< Vector2(void) > estimatedVector): _position(position), _angle(angle), _estimatedVector(estimatedVector)
{

}


Polygon::Polygon(Vector2 position, double angle, Vector2 estimatedVector)
{
	setPosition(position);
	setAngle(angle);
	setEstimatedVector(estimatedVector);
}

Polygon::Polygon(std::function< Vector2(void) > position, double angle, std::function< Vector2(void) > estimatedVector): _position(position), _estimatedVector(estimatedVector)
{
	setAngle(angle);
}

Polygon::Polygon(Vector2 position, std::function< double(void) > angle, Vector2 estimatedVector): _angle(angle)
{
	setPosition(position);
	setEstimatedVector(estimatedVector);
}

Polygon::Polygon(Vector2 position, std::function< double(void) > angle, std::function< Vector2(void) > estimatedVector): _angle(angle), _estimatedVector(estimatedVector)
{
	setPosition(position);
}

Polygon::Polygon(std::function< Vector2(void) > position, std::function< double(void) > angle, Vector2 estimatedVector): _position(position), _angle(angle)
{
	setEstimatedVector(estimatedVector);
}


Polygon::Polygon(std::function< Vector2(void) > position, double angle, Vector2 estimatedVector): _position(position)
{
	setAngle(angle);
	setEstimatedVector(estimatedVector);
}

CollisionEntity* Polygon::clone() const
{
	return new Polygon(*this);
}

Polygon::~Polygon()
{

}

void Polygon::addPoint(const Vector2 point)
{
	_vertex.push_back(point);
	
	Vector2d max;

	for (auto & vertex : _vertex) {
		max.x = std::max(max.x, std::abs(vertex.x));
		max.y = std::max(max.y, std::abs(vertex.y));
	}
	_cachedBoundingBox = std::pair<Vector2d, Vector2d>((-1 * max), max);
}

bool Polygon::isPointInside(Vector2 point) const
{
	bool oddNodes = false;
	Vector2 previous_vertex = *_vertex.rbegin();
	previous_vertex.setAngle(previous_vertex.getAngle() + getAngle());
	previous_vertex += getPosition();

	for (Vector2 current_vertex : _vertex) {
		current_vertex.setAngle(current_vertex.getAngle() + getAngle());
		current_vertex += getPosition();

		if ((current_vertex.y < point.y && previous_vertex.y >= point.y
		        || previous_vertex.y < point.y && current_vertex.y >= point.y)
		        && (current_vertex.x <= point.x || previous_vertex.x <= point.x)) {
			oddNodes ^= (current_vertex.x + (point.y - current_vertex.y) / (previous_vertex.y - current_vertex.y) * (previous_vertex.x - current_vertex.x) < point.x);
		}

		previous_vertex = current_vertex;
	}

	return oddNodes;
}

Vector2 Polygon::projection(double angle)
{
	Vector2d projection;
	std::unordered_map<double, Vector2d>::iterator it;
	if (_cachedProjections.size() > 0 && ((it = _cachedProjections.find(std::sin(angle))) != _cachedProjections.end())) {
			projection = it->second;
	} else {
		if (_cachedProjections.size() > 3 * _vertex.size()) {
			_cachedProjections.erase(_cachedProjections.begin(), std::next(_cachedProjections.begin(), _vertex.size()));
		}
		
		Vector2 axis(cos(angle), sin(angle));
		Vector2 current;

		auto verticle = _vertex.begin();

		current = *verticle;

		projection.x = axis.dot(current);
		projection.y = projection.x;

		for (verticle++ ; verticle != _vertex.end() ; verticle++) {
			current = *verticle;
			double p = axis.dot(current);
			
			projection.x = std::min(projection.x, p);
			projection.y = std::max(projection.y, p);
		}
		
		_cachedProjections[std::sin(angle + getAngle())] = projection;
		_cachedProjections[std::sin(angle + getAngle() + pi)] = Vector2(-projection.y, -projection.x);
	}
	
	Vector2 axis(cos(angle + getAngle()), sin(angle + getAngle()));
	projection.x += axis.dot(getPosition());
	projection.y += axis.dot(getPosition());

	return projection;
}

Vector2 Polygon::projection(double angle) const
{
	Vector2d projection;
	std::unordered_map<double, Vector2d>::const_iterator it;
	if (_cachedProjections.size() > 0 && ((it = _cachedProjections.find(std::sin(angle))) != _cachedProjections.end())) {
			projection = it->second;
	} else {
		Vector2 axis(cos(angle), sin(angle));
		Vector2 current;

		auto verticle = _vertex.begin();

		current = *verticle;

		projection.x = axis.dot(current);
		projection.y = projection.x;

		for (verticle++ ; verticle != _vertex.end() ; verticle++) {
			current = *verticle;
			double p = axis.dot(current);
			
			projection.x = std::min(projection.x, p);
			projection.y = std::max(projection.y, p);
		}
	}

	Vector2 axis(cos(angle + getAngle()), sin(angle + getAngle()));
	projection.x += axis.dot(getPosition());
	projection.y += axis.dot(getPosition());
	
	return projection;
}

Vector2 Polygon::overlap(const SAT_able& other)
{
	if (_vertex.size() == 0) {
		return Vector2();
	}

	Vector2 overlap;

	for (double angle : getAngles()) {
		Vector2 projectionThis = this->projection(angle);
		Vector2 projectionOther = other.projection(angle);

		if ((projectionThis.y < projectionOther.x) || projectionThis.x > projectionOther.y) {
			return Vector2();
		} else {
			if (!overlap.notZero() || overlap > projectionThis.y - projectionOther.x) {
				overlap = Vector2d(projectionThis.y - projectionOther.x, 0);
				overlap.setAngle(angle + getAngle());
			}
		}
	}

	return overlap;
}

Vector2 Polygon::overlap(const SAT_able& other) const
{
	if (_vertex.size() == 0) {
		return Vector2();
	}

	Vector2 overlap;

	for (double angle : getAngles()) {
		Vector2 projectionThis = this->projection(angle);
		Vector2 projectionOther = other.projection(angle);

		if ((projectionThis.y < projectionOther.x) || projectionThis.x > projectionOther.y) {
			return Vector2();
		} else {
			if (!overlap.notZero() || overlap > projectionThis.y - projectionOther.x) {
				overlap = Vector2d(projectionThis.y - projectionOther.x, 0);
				overlap.setAngle(angle + getAngle());
			}
		}
	}

	return overlap;
}

std::vector< double > Polygon::getAngles()
{
	if (_cachedAngles.size() == 0) {
		_cachedAngles.reserve(_vertex.size());
		
		Vector2 previous = *_vertex.rbegin();

		for (Vector2 current : _vertex) {
			_cachedAngles.push_back((previous - current).getAngle() - (tau / 4));
			previous = current;
		}
	}
	
	return _cachedAngles;
}

std::vector< double > Polygon::getAngles() const
{
	if (_cachedAngles.size() == 0) {
		std::vector<double> angles(_vertex.size());
		
		Vector2 previous = *_vertex.rbegin();
		previous.setAngle(getAngle() + previous.getAngle());

		for (Vector2 current : _vertex) {
			current.setAngle(getAngle() + current.getAngle());
			angles.push_back((previous - current).getAngle() - (tau / 4));
			previous = current;
		}
		
		return angles;
	} else {
		return _cachedAngles;
	}
}

Vector2 Polygon::getNearestPoint(Vector2 point) const
{
	Vector2 nearest(std::numeric_limits< double >().max(), 0);
	nearest.setAngle(pi / 4);

	for (Vector2 current : _vertex) {
		current.setAngle(getAngle() + current.getAngle());

		if (nearest.getLength() > (current - point).getLength()) {
			nearest = current;
		}
	}
	
	return nearest + getPosition();
}

double Polygon::getAngle() const
{
	return _angle();
}

Vector2 Polygon::getPosition() const
{
	return _position();
}

void Polygon::setAngle(std::function< double(void) > angle)
{
	_angle = angle;
}

void Polygon::setPosition(std::function< Vector2(void) > position)
{
	_position = position;
}

void Polygon::setAngle(double angle)
{
	_angle = [angle]() -> double {
		return angle;
	};
}

void Polygon::setPosition(Vector2 position)
{
	_position = [position]() -> Vector2 {
		return position;
	};
}

std::list< Vector2 > Polygon::getVertex() const
{
	return _vertex;
}

void Polygon::setEstimatedVector(std::function< Vector2(void) > estimatedVector)
{
	_estimatedVector = estimatedVector;
}

void Polygon::setEstimatedVector(Vector2 estimatedVector)
{
	_estimatedVector = [estimatedVector]() -> Vector2 {
		return estimatedVector;
	};
}

Vector2 Polygon::getEstimatedVector() const
{
	return _estimatedVector().unit();
}

std::pair< Vector2d, Vector2d > Polygon::getBoundingBox() const
{
	return {_cachedBoundingBox.first + getPosition(), _cachedBoundingBox.second + getPosition()};
}


}
}
