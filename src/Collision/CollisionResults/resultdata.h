#pragma once

#include "../../system.hpp"

namespace sbg {

struct ResultData : Clonable {
	virtual std::unique_ptr<ResultData> reverse() const = 0;
	ResultData* clone() const override = 0;
};

}
