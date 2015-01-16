#include "physicengine.h"

#include <algorithm>
#include <iostream>

using namespace std;

namespace sbg {

void PhysicEngine::add(weak_ptr<AbstractPhysicPoint> object)
{
	_objects.insert(object);
}

void PhysicEngine::remove(weak_ptr<AbstractPhysicPoint> object)
{
	auto it = find_if(_objects.begin(), _objects.end(), [&object](weak_ptr<AbstractPhysicPoint> other){
		return !object.owner_before(other) && !other.owner_before(object);
	});
	
	if (it != _objects.end()) {
		_objects.erase(it);
	}
}

void PhysicEngine::execute(const double time)
{
	for (auto ref : _objects) {
		if (!ref.expired()) {
			auto object = ref.lock();
			object->update(time);
		} else {
			remove(ref);
		}
	}
// 	auto objects = _objects;
// 	
// 	multitask(objects.begin(), objects.end(), [time, this] (typename decltype(_objects)::value_type ref) {
// 		if (!ref.expired()) {
// 			auto object = ref.lock();
// 			object->update(time);
// 		} else {
// 			remove(ref);
// 		}
// 	});
}

}
