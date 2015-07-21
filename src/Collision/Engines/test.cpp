#include "test.h"

using namespace std;

namespace sbg {

Test::Test(weak_ptr<Entity> object, weak_ptr<Entity> other, Group* test, bool reversible) : _object{object}, _other{other}, _test{test}, _reversible{reversible}
{

}


std::weak_ptr<Entity> Test::getObject() const
{
	return _object;
}

std::weak_ptr<Entity> Test::getOther() const
{
	return _other;
}

Group* Test::getTest() const
{
	return _test;
}

void Test::setObject(std::weak_ptr<Entity> object)
{
	_object = object;
}

void Test::setOther(std::weak_ptr<Entity> other)
{
	_other = other;
}

void Test::setTest(Group* test)
{
	_test = test;
}

bool Test::isReversible() const
{
	return _reversible;
}

void Test::reversible(bool reversible)
{
	_reversible = reversible;
}

}
