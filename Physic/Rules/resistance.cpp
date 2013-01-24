#include "resistance.h"

namespace Rule
{

Resistance::Resistance(const Resistance& c) : _value(c._value)
{

}

Resistance::Resistance(const Vector value) : _value(value)
{
	
}

Resistance::~Resistance()
{

}

Vector Resistance::getResult(const PhysicPoint& object) const
{
	return -1*object.getVelocity() * getValue();
}

Vector Resistance::getValue() const
{
	return _value;
}

void Resistance::setValue(const Vector value)
{
	_value = value;
}

}
