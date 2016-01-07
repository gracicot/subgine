#pragma once

#include "sat_able.h"

namespace sbg {

struct Line : virtual SAT_able {
	virtual std::pair<double, double> projection(double angle) const override;
};

}
