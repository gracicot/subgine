#include "satresultaccumulator.h"

#include "CollisionResults/satresult.h"

#include <iostream>

using namespace std;

namespace sbg {

Accumulator< SatResult >::Accumulator() : _count(0)
{

}

Accumulator<SatResult>::operator SatResult() const
{
	SatResult result;
	result.setContacts(_contacts);
	result.setGap(_total / _count);
	return result;
}

void Accumulator<SatResult>::operator+=(SatResult value)
{
	_total += value.getGap();
	_count++;
	auto contacts = value.getContacts();
	_contacts.insert(_contacts.end(), contacts.begin(), contacts.end());
}

void Accumulator<SatResult>::clear()
{
	_contacts.clear();
	_total = Vector2d();
	_count = 0;
}

bool Accumulator<SatResult>::empty() const
{
	return _count == 0;
}

int Accumulator<SatResult>::count() const
{
	return _count;
}

}
