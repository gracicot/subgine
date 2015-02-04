#pragma once

#include "../../system.hpp"

namespace sbg {

class ResultData : public Clonable
{
public:
	virtual ResultData* clone() const = 0;
};

}
