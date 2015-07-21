#pragma once

#include "../system.hpp"

#include "CollisionResults/collisionresult.h"

#include <memory>
#include <map>

namespace sbg {

class ResultData;
class CollisionTester;
class CollisionHandler;
class CollisionEntity;
struct Group;

class CollisionBody
{
public:
	CollisionBody() = default;
	CollisionBody(const CollisionBody& other);
	CollisionBody(CollisionBody&& other);
	virtual ~CollisionBody() = default;

	CollisionResult testObject(std::shared_ptr<const Entity> other, Time time, Group* test) const;
	
	void setCollisionEntity(Group* group, std::shared_ptr<CollisionEntity> entity);
	std::shared_ptr<CollisionEntity> getCollisionEntity(Group* group);
	const std::shared_ptr<const CollisionEntity> getCollisionEntity(Group* group) const;
	
	void addCollisionHandler(Group* group, std::unique_ptr<CollisionHandler> collisionHandler);
	void removeCollisionHandler(Group* group);
	
	void setCollisionTester(Group* group, std::unique_ptr<CollisionTester> collisionTester);
	void removeCollisionTester(Group* group);
	
	void trigger(std::shared_ptr<Entity> self, CollisionResult result, Group* test);

	void setMaterial(Material material);
	Material getMaterial() const;

private:
	Material _material;
	std::multimap<Group*, std::unique_ptr<CollisionHandler>> _collisionhandlers;
	std::map<Group*, std::shared_ptr<CollisionEntity>> _collisionEntities;
	std::map<Group*, std::unique_ptr<CollisionTester>> _collisionTesters;
};

}
