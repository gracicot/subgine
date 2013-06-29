#include "point.h"

namespace subgine
{
namespace collision
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
}
