#include "point.h"

using namespace std;

namespace sbg {

Point::Point(Provider<Vector2d> position) : _position{position} {}

Point::operator Vector2d()
{
	return getPosition();
}

Vector2d Point::getPosition() const
{
	return _position();
}

}
