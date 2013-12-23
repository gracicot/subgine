#pragma once

#include "../system.hpp"

#include "CollisionHandlers/collisionhandler.h"
#include "CollisionResults/collisionresult.h"
#include "collisionentity.h"

namespace subgine
{
namespace collision
{

class CollisionBody
{
public:
	CollisionBody();
	CollisionBody(const CollisionBody& other);
	virtual ~CollisionBody();

	virtual Results::CollisionResult* testObject(const CollisionBody& other, double time, std::string test) const =0;
	void removeCollisionHandler(std::string tag);
	void addCollisionHandler(std::string tag, CollisionHandler* handler);
	CollisionEntity& getCollisionEntity(std::string tag);
	const CollisionEntity& getCollisionEntity(std::string tag) const;
	void trigger(const CollisionBody& other, Results::CollisionResult* result, std::string tag);

protected:
	std::map<std::string, CollisionHandler*> _collisionhandlers;
	std::map<std::string, CollisionEntity*> _collisionEntities;
};


}
}
