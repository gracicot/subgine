#include "spring.h"

#include "../physicpoint.h"

namespace Rule
{

Spring::Spring(const Vector2 value, const double size, Positionnable& position) : _deletePosition(false), _value(value), _size(size)
{
	setPosition(position);
}

Spring::Spring(const Vector2 value, const double size, const Vector2 position) : _deletePosition(false), _value(value), _size(size)
{
	setPosition(position);
}

Spring::Spring(const Spring& other)
{
	if (_deletePosition) {
		delete _position;
	}

	_deletePosition = other._deletePosition;
	_position = other._position;
	_size = other._size;
	_value = other._value;
}

Spring::~Spring()
{
	if (_deletePosition) {
		delete _position;
	}
}

Vector2 Spring::getPosition() const
{
	if (_position == nullptr) {
		return Vector2();
	}

	return _position->getPosition();
}

void Spring::setPosition(Positionnable& position)
{
	if (_deletePosition) {
		delete _position;
	}

	_deletePosition = false;
	_position = &position;
}

void Spring::setPosition(Vector2 pos)
{
	if (_deletePosition) {
		Vector2* position = dynamic_cast<Vector2*>(_position);
		*position = pos;
	} else {
		_position = new Vector2(pos);
	}

	_deletePosition = true;
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

