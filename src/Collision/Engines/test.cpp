#include "test.h"

subgine::collision::Test::Test(subgine::collision::CollisionBody* object, subgine::collision::CollisionBody* other, std::string test): _object(object), _other(other), _test(test)
{

}

subgine::collision::CollisionBody* subgine::collision::Test::getObject() const
{
	return _object;
}

subgine::collision::CollisionBody* subgine::collision::Test::getOther() const
{
	return _other;
}

std::string subgine::collision::Test::getTest() const
{
	return _test;
}

void subgine::collision::Test::setObject(subgine::collision::CollisionBody* object)
{
	_object = object;
}

void subgine::collision::Test::setOther(subgine::collision::CollisionBody* other)
{
	_other = other;
}

void subgine::collision::Test::setTest(std::string test)
{
	_test = test;
}
