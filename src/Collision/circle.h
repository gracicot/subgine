#pragma once

#include "sat_able.h"
#include "point_able.h"

namespace sbg {

class Circle : public virtual SAT_able
{
public:
	Circle();
	Circle(std::shared_ptr<PositionProvider2D> provider);

	bool isPointInside(Vector2d point) const override;
	std::pair<double, double> projection(double angle) const override;
	Vector2d overlap(const SAT_able& other) const override;
	Vector2d getNearestPoint(Vector2d point) const override;
	std::pair< Vector2d, Vector2d > getBoundingBox() const override;
	
	Vector2d getPosition() const;
	void setPositionProvider(std::shared_ptr<PositionProvider2D> provider);
	
	void setShape(std::shared_ptr<shape::Circle> shape);
	std::shared_ptr<shape::Circle> getShape() const;
	
	Circle* clone() const override;
private:
	std::shared_ptr<shape::Circle> _shape;
	std::shared_ptr<PositionProvider2D> _provider;
};

}
