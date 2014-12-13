#pragma once

#include "sat_able.h"

namespace sbg {

class Line : public virtual SAT_able
{
public:
	Line() = default;
	virtual ~Line();

	virtual Vector2d projection(double angle);
};

}
