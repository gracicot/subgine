#pragma once

#include <string>
#include <memory>

namespace sbg {

class CollisionBody;
struct Group;

class Test
{
public:
	Test(std::weak_ptr<CollisionBody> object, std::weak_ptr<CollisionBody> other, Group* test, bool reversible);
	
	void setTest(Group* test);
	Group* getTest() const;
	
	std::weak_ptr<CollisionBody> getObject() const;
	void setObject(std::weak_ptr<CollisionBody> object);
	
	std::weak_ptr<CollisionBody> getOther() const;
	void setOther(std::weak_ptr<CollisionBody> other);
	
	bool isReversible() const;
	void reversible(bool reversible);
	
private:
	bool _reversible;
	std::weak_ptr<CollisionBody> _object;
	std::weak_ptr<CollisionBody> _other;
	Group* _test;
};

}
