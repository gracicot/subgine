#pragma once

#include "sat_able.h"

namespace sbg {

class Line : public virtual SAT_able
{
public:
	virtual std::pair<double, double> projection(double angle) const override;
};

}
