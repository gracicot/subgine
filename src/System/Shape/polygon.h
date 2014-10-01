#pragma once

#include "shape.h"
#include "../vector.h"
#include "../vector2.h"

#include <vector>

namespace subgine {
namespace shape {

class Polygon : public Shape<2>
{
public:
	Polygon() = default;
	Polygon(std::vector<Vector2d> vertices);
	~Polygon() = default;
	Polygon(const Polygon&) = default;
	Polygon(Polygon&&) = default;
	
	void addVertice(Vector2d vertice);
	std::vector<Vector2d> getVertices() const;
	void setVertices(std::vector<Vector2d> vertices);
	
	virtual double getMomentOfInertia(double mass) const override;
	virtual Vector2d getCenterOfMass() const override;
	
private:
	std::vector<Vector2d> _vertices;
	
};

}
}