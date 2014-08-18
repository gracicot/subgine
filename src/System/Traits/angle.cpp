#include "angle.h"

namespace subgine
{

Traits::Angle::Angle(double angle) : _angle(angle)
{

}

double Traits::Angle::getAngle() const
{
	return _angle;
}

}
