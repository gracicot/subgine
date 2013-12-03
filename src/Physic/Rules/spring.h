#pragma once

#include <functional>
#include <iostream>

#include "rule.h"
#include "../physicpoint.h"


namespace subgine
{
namespace physic
{
namespace Rule
{

template<int n>
class Spring : public Rule<n>
{
public:
	Spring(const Vector<n, double> value, const double size, std::function< Vector<n, double>(void) > functor) : _value(value), _size(size), _functor(functor)
	{
		
	}
	
	Spring(const Vector<n, double> value, const double size, const Vector<n, double> position) : _value(value), _size(size), _functor(nullptr), _position(position)
	{
		
	}
	
	Spring(const Spring& other)
	{
		_functor = other._functor;
		_position = other._position;
		_size = other._size;
		_value = other._value;
	}
	
	~Spring()
	{
		
	}
	
	Vector<n, double> getPosition() const
	{
		if (_functor) {
			return _functor();
		} else {
			return _position;
		}
	}
	
	void setPosition(std::function< Vector<n, double>(void) > functor)
	{
		_functor = functor;
	}
	
	void setPosition(Vector<n, double> pos)
	{
		_functor = nullptr;
		_position = pos;
	}
	
	double getSize() const
	{
		return _size;
	}
	
	void setSize(const double size)
	{
		_size = size;
	}
	
	Vector<n, double> getResult(const PhysicPoint<n>& object) const
	{
		Vector<n, double> relative = getPosition() - object.getPosition();
		return relative.unit() * getValue() * (relative.getLength() - getSize());
	}
	
	Vector<n, double> getValue() const
	{
		return _value;
	}
	
	void setValue(const Vector<n, double> value)
	{
		_value = value;
	}

private:
	Vector<n, double>  _value;
	double _size;

	Vector<n, double> _position;
	std::function< Vector<n, double>(void) > _functor;
};

}
}
}
