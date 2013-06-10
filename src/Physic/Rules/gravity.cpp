#include "gravity.h"

#include "../physicpoint.h"

namespace Rule
{

Gravity::Gravity(const Gravity& c) : _value(c._value)
{

}

Gravity::Gravity(const Vector2 value) : _value(value)
{

}

Gravity::~Gravity()
{

}

Vector2 Gravity::getResult(const PhysicPoint& object) const
{
	return _value * object.getMass();
}

Vector2 Gravity::getValue() const
{
	return _value;
}

void Gravity::setValue(const Vector2 value)
{
	_value = value;
}

}
