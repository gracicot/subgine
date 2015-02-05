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

class CollisionBody
{
public:
	CollisionBody();
	CollisionBody(const CollisionBody& other);
	CollisionBody(CollisionBody&& other);
	virtual ~CollisionBody();

	CollisionResult testObject(std::shared_ptr<const CollisionBody> other, Time time, std::string test) const;
	
	std::multimap<std::string, std::shared_ptr<CollisionHandler>>& getCollisionHandler();
	const std::multimap<std::string, std::shared_ptr<CollisionHandler>>& getCollisionHandler() const;
	std::vector<std::shared_ptr<CollisionHandler>> getCollisionHandler(const std::string tag);
	std::vector< std::shared_ptr< const CollisionHandler > > getCollisionHandler(const std::string tag) const;
	
	std::map<std::string, std::unique_ptr<CollisionTester>>& getCollisionTester();
	const std::map<std::string, std::unique_ptr<CollisionTester>>& getCollisionTester() const;
	
	std::shared_ptr<CollisionEntity> getCollisionEntity(std::string tag);
	const std::shared_ptr<const CollisionEntity> getCollisionEntity(std::string tag) const;
	std::map<std::string, std::shared_ptr<CollisionEntity>>& getCollisionEntity();
	const std::map<std::string, std::shared_ptr<CollisionEntity>>& getCollisionEntity() const;
	
	void trigger(CollisionResult result, std::string test);

	void setMaterial(Material material);
	Material getMaterial() const;

private:
	Material _material;
	std::multimap<std::string, std::shared_ptr<CollisionHandler>> _collisionhandlers;
	std::map<std::string, std::shared_ptr<CollisionEntity>> _collisionEntities;
	std::map<std::string, std::unique_ptr<CollisionTester>> _collisionTesters;
};

}
