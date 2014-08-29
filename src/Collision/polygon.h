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
	Polygon(Vector2 position = Vector2(), double angle = 0);
	Polygon(std::function< Vector2(void) > position, double angle);
	Polygon(Vector2 position, std::function< double(void) > angle);
	Polygon(std::function< Vector2(void) > position, std::function< double(void) > angle);
	~Polygon() = default;
	
	Vector2 getPosition() const;
	double getAngle() const;
	
	void setPosition(std::function< Vector2(void) > position);
	void setAngle(std::function< double(void) > angle);
	
	void setAngle(double angle);
	void setPosition(Vector2 position);
	
	virtual Vector2 projection(double angle) override;
	virtual Vector2 projection(double angle) const override;
	virtual bool isPointInside(Vector2 point) const override;
	virtual Vector2 overlap(const subgine::collision::SAT_able& other) override;
	virtual Vector2 overlap(const subgine::collision::SAT_able& other) const override;
	virtual Vector2 getNearestPoint(Vector2 point) const override;
	virtual CollisionEntity* clone() const override;
	virtual std::pair< Vector2d, Vector2d > getBoundingBox() const override;

	std::list<Vector2> getVertex() const;
	void addPoint(const Vector2 point);
	std::vector< double > getAngles();
	std::vector< double > getAngles() const;

private:
	std::function< Vector2(void) > _position;
	std::function< double(void) > _angle;
	
	std::pair<Vector2d, Vector2d> _cachedBoundingBox;
	std::vector<double> _cachedAngles;
	std::unordered_map<double, Vector2> _cachedProjections;
};

}
}
