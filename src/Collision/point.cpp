#include "point.h"

namespace subgine
{
namespace collision
{

Point::Point(std::function< subgine::Vector2(void) > functor) : _functor(functor)
{
}

Point::~Point()
{

}

Point::operator Vector2()
{
	return getPosition();
}

Vector2 Point::getPosition() const
{
	return _functor();
}

}
}
