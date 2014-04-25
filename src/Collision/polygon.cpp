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
	if (_vertex.size() == 0) {
		return Vector2();
	}

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
				if (getEstimatedVector().notZero()) {
					// code with estimation
				}

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

Vector2d Polygon::boxOverlap(const AABB_able& other) const
{
	if (
		getBoundingBox().second.x < other.getBoundingBox().first.x ||
		getBoundingBox().second.y < other.getBoundingBox().first.y ||
		getBoundingBox().first.x > other.getBoundingBox().second.x ||
		getBoundingBox().first.y > other.getBoundingBox().second.y
	   ) {
			const Vector2& amin = getBoundingBox().first;
            const Vector2& amax = getBoundingBox().second;
            const Vector2& bmin = other.getBoundingBox().first;
            const Vector2& bmax = other.getBoundingBox().second;
 
            Vector2 mtd;
 
            double left = (bmin.x - amax.x);
            double right = (bmax.x - amin.x);
            double top = (bmin.y - amax.y);
            double bottom = (bmax.y - amin.y);
 
            if (std::abs(left) < right) {
                mtd.x = left;
			} else {
                mtd.x = right;
			}
			
            if (std::abs(top) < bottom) {
                mtd.y = top;
			} else {
                mtd.y = bottom;
			}
 
            if (std::abs(mtd.x) < std::abs(mtd.y)) {
                mtd.x = 0;
			} else {
                mtd.x = 0;
			}
			
            return mtd;
	} else{
		return Vector2d();
	}
}

std::pair< Vector2d, Vector2d > Polygon::getBoundingBox() const
{
	Vector2d max;

	for (auto & vertex : getVertex()) {
		max.x = std::max(max.x, std::abs(vertex.x));
		max.y = std::max(max.y, std::abs(vertex.y));
	}

	return std::pair<Vector2d, Vector2d>((-1 * max) + getPosition(), max + getPosition());
}


}
}
