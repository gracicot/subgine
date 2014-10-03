#pragma once

#include "../../system.hpp"

#include "collisionresult.h"

#include <vector>

namespace subgine {
namespace collision {
namespace Results {

class SatResult : public CollisionResult
{
public:
	SatResult(const CollisionBody& other, const bool colliding, const double time, const Vector2d gap);
	~SatResult() = default;

	void setGap(const Vector2d gap);
	Vector2d getGap() const;
	
	void setContacts(std::vector<Vector2d> contacts);
	std::vector<Vector2d> getContacts() const;

private:
	Vector2d _gap;
	std::vector<Vector2d> _contacts;
};

}
}
}
