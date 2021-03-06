#include "collisionresult.h"

#include "../collisionbody.h"
#include "resultdata.h"

using namespace std;

namespace sbg {

CollisionResult::CollisionResult(weak_ptr<const Entity> other, const bool colliding, unique_ptr<const ResultData> data, Time time) : _data{move(data)}, _other{other}, _colliding{colliding}, _time{time}
{

}

CollisionResult::CollisionResult(const CollisionResult& other):
	_data{clone_unique(other._data)},
	_other{other._other},
	_colliding{other._colliding},
	_time{other._time}
{
	
}

void CollisionResult::colliding(const bool colliding)
{
	_colliding = colliding;
}

Time CollisionResult::getTime() const
{
	return _time;
}

bool CollisionResult::isColliding() const
{
	return _colliding;
}

void CollisionResult::setTime(Time time)
{
	_time = time;
}

shared_ptr<const Entity> CollisionResult::getOther() const
{
	if (!_other.expired()) {
		return _other.lock();
	} else {
		return {};
	}
}

void CollisionResult::setOther(weak_ptr<const Entity> other)
{
	_other = other;
}

const ResultData* CollisionResult::getData() const
{
	return _data.get();
}

void CollisionResult::setData(unique_ptr<const ResultData> data)
{
	_data = move(data);
}

}
