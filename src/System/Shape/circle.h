#pragma once

#include "shape.h"

#include <vector>

namespace sbg {
namespace shape {

class Circle : public Shape2D
{
public:
	Circle() = default;
	Circle(double radius);
	~Circle() = default;
	Circle(const Circle&) = default;
	Circle(Circle&&) = default;
	
	void setRadius(double radius);
	double getRadius() const;
	
	virtual Vector1d getMomentOfInertia(double mass) const override;
	virtual Vector2d getCenterOfMass() const override;
	
private:
	double _radius;
	
};

}
}