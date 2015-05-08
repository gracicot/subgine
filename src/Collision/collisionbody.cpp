#include "collisionbody.h"

#include "CollisionTester/collisiontester.h"
#include "collisionentity.h"
#include "CollisionHandlers/collisionhandler.h"
#include "CollisionResults/collisionresult.h"
#include "CollisionResults/resultdata.h"

using namespace std;

namespace sbg {

CollisionBody::CollisionBody(CollisionBody&& other) :
	_material(move(other._material)),
	_collisionhandlers(move(other._collisionhandlers)),
	_collisionEntities(move(other._collisionEntities)),
	_collisionTesters(move(other._collisionTesters))
{}

CollisionBody::CollisionBody(const CollisionBody& other) :
	_material(other._material)
{
	for (auto& tester : other._collisionTesters) {
		_collisionTesters.emplace(tester.first, clone_unique(tester.second));
	}
	for (auto& entity : other._collisionEntities) {
		_collisionEntities.emplace(entity.first, clone_shared(entity.second));
	}
	for (auto& entity : other._collisionhandlers) {
		_collisionhandlers.emplace(entity.first, clone_unique(entity.second));
	}
}

void CollisionBody::addCollisionHandler(Group* group, unique_ptr<CollisionHandler> collisionHandler)
{
	_collisionhandlers.emplace(group, move(collisionHandler));
}

void CollisionBody::setCollisionTester(Group* group, unique_ptr<CollisionTester> collisionTester)
{
	_collisionTesters[group] = move(collisionTester);
}

void CollisionBody::removeCollisionHandler(Group* group)
{
	_collisionhandlers.erase(group);
}

void CollisionBody::removeCollisionTester(Group* group)
{
	_collisionTesters.erase(group);
}

void CollisionBody::setCollisionEntity(Group* group, shared_ptr<CollisionEntity> entity)
{
	_collisionEntities[group] = move(entity);
}

CollisionResult CollisionBody::testObject(shared_ptr<const CollisionBody> other, Time time, Group* test) const
{
	auto it = _collisionTesters.find(test);
	
	if (it != _collisionTesters.end()) {
		auto entityThis = getCollisionEntity(test);
		auto entityOther = other->getCollisionEntity(test);
		
		if (entityThis && entityOther) {
			auto data = it->second->test(entityThis, entityOther);
			return CollisionResult(other, data.second, move(data.first), time);
		}
	}
	
	return CollisionResult(other, false, nullptr, time);
}

void CollisionBody::trigger(CollisionResult result, Group* test)
{
	auto range = _collisionhandlers.equal_range(test);
	
	for(auto it = range.first ; it != range.second ; it++) {
		it->second->apply(*this, result);
	}
}

shared_ptr<CollisionEntity> CollisionBody::getCollisionEntity(Group* group)
{
	auto it = _collisionEntities.find(group);
	
	if (it != _collisionEntities.end()) {
		return it->second;
	}
	
	return nullptr;
}

const shared_ptr<const CollisionEntity> CollisionBody::getCollisionEntity(Group* group) const
{
	auto it = _collisionEntities.find(group);
	
	if (it != _collisionEntities.end()) {
		return it->second;
	}
	
	return nullptr;
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
