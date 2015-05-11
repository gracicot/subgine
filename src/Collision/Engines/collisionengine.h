#pragma once

#include <map>
#include <vector>
#include <mutex>

#include "../../system.hpp"

#include "test.h"

namespace sbg {

struct Group;
class CollisionBody;
class GroupContainer;

class CollisionEngine : public Engine
{
public:
	CollisionEngine();
	void execute(Time time) override;

	void add(std::weak_ptr<CollisionBody> object, std::vector<Group*> groups, std::vector<Group*> collisionGroups);
	void remove(std::weak_ptr<CollisionBody> object);

protected:
	std::mutex _inserting;
	std::mutex _changeTests;
	void makeObjectList();

	std::map<std::weak_ptr<CollisionBody>, std::pair<std::vector<Group*>, std::vector<Group*>>, std::owner_less<std::weak_ptr<CollisionBody>>> _objects;
	bool _listClean;

	std::vector<Test> _tests;
};

}
