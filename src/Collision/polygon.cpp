#include "polygon.h"

#include <limits>
#include <iostream>

using namespace std;

namespace sbg {

Polygon::Polygon(function< Vector2d(void) > position, function< double(void) > angle): _position(position), _angle(angle)
{
	setShape(make_shared<shape::Polygon>());
}

Polygon::Polygon(Vector2d position, double angle)
{
	setPosition(position);
	setAngle(angle);
	setShape(make_shared<shape::Polygon>());
}

Polygon::Polygon(function<Vector2d(void)> position, double angle): _position(position)
{
	setAngle(angle);
	setShape(make_shared<shape::Polygon>());
}

Polygon::Polygon(Vector2d position, function< double(void) > angle): _angle(angle)
{
	setPosition(position);
	setShape(make_shared<shape::Polygon>());
}

shared_ptr<shape::Polygon> Polygon::getShape() const
{
	return _shape;
}

CollisionEntity* Polygon::clone() const
{
	return new Polygon(*this);
}

double Polygon::getAngle() const
{
	return _angle();
}

Vector2d Polygon::getPosition() const
{
	return _position();
}

void Polygon::setAngle(function< double(void) > angle)
{
	_angle = angle;
}

void Polygon::setPosition(function<Vector2d(void)> position)
{
	_position = position;
}

void Polygon::setAngle(double angle)
{
	_angle = [angle]() -> double {
		return angle;
	};
}

void Polygon::setPosition(Vector2d position)
{
	_position = [position]() -> Vector2d {
		return position;
	};
}

pair< Vector2d, Vector2d> Polygon::getBoundingBox() const
{
	return {_cachedBoundingBox.first + getPosition(), _cachedBoundingBox.second + getPosition()};
}

void Polygon::setShape(shared_ptr<shape::Polygon> shape)
{
	_shape = shape;
	if (_shape->getVertices().size() > 0) {
		{
			Vector2d maximum;
			for (auto vertex : _shape->getVertices()) {
				maximum.x = max(maximum.x, abs(vertex.x));
				maximum.y = max(maximum.y, abs(vertex.y));
			}
			_cachedBoundingBox = pair<Vector2d, Vector2d>((-1.5 * maximum), 1.5 * maximum);
		}

		{
			Vector2d previous = *_shape->getVertices().rbegin();
			for (Vector2d current : _shape->getVertices()) {
				_cachedAngles.push_back((previous - current).getAngle() - (tau / 4));
				previous = current;
			}
		}

		for (auto angle : _cachedAngles) {
			Vector2d axis(cos(angle), sin(angle));
			Vector2d current;
			Vector2d projection;
			auto vertex = _shape->getVertices().begin();

			current = *vertex;

			projection.x = axis.dot(current);
			projection.y = projection.x;

			for (vertex++ ; vertex != _shape->getVertices().end() ; vertex++) {
				current = *vertex;
				double p = axis.dot(current);

				projection.x = min(projection.x, p);
				projection.y = max(projection.y, p);
			}

			_cachedProjections[sin(angle)] = projection;
			_cachedProjections[sin((angle + pi))] = Vector2d(-projection.y, -projection.x);
		}
	}
}

bool Polygon::isPointInside(Vector2d point) const
{
	if (_shape && _shape->getVertices().size()) {
		bool oddNodes = false;
		Vector2d previous = *_shape->getVertices().rbegin();
		previous.setAngle(previous.getAngle() + getAngle());
		previous += getPosition();

		for (Vector2d current :_shape->getVertices()) {
			current.setAngle(current.getAngle() + getAngle());
			current += getPosition();

			if ((current.y < point.y && previous.y >= point.y
					|| previous.y < point.y && current.y >= point.y)
					&& (current.x <= point.x || previous.x <= point.x)) {
				oddNodes ^= (current.x + (point.y - current.y) / (previous.y - current.y) * (previous.x - current.x) < point.x);
			}

			previous = current;
		}

		return oddNodes;
	} else {
		return false;
	}
}

Vector2d Polygon::projection(double angle) const
{
	if (_shape && _shape->getVertices().size() > 0) {
		Vector2d projection;
		unordered_map<double, Vector2d>::const_iterator it;

		if (_cachedProjections.size() > 0 && ((it = _cachedProjections.find(sin(angle - getAngle()))) != _cachedProjections.end())) {
			projection = it->second;
		} else {
			Vector2d axis(cos(angle - getAngle()), sin(angle - getAngle()));
			Vector2d current;

			auto verticle = _shape->getVertices().begin();

			current = *verticle;

			projection.x = axis.dot(current);
			projection.y = projection.x;

			for (verticle++ ; verticle != _shape->getVertices().end() ; verticle++) {
				current = *verticle;
				double p = axis.dot(current);

				projection.x = min(projection.x, p);
				projection.y = max(projection.y, p);
			}
		}

		Vector2d axis(cos(angle), sin(angle));
		projection.x += axis.dot(getPosition());
		projection.y += axis.dot(getPosition());

		return projection;
	} else {
		return Vector2d();
	}
}

Vector2d Polygon::overlap(const SAT_able& other) const
{
	if (!_shape || _shape->getVertices().size() == 0) {
		return Vector2d();
	}

	Vector2d overlap;

	for (double angle : getAngles()) {
		Vector2d projectionThis = this->projection(angle);
		Vector2d projectionOther = other.projection(angle);

		if (projectionThis.y < projectionOther.x || projectionThis.x > projectionOther.y) {
			return Vector2d();
		} else {
			if (!overlap.notZero() || overlap > projectionThis.y - projectionOther.x) {
				overlap = Vector2d(projectionThis.y - projectionOther.x, 0);
				overlap.setAngle(angle);
			}
		}
	}

	return overlap;
}

vector< double > Polygon::getAngles() const
{
	vector<double> angles;
	
	for (auto angle : _cachedAngles) {
		angles.push_back(angle + getAngle());
	}

	return angles;
}

Vector2d Polygon::getNearestPoint(Vector2d point) const
{
	if (_shape && _shape->getVertices().size()) {
		Vector2d nearest(0, 0);
		bool first = true;

		for (Vector2d current : _shape->getVertices()) {
			current.setAngle(getAngle() + current.getAngle());

			if (first || nearest > (current - point)) {
				nearest = current;
			}
			
			first = false;
		}

		return nearest + getPosition();
	} else {
		return Vector2d();
	}
}

}
