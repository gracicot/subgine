#pragma once

#include "../../system.hpp"

#include "../collisionnable.h"
#include "../CollisionTesters/collisiontester.h"

namespace subgine
{
namespace collision
{

class Collision : public Engine
{

public:
	Collision();
	virtual ~Collision();

	virtual void execute(const double time);

	Testers::CollisionTester& getTester(const std::string tag);
	const Testers::CollisionTester& getTester(const std::string tag) const;

	void addTester(Testers::CollisionTester* tester, const std::string tag);
	void add(Collisionnable* object, std::list< std::string > groups);
	void remove(Collisionnable& object);
	void remove(Collisionnable& object, std::list< std::string > groups);
	void addTest(std::string tester, std::string group1, std::string group2);
	void removeTest(std::string tester, std::string group1, std::string group2);
	void clear();

protected:
	void makeObjectList();

	std::map<std::string, std::list<Collisionnable*>> _groups;
	std::map<std::string, Testers::CollisionTester*> _testers;

	std::vector<std::tuple<std::string, std::string, std::string>> _testDefinition;
	std::vector<std::tuple<Testers::CollisionTester*, Collisionnable*, Collisionnable*>> _objects;
};

}
}
