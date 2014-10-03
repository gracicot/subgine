#include "point.h"

namespace subgine
{
namespace collision
{

Point::Point(std::function< subgine::Vector2d(void) > functor) : _functor(functor)
{
}

Point::~Point()
{

}

Point::operator Vector2d()
{
	return getPosition();
}

Vector2d Point::getPosition() const
{
	return _functor();
}

}
}
