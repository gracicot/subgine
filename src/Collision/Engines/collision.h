#pragma once

#include <map>
#include <vector>
#include <mutex>

#include "../../system.hpp"

#include "test.h"

namespace sbg {

class CollisionBody;

class Collision : public Engine
{

public:
	Collision();
	virtual ~Collision();

	virtual void execute(const double time);

	void add(std::weak_ptr<CollisionBody> object, std::vector<std::string> groups, std::vector<std::string> collisionGroups);
	void remove(std::weak_ptr<CollisionBody> object);

protected:
	std::mutex _inserting;
	void makeObjectList();

	std::map<std::weak_ptr<CollisionBody>, std::pair<std::vector<std::string>, std::vector<std::string>>, std::owner_less<std::weak_ptr<CollisionBody>>> _objects;
	bool _listClean;

	std::vector<Test> _test;
};

}
