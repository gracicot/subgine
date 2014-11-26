#pragma once

#include <map>
#include <vector>
#include <mutex>

#include "../../system.hpp"

#include "test.h"

namespace subgine
{
namespace collision
{

class CollisionBody;

class Collision : public Engine
{

public:
	Collision();
	virtual ~Collision();

	virtual void execute(const double time);

	void add(subgine::collision::CollisionBody* object, std::vector< std::string > groups, std::vector< std::string > collisionGroups);
	void remove(CollisionBody& object);

protected:
	std::mutex _inserting;
	void makeObjectList();

	std::map<CollisionBody*, std::pair<std::vector<std::string>, std::vector<std::string>>> _objects;
	bool _listClean;

	std::vector<Test> _test;
};

}
}
