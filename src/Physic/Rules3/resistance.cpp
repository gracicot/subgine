#include "resistance.h"

#include "../physicpoint3.h"

namespace subgine
{
namespace physic
{
namespace Rule3
{

Resistance::Resistance(const Resistance& c) : _value(c._value)
{

}

Resistance::Resistance(const Vector3 value) : _value(value)
{

}

Resistance::~Resistance()
{

}

Vector3 Resistance::getResult(const PhysicPoint3& object) const
{
	return -1 * object.getVelocity() * getValue();
}

Vector3 Resistance::getValue() const
{
	return _value;
}

void Resistance::setValue(const Vector3 value)
{
	_value = value;
}

}
}
}
