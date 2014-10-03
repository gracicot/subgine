#pragma once

#include <vector>
#include <unordered_map>

#include "../system.hpp" 
#include "sat_able.h"
#include "point_able.h"
#include "aabb_able.h"

namespace subgine
{
namespace collision
{

class Polygon : public virtual SAT_able, public virtual Traits::Vertex
{
public:
	Polygon(Vector2d position = Vector2d(), double angle = 0);
	Polygon(std::function< Vector2d(void) > position, double angle);
	Polygon(Vector2d position, std::function< double(void) > angle);
	Polygon(std::function< Vector2d(void) > position, std::function< double(void) > angle);
	~Polygon() = default;
	
	Vector2d getPosition() const;
	double getAngle() const;
	
	void setPosition(std::function< Vector2d(void) > position);
	void setAngle(std::function< double(void) > angle);
	
	void setAngle(double angle);
	void setPosition(Vector2d position);
	
	virtual Vector2d projection(double angle) const override;
	virtual bool isPointInside(Vector2d point) const override;
	virtual Vector2d overlap(const subgine::collision::SAT_able& other) const override;
	virtual Vector2d getNearestPoint(Vector2d point) const override;
	virtual CollisionEntity* clone() const override;
	virtual std::pair< Vector2d, Vector2d > getBoundingBox() const override;

	std::shared_ptr< shape::Polygon > getShape() const;
	void setShape(std::shared_ptr<shape::Polygon> shape);
	std::vector< double > getAngles() const;

private:
	std::shared_ptr<shape::Polygon> _shape;
	std::function< Vector2d(void) > _position;
	std::function< double(void) > _angle;
	
	std::pair<Vector2d, Vector2d> _cachedBoundingBox;
	std::vector<double> _cachedAngles;
	std::unordered_map<double, Vector2d> _cachedProjections;
};

}
}
