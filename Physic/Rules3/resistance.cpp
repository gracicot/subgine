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

Vector3 Resistance::apply(const PhysicPoint3& object, double time) const
{
	return Vector3(
			   -object.getVelocity().x * ((getValue().x)),
			   -object.getVelocity().y * ((getValue().y)),
			   -object.getVelocity().z * ((getValue().z))
		   );
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
