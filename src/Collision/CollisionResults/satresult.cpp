#include "satresult.h"

#include "../collisionbody.h"

using namespace std;

namespace sbg {

SatResult::SatResult(const Vector2d gap, vector<Vector2d> contacts) : _gap(gap), _contacts{move(contacts)}
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

vector< Vector2d > SatResult::getContacts() const
{
	return _contacts;
}

void SatResult::setContacts(vector< Vector2d > contacts)
{
	_contacts = contacts;
}

unique_ptr<ResultData> SatResult::reverse() const
{
	return make_unique<SatResult>(_gap * -1, _contacts);
}

SatResult* SatResult::clone() const
{
	return new SatResult(*this);
}

}
