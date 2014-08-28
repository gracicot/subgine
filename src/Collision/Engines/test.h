#pragma once

#include <string>

namespace subgine {
namespace collision {

class CollisionBody;

class Test
{
public:
	Test(CollisionBody* object, CollisionBody* other, std::string test);
	
	void setTest(std::string test);
	std::string getTest() const;
	
	CollisionBody* getObject() const;
	void setObject(CollisionBody* object);
	
	CollisionBody* getOther() const;
	void setOther(CollisionBody* other);
	
private:
	CollisionBody* _object;
	CollisionBody* _other;
	std::string _test;
};

}
}