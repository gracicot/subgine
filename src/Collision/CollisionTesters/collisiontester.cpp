#include "collisiontester.h"

CollisionTester::~CollisionTester()
{

}

std::string CollisionTester::getAlias() const
{
	return _alias;
}

void CollisionTester::setAlias(std::string alias)
{
	_alias = alias;
}
