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
		_collisionEntities[entity.first] = entity.second->clone();
	}
	
	for (auto handler : _collisionhandlers) {
		_collisionhandlers[handler.first] = handler.second->clone();
	}
}

CollisionBody::~CollisionBody()
{
	for (auto handler : _collisionhandlers) {
		delete handler.second;
	}
	
	for (auto entity : _collisionEntities) {
		delete entity.second;
	}
}

void CollisionBody::addCollisionHandler(std::string tag, CollisionHandler* handler)
{
	_collisionhandlers[tag] = handler;
}

void CollisionBody::trigger(const subgine::collision::CollisionBody& other, subgine::collision::Results::CollisionResult* result, std::string tag)
{
	auto it = _collisionhandlers.find(tag);

	if (it != _collisionhandlers.end()) {
		it->second->apply(*this, other, *result);
	}
}

CollisionEntity& CollisionBody::getCollisionEntity(std::string tag)
{
	auto it = _collisionEntities.find(tag);
	
	if (it != _collisionEntities.end()) {
		return *it->second;
	}
	
	throw std::out_of_range("CollisionEntity with tag \"" + tag + "\" not found...");
}

const CollisionEntity& CollisionBody::getCollisionEntity(std::string tag) const
{
	auto it = _collisionEntities.find(tag);
	
	if (it != _collisionEntities.end()) {
		return *it->second;
	}
	
	throw std::out_of_range("CollisionEntity with tag \"" + tag + "\" not found...");
}

}
}
