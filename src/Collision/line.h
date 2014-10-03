#pragma once

#include "sat_able.h"

namespace subgine
{
namespace collision
{

class Line : public virtual SAT_able
{
public:
	Line() = default;
	virtual ~Line();

	virtual Vector2d projection(double angle);
};

}
}
