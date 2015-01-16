#pragma once

#include "../system.hpp"

namespace sbg {

class CollisionEntity : public Clonable
{
public:
	CollisionEntity() = default;
	virtual CollisionEntity* clone() const = 0;
	~CollisionEntity() = default;
};

}
