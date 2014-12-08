#pragma once

#include "shape.h"

#include <vector>

namespace subgine {
namespace shape {

class Circle : public Shape<2>
{
public:
	Circle() = default;
	Circle(double radius);
	~Circle() = default;
	Circle(const Circle&) = default;
	Circle(Circle&&) = default;
	
	void setRadius(double radius);
	double getRadius() const;
	
	virtual double getMomentOfInertia(double mass) const override;
	virtual Vector2d getCenterOfMass() const override;
	
private:
	double _radius;
	
};

}
}