#pragma once

#include "rule.h"

namespace Rule
{

class Attraction : public Rule
{
public:
	Attraction(const Vector2 value = Vector2());
	Attraction(const Attraction& c);

	virtual Vector2 getResult(const PhysicPoint& object) const;

	void addObject(const PhysicPoint& object);
	void removeObject(const PhysicPoint& object);

	void setValue(const Vector2 value);
	Vector2 getValue() const;

private:
	std::list<const PhysicPoint*> _objects;
	Vector2 _value;
};

}
