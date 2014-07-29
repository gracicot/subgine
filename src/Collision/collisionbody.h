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

	virtual std::unique_ptr<Results::CollisionResult> testObject(const CollisionBody& other, double time, std::string test) =0;
	void removeCollisionHandler(std::string tag);
	void addCollisionHandler(std::string tag, std::shared_ptr<CollisionHandler> handler);
	std::shared_ptr<CollisionEntity> getCollisionEntity(std::string tag);
	const std::shared_ptr<const CollisionEntity> getCollisionEntity(std::string tag) const;
	void removeCollisionEntity(std::string tag);
	void addCollisionEntity(std::string tag, std::shared_ptr<CollisionEntity> handler);
	void trigger(const CollisionBody& other, std::unique_ptr<Results::CollisionResult> result, std::string tag);

private:
	std::map<std::string, std::shared_ptr<CollisionHandler>> _collisionhandlers;
	std::map<std::string, std::shared_ptr<CollisionEntity>> _collisionEntities;
};


}
}
