#include "collisionbody.h"

#include "CollisionTester/collisiontester.h"
#include "collisionentity.h"
#include "CollisionHandlers/collisionhandler.h"
#include "CollisionResults/collisionresult.h"

using namespace std;

namespace subgine
{
namespace collision
{

CollisionBody::CollisionBody(CollisionBody && other) :
	_material(move(other._material)),
	_collisionhandlers(move(other._collisionhandlers)),
	_collisionEntities(move(other._collisionEntities)),
	_collisionTesters(move(other._collisionTesters))
{}

CollisionBody::CollisionBody(const CollisionBody& other) :
	_material(other._material),
	_collisionhandlers(other._collisionhandlers),
	_collisionEntities(other._collisionEntities)
{
	for (auto& tester : other._collisionTesters) {
		_collisionTesters.insert(std::pair<std::string, std::unique_ptr<CollisionTester>>(tester.first, std::unique_ptr<CollisionTester>(tester.second->clone())));
	}
}

CollisionBody::CollisionBody()
{

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
	auto range = _collisionhandlers.equal_range(tag);
	for(auto it = range.first ; it != range.second ; it++) {
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

std::vector<std::shared_ptr< const CollisionHandler >> CollisionBody::getCollisionHandler(const std::string tag) const
{
	auto range = _collisionhandlers.equal_range(tag);
	std::vector<std::shared_ptr< const CollisionHandler >> results;
	
	for(auto& it = range.first ; it != range.second ; it++) {
		results.push_back(it->second);
	}
	
	return results;
}

std::vector<std::shared_ptr< CollisionHandler >> CollisionBody::getCollisionHandler(const std::string tag)
{
	auto range = _collisionhandlers.equal_range(tag);
	std::vector<std::shared_ptr< CollisionHandler >> results;
	
	for(auto it = range.first ; it != range.second ; it++) {
		results.push_back(it->second);
	}
	
	return results;
}

const std::multimap< std::string, std::shared_ptr< CollisionHandler > >& CollisionBody::getCollisionHandler() const
{
	return _collisionhandlers;
}

std::multimap< std::string, std::shared_ptr< CollisionHandler > >& CollisionBody::getCollisionHandler()
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
