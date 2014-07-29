#include "collisionbody.h"

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

void CollisionBody::addCollisionHandler(std::string tag, std::shared_ptr< subgine::collision::CollisionHandler > handler)
{
	_collisionhandlers[tag] = handler;
}

void CollisionBody::trigger(const subgine::collision::CollisionBody& other, std::unique_ptr< subgine::collision::Results::CollisionResult > result, std::string tag)
{
	auto it = _collisionhandlers.find(tag);

	if (it != _collisionhandlers.end()) {
		it->second->apply(*this, other, *result);
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

void CollisionBody::addCollisionEntity(std::string tag, std::shared_ptr< CollisionEntity > handler)
{
	_collisionEntities[tag] = handler;
}

void CollisionBody::removeCollisionEntity(std::string tag)
{
	_collisionEntities.erase(tag);
}

void CollisionBody::removeCollisionHandler(std::string tag)
{
	_collisionhandlers.erase(tag);
}

const std::shared_ptr<const CollisionEntity> CollisionBody::getCollisionEntity(std::string tag) const
{
	auto it = _collisionEntities.find(tag);
	
	if (it != _collisionEntities.end()) {
		return it->second;
	}
	
	throw std::out_of_range("CollisionEntity with tag \"" + tag + "\" not found...");
}

}
}
