#include "spring.h"

#include "../physicpoint.h"

namespace subgine
{
namespace physic
{
namespace Rule
{

Spring::Spring(const subgine::Vector2 value, const double size, std::function< subgine::Vector2(void) > functor) : _value(value), _size(size), _functor(functor)
{
	
}

Spring::Spring(const Vector2 value, const double size, const Vector2 position) : _value(value), _size(size), _functor(nullptr), _position(position)
{
	
}

Spring::Spring(const Spring& other)
{
	_functor = other._functor;
	_position = other._position;
	_size = other._size;
	_value = other._value;
}

Spring::~Spring()
{
	
}

Vector2 Spring::getPosition() const
{
	if (_functor) {
		return _functor();
	} else {
		return _position;
	}
}

void Spring::setPosition(std::function< subgine::Vector2(void) > functor)
{
	_functor = functor;
}

void Spring::setPosition(Vector2 pos)
{
	_functor = nullptr;
	_position = pos;
}

double Spring::getSize() const
{
	return _size;
}

void Spring::setSize(const double size)
{
	_size = size;
}

Vector2 Spring::getResult(const PhysicPoint& object) const
{
	Vector2 relative = getPosition() - object.getPosition();
	return relative.unit() * getValue() * (relative.getLenght() - getSize());
}

Vector2 Spring::getValue() const
{
	return _value;
}

void Spring::setValue(const Vector2 value)
{
	_value = value;
}

}
}
}
