#pragma once

#include "../../system.hpp"

namespace sbg {

class ResultData : public Clonable
{
public:
	virtual std::unique_ptr<ResultData> reverse() const = 0;
	virtual ResultData* clone() const = 0;
};

}
