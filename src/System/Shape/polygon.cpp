#include "polygon.h"

using namespace std;

namespace sbg {
namespace shape {

void Polygon::addVertice(Vector2d vertice)
{
	_vertices.push_back(vertice);
}

const std::vector< Vector2d >& Polygon::getVertices() const
{
	return _vertices;
}

std::vector< Vector2d >& Polygon::getVertices()
{
	return _vertices;
}

void Polygon::setVertices(std::vector< Vector2d > vertices)
{
	_vertices = vertices;
}

Polygon::Polygon(std::vector< Vector2d > vertices): _vertices(vertices)
{

}

Vector1d Polygon::getMomentOfInertia(double mass) const
{
	double momentOfInertia = 0;
	Vector2d center;
	
	Vector2d previous = *_vertices.rbegin();
	for (auto current : _vertices) {
		Vector2d edge = (current - previous);
		double distance = edge.getLength();
		double height = std::abs(edge.angle(edge.getAngle() + tau/4).unit().dot(center - current));
		double a1 = std::abs(edge.unit().dot(center - current));
		double a2 = std::abs(edge.unit().dot(center - previous));
		double a = a1 > a2 ? a2:a1;
		
		
		momentOfInertia += (((distance*distance*distance*height) - (distance*distance*height*a) + (distance*height*a*a) + (distance*height*height*height)) / 36) + (mass*distance*distance);
		
		previous = current;
	}
	return momentOfInertia;
}

Vector2d Polygon::getCenterOfMass() const
{
	Vector2d average;
	for (auto vertice : _vertices) {
		average += vertice;
	}
	return average / _vertices.size();
}

}
}