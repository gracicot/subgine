#pragma once

#include "../collisionnable.h"
#include "../CollisionResults/collisionresult.h"

class CollisionTester
{
public:
	CollisionTester() = default;
	virtual ~CollisionTester();

	virtual CollisionResult* compareObject(Collisionnable::Collisionnable& object1, Collisionnable::Collisionnable& object2, double time) const = 0;
	void addObject(Collisionnable::Collisionnable& object, double time);

	void setAlias(std::string alias);
	std::string getAlias() const;

private:
	std::string _alias;
};
