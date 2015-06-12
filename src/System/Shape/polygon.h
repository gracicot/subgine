#pragma once

#include "shape.h"

#include <vector>

namespace sbg {
namespace shape {

class Polygon : public Shape2D
{
public:
	Polygon() = default;
	Polygon(std::vector<Vector2d> vertices);
	~Polygon() = default;
	Polygon(const Polygon&) = default;
	Polygon(Polygon&&) = default;
	
	void addVertice(Vector2d vertice);
	const std::vector<Vector2d>& getVertices() const;
	std::vector<Vector2d>& getVertices();
	void setVertices(std::vector<Vector2d> vertices);
	
	virtual Vector1d getMomentOfInertia(double mass) const override;
	virtual Vector2d getCenterOfMass() const override;
	
private:
	std::vector<Vector2d> _vertices;
	
};

}
}