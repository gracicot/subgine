#pragma once

#include "../../system.hpp"


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
	void makeObjectList();

	std::map<std::string, std::vector<std::tuple<CollisionBody*, std::string>>> _groups;

	std::vector<std::tuple<CollisionBody*, CollisionBody*, std::string>> _objects;
};

}
}
