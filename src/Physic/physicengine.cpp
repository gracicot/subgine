#include "physicengine.h"

#include <algorithm>
#include <iostream>
#include "abstractphysicpoint.h"

using namespace std;

namespace sbg {

void PhysicEngine::add(shared_ptr<Entity> object)
{
	if (object->has<AbstractPhysicPoint>()) {
		_objects.insert(move(object));
	}
}

void PhysicEngine::remove(weak_ptr<Entity> object)
{
	auto it = find_if(_objects.begin(), _objects.end(), [&object](const weak_ptr<Entity>& other){
		return !object.owner_before(other) && !other.owner_before(object);
	});
	
	if (it != _objects.end()) {
		_objects.erase(it);
	}
}

void PhysicEngine::execute(Time time)
{
	for (auto ref : _objects) {
		if (!ref.expired()) {
			auto object = ref.lock();
			object->component<AbstractPhysicPoint>().update(time);
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
