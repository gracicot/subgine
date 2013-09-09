#include "spring.h"

#include "../physicpoint3.h"

namespace subgine
{
namespace physic
{
namespace Rule3
{

	Spring::Spring(const subgine::Vector3 value, const double size, std::function< subgine::Vector3(void) > functor) : _value(value), _size(size), _functor(functor)
	{
		
	}
	
	Spring::Spring(const Vector3 value, const double size, const Vector3 position) : _value(value), _size(size), _functor(nullptr), _position(position)
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
	
	Vector3 Spring::getPosition() const
	{
		if (_functor) {
			return _functor();
		} else {
			return _position;
		}
	}
	
	void Spring::setPosition(std::function< subgine::Vector3(void) > functor)
	{
		_functor = functor;
	}
	
	void Spring::setPosition(Vector3 pos)
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
	
	Vector3 Spring::getResult(const PhysicPoint3& object) const
	{
		Vector3 relative = getPosition() - object.getPosition();
		return relative.unit() * getValue() * (relative.getLenght() - getSize());
	}
	
	Vector3 Spring::getValue() const
	{
		return _value;
	}
	
	void Spring::setValue(const Vector3 value)
	{
		_value = value;
	}

}
}
}
