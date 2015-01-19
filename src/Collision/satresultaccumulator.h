#pragma once

#include "../system.hpp"

namespace sbg {

class SatResult;

template<>
class Accumulator<SatResult>
{
public:
	Accumulator();
	void take(SatResult value);
	SatResult flush();
	
private:
	Vector2d _total;
	std::vector<Vector2d> _contacts;
	int _count;
};

}
