#pragma once

#include "time.h"

namespace sbg {

struct Engine {
	virtual void execute(Time time) = 0;
};

}

