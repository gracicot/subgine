#include "resistance.h"

namespace Rule3
{

Resistance::Resistance(const Resistance& c) : _value(c._value)
{

}

Resistance::Resistance(Vector3 value) : _value(value)
{
	
}

Resistance::~Resistance()
{

}

Vector3 Resistance::getResult(const PhysicPoint3& object) const
{
	return -1*object.getVelocity() * getValue();
}

Vector3 Resistance::getValue() const
{
	return _value;
}

void Resistance::setValue(Vector3 value)
{
	_value = value;
}

}
