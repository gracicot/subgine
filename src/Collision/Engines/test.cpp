#include "test.h"

using namespace std;

namespace sbg {

Test::Test(weak_ptr<CollisionBody> object, weak_ptr<CollisionBody> other, Group* test) : _object{object}, _other{other}, _test{test}
{

}


std::weak_ptr<CollisionBody> Test::getObject() const
{
	return _object;
}

std::weak_ptr<CollisionBody> Test::getOther() const
{
	return _other;
}

Group* Test::getTest() const
{
	return _test;
}

void Test::setObject(std::weak_ptr<CollisionBody> object)
{
	_object = object;
}

void Test::setOther(std::weak_ptr<CollisionBody> other)
{
	_other = other;
}

void Test::setTest(Group* test)
{
	_test = test;
}

}
