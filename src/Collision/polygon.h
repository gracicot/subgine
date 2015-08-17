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
	Polygon(ComponentProvider2D components);
	Polygon(const Polygon&) = default;
	Polygon(Polygon&&) = default;
	Polygon& operator=(const Polygon&) = default;
	Polygon& operator=(Polygon&&) = default;
	
	Vector2d getPosition() const;
	double getAngle() const;
	
	void setComponents(ComponentProvider2D components);
	
	std::pair<double, double> projection(double angle) const override;
	bool isPointInside(Vector2d point) const override;
	Vector2d overlap(const SAT_able& other) const override;
	Vector2d getNearestPoint(Vector2d point) const override;
	std::pair<Vector2d, Vector2d> getBoundingBox() const override;

	shape::Polygon getShape() const;
	void setShape(const shape::Polygon& shape);
	void setShape(shape::Polygon&& shape);
	std::vector<double> getAngles() const;

private:
	void makeCache();
	shape::Polygon _shape;
	ComponentProvider2D _components;
	
	std::pair<Vector2d, Vector2d> _cachedBoundingBox;
	std::vector<double> _cachedAngles;
	std::unordered_map<double, std::pair<double, double>> _cachedProjections;
};

}
