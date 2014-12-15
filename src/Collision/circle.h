#pragma once

#include "sat_able.h"
#include "point_able.h"

namespace sbg {

class Circle : public virtual SAT_able
{
public:
	Circle();
	Circle(std::shared_ptr<PositionProvider2D> provider);

	virtual bool isPointInside(Vector2d point) const override;
	virtual Vector2d projection(double angle) const override;
	virtual Vector2d overlap(const SAT_able& other) const override;
	virtual Vector2d getNearestPoint(Vector2d point) const override;
	virtual std::pair< Vector2d, Vector2d > getBoundingBox() const override;
	
	Vector2d getPosition() const;
	Vector2d setPositionProvider(std::shared_ptr<PositionProvider2D> provider);
	
	void setShape(std::shared_ptr<shape::Circle> shape);
	std::shared_ptr<shape::Circle> getShape() const;
	
	virtual CollisionEntity* clone() const override;
private:
	std::shared_ptr<shape::Circle> _shape;
	std::shared_ptr<PositionProvider2D> _provider;
};

}
