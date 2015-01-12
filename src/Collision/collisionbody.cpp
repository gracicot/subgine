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
	_material(other._material),
	_collisionhandlers(other._collisionhandlers),
	_collisionEntities(other._collisionEntities)
{
	for (auto& tester : other._collisionTesters) {
		_collisionTesters.insert(make_pair(tester.first, unique_ptr<CollisionTester>(tester.second->clone())));
	}
}

CollisionBody::CollisionBody()
{

}

CollisionBody::~CollisionBody()
{
	
}

CollisionResult CollisionBody::testObject(shared_ptr<const CollisionBody> other, double time, string test) const
{
	auto it = _collisionTesters.find(test);
	
	if (it != _collisionTesters.end()) {
		auto data = it->second->test(getCollisionEntity(test), other->getCollisionEntity(test));
		return CollisionResult(other, data.second, move(data.first), time);
	}
	
	return CollisionResult(other, false, nullptr, time);
}

void CollisionBody::trigger(CollisionResult result, string test)
{
	auto range = _collisionhandlers.equal_range(test);
	
	for(auto it = range.first ; it != range.second ; it++) {
		it->second->apply(*this, result);
	}
}

shared_ptr<CollisionEntity> CollisionBody::getCollisionEntity(string tag)
{
	auto it = _collisionEntities.find(tag);
	
	if (it != _collisionEntities.end()) {
		return it->second;
	}
	
	throw out_of_range("CollisionEntity with tag \"" + tag + "\" not found...");
}

const shared_ptr<const CollisionEntity> CollisionBody::getCollisionEntity(string tag) const
{
	auto it = _collisionEntities.find(tag);
	
	if (it != _collisionEntities.end()) {
		return it->second;
	}
	
	throw out_of_range("CollisionEntity with tag \"" + tag + "\" not found...");
}

const map< string, shared_ptr< CollisionEntity > >& CollisionBody::getCollisionEntity() const
{
	return _collisionEntities;
}

map< string, shared_ptr< CollisionEntity > >& CollisionBody::getCollisionEntity()
{
	return _collisionEntities;
}

vector<shared_ptr< const CollisionHandler >> CollisionBody::getCollisionHandler(const string tag) const
{
	auto range = _collisionhandlers.equal_range(tag);
	vector<shared_ptr< const CollisionHandler >> results;
	
	for(auto& it = range.first ; it != range.second ; it++) {
		results.push_back(it->second);
	}
	
	return results;
}

vector<shared_ptr< CollisionHandler >> CollisionBody::getCollisionHandler(const string tag)
{
	auto range = _collisionhandlers.equal_range(tag);
	vector<shared_ptr< CollisionHandler >> results;
	
	for(auto it = range.first ; it != range.second ; it++) {
		results.push_back(it->second);
	}
	
	return results;
}

const multimap< string, shared_ptr< CollisionHandler > >& CollisionBody::getCollisionHandler() const
{
	return _collisionhandlers;
}

multimap< string, shared_ptr< CollisionHandler > >& CollisionBody::getCollisionHandler()
{
	return _collisionhandlers;
}

const map< string, unique_ptr< CollisionTester > >& CollisionBody::getCollisionTester() const
{
	return _collisionTesters;
}

map< string, unique_ptr< CollisionTester > >& CollisionBody::getCollisionTester()
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
