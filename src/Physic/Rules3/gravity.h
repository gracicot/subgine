#pragma once

#include "rule.h"

namespace subgine
{
namespace physic
{
namespace Rule3
{

class Gravity : public Rule
{
public:
	Gravity(const Vector3 value = Vector3());
	Gravity(const Gravity& c);
	virtual ~Gravity();

	virtual Vector3 getResult(const PhysicPoint3& object) const;

	void setValue(const Vector3 value);
	Vector3 getValue() const;

private:
	Vector3 _value;
};

}
}
}
