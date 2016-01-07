#pragma once

#include <string>
#include <memory>

namespace sbg {

struct Entity;
struct Group;

class Test
{
public:
	Test(std::weak_ptr<Entity> object, std::weak_ptr<Entity> other, Group* test, bool reversible);
	
	void setTest(Group* test);
	Group* getTest() const;
	
	std::weak_ptr<Entity> getObject() const;
	void setObject(std::weak_ptr<Entity> object);
	
	std::weak_ptr<Entity> getOther() const;
	void setOther(std::weak_ptr<Entity> other);
	
	bool isReversible() const;
	void reversible(bool reversible);
	
private:
	bool _reversible;
	std::weak_ptr<Entity> _object;
	std::weak_ptr<Entity> _other;
	Group* _test;
};

}
