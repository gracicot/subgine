#include "polygon.h"

#include <limits>
#include <iostream>

using namespace std;

namespace sbg {

Polygon::Polygon(): _components(unique_ptr<ComponentProvider2D>(new ZeroComponentProvider2D))
{
	
}

Polygon::Polygon(unique_ptr<ComponentProvider2D> components): _components(move(components))
{
	setShape(make_shared<shape::Polygon>());
}

Polygon::Polygon(const Polygon &other) : 
	_shape(other._shape),
	_components(other._components->clone()),
	_cachedBoundingBox(other._cachedBoundingBox),
	_cachedAngles(other._cachedAngles),
	_cachedProjections(other._cachedProjections)
{

}

shared_ptr<shape::Polygon> Polygon::getShape() const
{
	return _shape;
}

CollisionEntity* Polygon::clone() const
{
	return new Polygon(*this);
}

void Polygon::setComponents(unique_ptr<ComponentProvider2D> components)
{
	_components = move(components);
}

double Polygon::getAngle() const
{
	return _components->getOrientation();
}

Vector2d Polygon::getPosition() const
{
	return _components->getPosition();
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
			pair<double, double> projection;
			auto vertex = _shape->getVertices().begin();

			current = *vertex;

			projection.first = axis.dot(current);
			projection.second = projection.first;

			for (vertex++ ; vertex != _shape->getVertices().end() ; vertex++) {
				current = *vertex;
				double p = axis.dot(current);

				projection.first = min(projection.first, p);
				projection.second = max(projection.second, p);
			}

			_cachedProjections[sin(angle)] = projection;
			_cachedProjections[sin((angle + pi))] = {-projection.second, -projection.first};
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

			if (((current.y < point.y && previous.y >= point.y)
					|| (previous.y < point.y && current.y >= point.y))
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

pair<double, double> Polygon::projection(double angle) const
{
	if (_shape && _shape->getVertices().size() > 0) {
		pair<double, double> projection;
		unordered_map<double, pair<double, double>>::const_iterator it;

		if (_cachedProjections.size() > 0 && ((it = _cachedProjections.find(sin(angle - getAngle()))) != _cachedProjections.end())) {
			projection = it->second;
		} else {
			Vector2d axis(cos(angle - getAngle()), sin(angle - getAngle()));
			Vector2d current;

			auto verticle = _shape->getVertices().begin();

			current = *verticle;

			projection.first = axis.dot(current);
			projection.second = projection.first;

			for (verticle++ ; verticle != _shape->getVertices().end() ; verticle++) {
				current = *verticle;
				double p = axis.dot(current);

				projection.first = min(projection.first, p);
				projection.second = max(projection.second, p);
			}
		}

		Vector2d axis(cos(angle), sin(angle));
		projection.first += axis.dot(getPosition());
		projection.second += axis.dot(getPosition());

		return projection;
	} else {
		return {};
	}
}

Vector2d Polygon::overlap(const SAT_able& other) const
{
	if (!_shape || _shape->getVertices().size() == 0) {
		return Vector2d();
	}

	Vector2d overlap;

	for (double angle : getAngles()) {
		pair<double, double> projectionThis = this->projection(angle);
		pair<double, double> projectionOther = other.projection(angle);

		if (projectionThis.second < projectionOther.first || projectionThis.first > projectionOther.second) {
			return {};
		} else {
			if (!overlap.notZero() || overlap > projectionThis.second - projectionOther.first) {
				overlap = Vector2d(projectionThis.second - projectionOther.first, 0);
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
