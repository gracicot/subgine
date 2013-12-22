#pragma once

#include "../system.hpp"
#include "sat_able.h"
#include "point_able.h"

namespace subgine
{
namespace collision
{

class Polygon : public virtual SAT_able, public virtual Point_able, public virtual Traits::Vertex
{
public:
	Polygon(subgine::Vector2 position = Vector2(), double angle = 0);
	Polygon(std::function< subgine::Vector2 > position, double angle = 0);
	Polygon(Vector2 position, std::function< double(void) > angle);
	Polygon(std::function< Vector2(void) > position, std::function< double(void) > angle);
	virtual ~Polygon();
	
	Vector2 getPosition() const;
	double getAngle() const;
	
	void setPosition(std::function< Vector2(void) > position);
	void setAngle(std::function< double(void) > angle);

	virtual Vector2 projection(double angle) const;
	virtual bool isPointInside(Vector2 point) const;
	virtual Vector2 overlap(const SAT_able& other) const;
	virtual Vector2 getNearestPoint(Vector2 point) const;

	void addPoint(const Vector2 point);
	std::vector< double > getAngles() const;

private:
	std::function< Vector2(void) > _position;
	std::function< double(void) > _angle;
};

}
}
