#include "point.h"

namespace Collisionnable
{

Point::Point(Vector2 position)
{
	_position = position;
}

Point::~Point()
{

}

Point::operator Vector2()
{
	return _position;
}

}
