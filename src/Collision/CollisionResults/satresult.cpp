#include "satresult.h"

#include "../collisionbody.h"

using namespace std;

namespace sbg {

SatResult::SatResult(const Vector2d gap) : _gap(gap)
{

}

Vector2d SatResult::getGap() const
{
	return _gap;
}

void SatResult::setGap(const Vector2d gap)
{
	_gap = gap;
}

std::vector< Vector2d > SatResult::getContacts() const
{
	return _contacts;
}

void SatResult::setContacts(std::vector< Vector2d > contacts)
{
	_contacts = contacts;
}

SatResult* SatResult::clone() const
{
	return new SatResult(*this);
}

}
