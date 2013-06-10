#pragma once

#include "rule.h"

namespace Rule3
{

class Attraction : public Rule
{
public:
	Attraction(const Vector3 value = Vector3());
	Attraction(const Attraction& c);

	virtual Vector3 getResult(const PhysicPoint3& object) const;

	void addObject(const PhysicPoint3& object);
	void removeObject(const PhysicPoint3& object);

	void setValue(const Vector3 value);
	Vector3 getValue() const;

private:
	std::list<const PhysicPoint3*> _objects;
	Vector3 _value;
};

}
