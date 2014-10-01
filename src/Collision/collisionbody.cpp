#include "collisionbody.h"

#include "CollisionTester/collisiontester.h"
#include "collisionentity.h"
#include "CollisionHandlers/collisionhandler.h"
#include "CollisionResults/collisionresult.h"

namespace subgine
{
namespace collision
{

CollisionBody::CollisionBody()
{

}

CollisionBody::CollisionBody(const CollisionBody& other)
{
	for (auto entity : other._collisionEntities) {
		_collisionEntities[entity.first] = std::shared_ptr<CollisionEntity>(entity.second->clone());
	}
	
	for (auto handler : _collisionhandlers) {
		_collisionhandlers[handler.first] = std::shared_ptr<CollisionHandler>(handler.second->clone());
	}
}

CollisionBody::~CollisionBody()
{
	
}

std::unique_ptr< Results::CollisionResult > CollisionBody::testObject(const CollisionBody& other, double time, std::string test) const
{
	auto it = _collisionTesters.find(test);
	
	if (it != _collisionTesters.end()) {
		return it->second->test(*this, other, time, test);
	}
	
	return std::unique_ptr<Results::CollisionResult>(nullptr);
}

void CollisionBody::trigger(const subgine::collision::CollisionBody& other, std::unique_ptr< subgine::collision::Results::CollisionResult > result, std::string tag)
{
	auto it = _collisionhandlers.find(tag);

	if (it != _collisionhandlers.end()) {
		it->second->apply(*this, *result);
	}
}

std::shared_ptr<CollisionEntity> CollisionBody::getCollisionEntity(std::string tag)
{
	auto it = _collisionEntities.find(tag);
	
	if (it != _collisionEntities.end()) {
		return it->second;
	}
	
	throw std::out_of_range("CollisionEntity with tag \"" + tag + "\" not found...");
}

const std::shared_ptr<const CollisionEntity> CollisionBody::getCollisionEntity(std::string tag) const
{
	auto it = _collisionEntities.find(tag);
	
	if (it != _collisionEntities.end()) {
		return it->second;
	}
	
	throw std::out_of_range("CollisionEntity with tag \"" + tag + "\" not found...");
}

const std::map< std::string, std::shared_ptr< CollisionEntity > >& CollisionBody::getCollisionEntity() const
{
	return _collisionEntities;
}

std::map< std::string, std::shared_ptr< CollisionEntity > >& CollisionBody::getCollisionEntity()
{
	return _collisionEntities;
}

const std::shared_ptr< CollisionHandler >& CollisionBody::getCollisionHandler(const std::string tag) const
{
	auto it = _collisionhandlers.find(tag);
	
	if (it != _collisionhandlers.end()) {
		return it->second;
	}
	
	throw std::out_of_range("CollisionHandler with tag \"" + tag + "\" not found...");
}

std::shared_ptr< CollisionHandler >& CollisionBody::getCollisionHandler(const std::string tag)
{
	auto it = _collisionhandlers.find(tag);
	
	if (it != _collisionhandlers.end()) {
		return it->second;
	}
	
	throw std::out_of_range("CollisionHandler with tag \"" + tag + "\" not found...");
}

const std::map< std::string, std::shared_ptr< CollisionHandler > >& CollisionBody::getCollisionHandler() const
{
	return _collisionhandlers;
}

std::map< std::string, std::shared_ptr< CollisionHandler > >& CollisionBody::getCollisionHandler()
{
	return _collisionhandlers;
}

const std::map< std::string, std::unique_ptr< CollisionTester > >& CollisionBody::getCollisionTester() const
{
	return _collisionTesters;
}

std::map< std::string, std::unique_ptr< CollisionTester > >& CollisionBody::getCollisionTester()
{
	return _collisionTesters;
}

Material CollisionBody::getMaterial() const
{
	return _material;
}

void CollisionBody::setMaterial(Material material)
{
	_material = material;
}

}
}
