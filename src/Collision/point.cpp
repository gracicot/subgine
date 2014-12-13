#include "point.h"

using namespace std;

namespace sbg {

Point::Point(function< Vector2d(void) > functor) : _functor(functor)
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
