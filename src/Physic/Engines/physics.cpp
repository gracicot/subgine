#include "physics.h"

#include <algorithm>

using namespace std;

namespace sbg {

Physics::Physics()
{

}

Physics::~Physics()
{

}

void Physics::add(weak_ptr<AbstractPhysicPoint> object)
{
	_objects.insert(object);
}

void Physics::remove(weak_ptr<AbstractPhysicPoint> object)
{
	auto it = find_if(_objects.begin(), _objects.end(), [&object](weak_ptr<AbstractPhysicPoint> other){
		return !object.owner_before(other) && !other.owner_before(object);
	});
	
	if (it != _objects.end()) {
		_objects.erase(it);
	}
}

void Physics::execute(const double time)
{
	for (auto ref : _objects) {
		if (!ref.expired()) {
			auto object = ref.lock();
			object->update(time);
		} else {
			remove(ref);
		}
	}
}

}
