#pragma once

#include "sat_able.h"

namespace Collisionnable
{

class Line : public virtual SAT_able
{
public:
	Line() = default;
	virtual ~Line();

	virtual Vector2 projection(double angle);
};

}
