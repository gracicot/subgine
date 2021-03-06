#pragma once

#include <map>
#include <vector>
#include <mutex>

#include "../../system.hpp"

#include "test.h"

namespace sbg {

struct Group;
struct GroupContainer;

struct CollisionEngine : Engine {
	CollisionEngine();
	void execute(Time time) override;

	void add(std::shared_ptr<Entity> object, std::vector<Group*> groups, std::vector<Group*> collisionGroups);
	void remove(std::weak_ptr<Entity> object);
	

protected:
	bool findByGroup(Group* group, std::pair<const std::weak_ptr<Entity>, std::pair<std::vector<Group*>, std::vector<Group*>>>& object);
	std::mutex _inserting;
	std::mutex _changeTests;
	void makeObjectList();

	std::map<std::weak_ptr<Entity>, std::pair<std::vector<Group*>, std::vector<Group*>>, std::owner_less<std::weak_ptr<Entity>>> _objects;
	bool _listClean;

	std::vector<Test> _tests;
};

}
