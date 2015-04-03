#pragma once

namespace sbg {

class Clonable
{
public:
	virtual Clonable* clone() const = 0;
};

}
