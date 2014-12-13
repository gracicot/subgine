#pragma once

#include "sat_able.h"
#include "point_able.h"

namespace sbg {

class Circle : public virtual SAT_able
{
public:
	Circle(Vector2d position = Vector2d());
	Circle(std::function< Vector2d(void) > position);

	virtual bool isPointInside(Vector2d point) const override;
	virtual Vector2d projection(double angle) const override;
	virtual Vector2d overlap(const SAT_able& other) const override;
	virtual Vector2d getNearestPoint(Vector2d point) const override;
	virtual std::pair< Vector2d, Vector2d > getBoundingBox() const override;
	
	Vector2d getPosition() const;
	
	void setShape(std::shared_ptr<shape::Circle> shape);
	std::shared_ptr<shape::Circle> getShape() const;
	
	virtual CollisionEntity* clone() const override;
private:
	std::shared_ptr<shape::Circle> _shape;
	std::function< Vector2d(void) > _position;
};

}
