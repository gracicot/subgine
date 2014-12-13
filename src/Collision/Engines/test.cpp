#include "test.h"

using namespace std;

namespace sbg {

Test::Test(CollisionBody* object, CollisionBody* other, std::string test): _object(object), _other(other), _test(test)
{

}

CollisionBody* Test::getObject() const
{
	return _object;
}

CollisionBody* Test::getOther() const
{
	return _other;
}

std::string Test::getTest() const
{
	return _test;
}

void Test::setObject(CollisionBody* object)
{
	_object = object;
}

void Test::setOther(CollisionBody* other)
{
	_other = other;
}

void Test::setTest(std::string test)
{
	_test = test;
}

}
