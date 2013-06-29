#include "collisionnable.h"

namespace subgine
{
namespace collision
{

Collisionnable::Collisionnable()
{

}

Collisionnable::~Collisionnable()
{

	for (auto handler : _collisionhandlers) {
		delete handler.second;
	}
}

void Collisionnable::addCollisionHandler(CollisionHandler* handler, std::string tag)
{
	if (!(handler == nullptr || handler == 0)) {
		_collisionhandlers[tag] = handler;
	} else {
		throw std::runtime_error("Collision handler is null");
	}
}

void Collisionnable::trigger(Collisionnable& other, Results::CollisionResult* result, std::string tag)
{
	std::map<std::string, CollisionHandler*>::iterator it = _collisionhandlers.find(tag);

	if (it != _collisionhandlers.end()) {
		if (!(it->second == nullptr || it->second == 0)) {
			it->second->apply(*this, other, *result);
		}
	}
}


}
}
