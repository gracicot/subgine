#pragma once

#include <set>

#include "../system.hpp"

namespace sbg {

class PhysicEngine : public Engine
{
public:
	void add(std::shared_ptr<Entity> entity);
	void remove(std::weak_ptr<Entity> entity);

	void execute(Time time) override;

private:
	std::set<std::weak_ptr<Entity>, std::owner_less<std::weak_ptr<Entity>>> _objects;
};

}
