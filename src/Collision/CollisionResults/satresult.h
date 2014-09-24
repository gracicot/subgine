#pragma once

#include "../../system.hpp"

#include "collisionresult.h"
#include "../collisionbody.h"

#include <vector>

namespace subgine
{
namespace collision
{
namespace Results
{

struct SatResult : public CollisionResult {
public:
	SatResult(const CollisionBody& other, const bool colliding, const double time, const Vector2 gap);
	~SatResult() = default;

	void setGap(const Vector2 gap);
	Vector2 getGap() const;
	
	void setContacts(std::vector<Vector2d> contacts);
	std::vector<Vector2d> getContacts() const;

private:
	Vector2 _gap;
	std::vector<Vector2d> _contacts;
};

}
}
}
