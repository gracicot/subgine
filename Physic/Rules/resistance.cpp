#include "resistance.h"

namespace Rule
{

Resistance::Resistance(const Resistance& c) : _value(c._value)
{

}

Resistance::Resistance(Vector value) : _value(value)
{
	
}

Resistance::~Resistance()
{

}

Vector Resistance::apply(const PhysicPoint& object, double time) const
{
	return Vector(
			   -object.getVelocity().x * ((getValue().x)),
			   -object.getVelocity().y * ((getValue().y))
		   );
}

Vector Resistance::getValue() const
{
	return _value;
}

void Resistance::setValue(Vector value)
{
	_value = value;
}

}
