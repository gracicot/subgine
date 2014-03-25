#pragma once

#include <vector>

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
	Polygon(Vector2 position = Vector2(), double angle = 0, Vector2 estimatedVector = Vector2());
	Polygon(std::function< Vector2(void) > position, double angle, Vector2 estimatedVector = Vector2());
	Polygon(std::function< Vector2(void) > position, double angle, std::function< Vector2(void) > estimatedVector);
	Polygon(Vector2 position, std::function< double(void) > angle, Vector2 estimatedVector = Vector2());
	Polygon(Vector2 position, std::function< double(void) > angle, std::function< Vector2(void) > estimatedVector);
	Polygon(std::function< Vector2(void) > position, std::function< double(void) > angle, Vector2 estimatedVector = Vector2());
	Polygon(std::function< Vector2(void) > position, std::function< double(void) > angle, std::function< Vector2(void) > estimatedVector);
	virtual ~Polygon();
	
	Vector2 getPosition() const;
	double getAngle() const;
	Vector2 getEstimatedVector() const;
	
	void setPosition(std::function< Vector2(void) > position);
	void setAngle(std::function< double(void) > angle);
	void setEstimatedVector(std::function< Vector2(void) > estimatedVector);
	
	void setEstimatedVector(Vector2 estimatedVector);
	void setAngle(double angle);
	void setPosition(Vector2 position);

	virtual Vector2 projection(double angle) const override;
	virtual bool isPointInside(Vector2 point) const override;
	virtual Vector2 overlap(const SAT_able& other) const override;
	virtual Vector2 getNearestPoint(Vector2 point) const override;
	virtual CollisionEntity* clone() const override;

	std::list<Vector2> getVertex() const;
	void addPoint(const Vector2 point);
	std::vector< double > getAngles() const;

private:
	std::function< Vector2(void) > _position;
	std::function< double(void) > _angle;
	std::function< Vector2(void) > _estimatedVector;
};

}
}
