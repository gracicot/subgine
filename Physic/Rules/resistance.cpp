#include "resistance.h"

#include "../physicpoint.h"

namespace Rule
{

Resistance::Resistance(const Resistance& c) : _value(c._value)
{

}

Resistance::Resistance(const Vector2 value) : _value(value)
{
	
}

Resistance::~Resistance()
{

}

Vector2 Resistance::getResult(const PhysicPoint& object) const
{
	return -1*object.getVelocity() * getValue();
}

Vector2 Resistance::getValue() const
{
	return _value;
}

void Resistance::setValue(const Vector2 value)
{
	_value = value;
}

}
