#pragma once

#include "rule.h"

namespace subgine
{
namespace physic
{
namespace Rule
{

class Resistance : public Rule
{
public:
	Resistance(const Vector2 value = Vector2());
	Resistance(const Resistance& c);
	virtual ~Resistance();

	virtual Vector2 getResult(const PhysicPoint& object) const;

	void setValue(const Vector2 value);
	Vector2 getValue() const;

private:
	Vector2 _value;
};

}
}
}
