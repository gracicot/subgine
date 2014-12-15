#pragma once

#include <vector>
#include <unordered_map>

#include "../system.hpp" 
#include "sat_able.h"
#include "point_able.h"
#include "aabb_able.h"

namespace sbg {

class Polygon : public virtual SAT_able
{
public:
	Polygon();
	Polygon(std::shared_ptr<ComponentProvider2D> components);
	~Polygon() = default;
	
	Vector2d getPosition() const;
	double getAngle() const;
	
	void setComponents(std::shared_ptr<ComponentProvider2D> components);
	
	virtual Vector2d projection(double angle) const override;
	virtual bool isPointInside(Vector2d point) const override;
	virtual Vector2d overlap(const SAT_able& other) const override;
	virtual Vector2d getNearestPoint(Vector2d point) const override;
	virtual CollisionEntity* clone() const override;
	virtual std::pair< Vector2d, Vector2d > getBoundingBox() const override;

	std::shared_ptr< shape::Polygon > getShape() const;
	void setShape(std::shared_ptr<shape::Polygon> shape);
	std::vector< double > getAngles() const;

private:
	std::shared_ptr<shape::Polygon> _shape;
	std::shared_ptr<ComponentProvider2D> _components;
	
	std::pair<Vector2d, Vector2d> _cachedBoundingBox;
	std::vector<double> _cachedAngles;
	std::unordered_map<double, Vector2d> _cachedProjections;
};

}
