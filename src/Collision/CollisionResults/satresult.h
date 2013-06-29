#pragma once

#include "../../system.hpp"

#include "collisionresult.h"
#include "../collisionnable.h"

namespace subgine
{
namespace collision
{
namespace Results
{

struct SatResult : public CollisionResult {
public:
	SatResult(const bool colliding, const double time, const Vector2 gap);
	~SatResult() = default;

	void setGap(const Vector2 gap);
	Vector2 getGap() const;

private:
	Vector2 _gap;
};

}
}
}
