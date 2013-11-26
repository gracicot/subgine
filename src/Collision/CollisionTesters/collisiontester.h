#pragma once

#include "../collisionbody.h"
#include "../CollisionResults/collisionresult.h"

namespace subgine
{
namespace collision
{
namespace Testers
{

class CollisionTester
{
public:
	CollisionTester() = default;
	virtual ~CollisionTester();

	virtual Results::CollisionResult* compareObject(CollisionBody& object1, CollisionBody& object2, double time) const = 0;
	void addObject(CollisionBody& object, double time);

	void setAlias(std::string alias);
	std::string getAlias() const;

private:
	std::string _alias;
};

}
}
}
