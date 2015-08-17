#pragma once

#include "sat_able.h"

namespace sbg {

class Line : public virtual SAT_able
{
public:
	virtual Vector2d projection(double angle);
};

}
