#include "attraction.h"

#include "../physicpoint.h"

namespace Rule
{

Attraction::Attraction(const Attraction& c) : _value(c._value), _objects(c._objects)
{

}

Attraction::Attraction(const Vector2 value) : _value(value)
{

}

Vector2 Attraction::getResult(const PhysicPoint& object) const
{
	Vector2 result;
	Vector2 absolute;
	
for(auto i : _objects)
	{
		absolute = i->getPosition() - object.getPosition();
		result +=  (absolute.unit() * i->getMass() * object.getMass()) / (pow2(absolute.x) + pow2(absolute.y));	  
	}

	return result * getValue();
}

void Attraction::addObject(const PhysicPoint& object)
{
	_objects.remove(&object);
	_objects.push_back(&object);
}

void Attraction::removeObject(const PhysicPoint& object)
{
	_objects.remove(&object);
}

Vector2 Attraction::getValue() const
{
	return _value;
}

void Attraction::setValue(const Vector2 value)
{
	_value = value;
}

}

