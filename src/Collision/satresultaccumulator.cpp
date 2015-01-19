#include "satresultaccumulator.h"

#include "CollisionResults/satresult.h"

#include <iostream>

using namespace std;

namespace sbg {

Accumulator< SatResult >::Accumulator() : _count(0)
{

}

SatResult Accumulator<SatResult>::flush()
{
	SatResult result;
	result.setContacts(_contacts);
	result.setGap(_total / _count);
	_contacts.clear();
	_total = Vector2d();
	_count = 0;
	return result;
}

void Accumulator<SatResult>::take(SatResult value)
{
	_total += value.getGap();
	_count++;
	auto contacts = value.getContacts();
	_contacts.insert(_contacts.end(), contacts.begin(), contacts.end());
}

}
