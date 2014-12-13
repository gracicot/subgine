#include "angle.h"

using namespace std;

namespace sbg {

Traits::Angle::Angle(double angle) : _angle(angle)
{

}

double Traits::Angle::getAngle() const
{
	return _angle;
}

}
