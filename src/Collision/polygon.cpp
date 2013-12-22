#include "polygon.h"
#include <limits>

namespace subgine
{
namespace collision
{

Polygon::Polygon(std::function< subgine::Vector2(void) > position, std::function< double(void) > angle) : _position(position), _angle(angle)
{

}

Polygon::Polygon(Vector2 position, double angle)
{
	_position = [position]() -> Vector2 {
		return position;
	};
	
	_angle = [angle]() -> double {
		return angle;
	};
}

Polygon::Polygon(Vector2 position, std::function< double(void) > angle) : _angle(angle)
{
	_position = [position]() -> Vector2 {
		return position;
	};
}

Polygon::Polygon(std::function< Vector2(void) > position, double angle): _position(position)
{
	_angle = [angle]() -> double {
		return angle;
	};
}


Polygon::~Polygon()
{

}

void Polygon::addPoint(const Vector2 point)
{
	_vertex.push_back(point);
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

Vector2 Polygon::projection(double angle) const
{
	Vector2 axis = {cos(angle), sin(angle) };
	Vector2 result_projection;
	Vector2 current;


	auto verticle = _vertex.begin();

	current = *verticle;
	current.setAngle(getAngle() + current.getAngle());

	result_projection.x = axis.dot(current + getPosition());
	result_projection.y = result_projection.x;

	for (verticle++ ; verticle != _vertex.end() ; verticle++) {
		current = *verticle;
		current.setAngle(getAngle() + current.getAngle());
		double p = axis.dot(current + getPosition());

		if (p < result_projection.x) {
			result_projection.x = p;
		} else if (p > result_projection.y) {
			result_projection.y = p;
		}
	}

	return result_projection;
}

Vector2 Polygon::overlap(const SAT_able& other) const
{
	Vector2 overlap;
	overlap.setLenght(std::numeric_limits< double >().max());
	overlap.setAngle(pi / 4);

	for (double angle : getAngles()) {
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
	}
	
	return overlap;
}

std::vector< double > Polygon::getAngles() const
{
	std::vector<double> angles;
	Vector2 previous = *_vertex.rbegin();
	previous.setAngle(getAngle() + previous.getAngle());

	for (Vector2 current : _vertex) {
		current.setAngle(getAngle() + current.getAngle());
		angles.push_back((previous - current).getAngle() - (pi / 2));
		previous = current;
	}

	return angles;
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

}
}
