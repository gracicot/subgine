#pragma once

#include <set>
#include <memory>
#include "collisionentity.h"

namespace sbg {

template<typename T>
struct CompoundCollision : CollisionEntity {
	CompoundCollision(){};
	CompoundCollision(std::set<std::shared_ptr<T>> entities) : _entities(entities)
	{
		
	}
	
	void add(std::shared_ptr<T> entity)
	{
		_entities.insert(entity);
	}
	
	void remove(std::shared_ptr<T> entity)
	{
		_entities.erase(entity);
	}
	
	const std::set<std::shared_ptr<T>>& get() const
	{
		return _entities;
	}

private:
	std::set<std::shared_ptr<T>> _entities;
};

}
