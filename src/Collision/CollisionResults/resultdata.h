#pragma once

#include "../../system.hpp"

namespace sbg {

struct ResultData : Clonable {
	virtual std::unique_ptr<ResultData> reverse() const = 0;
	virtual ResultData* clone() const = 0;
};

}
