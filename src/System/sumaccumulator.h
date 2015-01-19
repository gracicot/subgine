#pragma once

#include "accumulator.h"

namespace sbg {

template<typename T>
class SumAccumulator : public Accumulator<T>
{
public:
	void take(T value)
	{
		_total += value;
	}
	
	T flush()
	{
		T result = _total;
		_total = T();
		return result;
	}
	
private:
	T _total;
	
};

}
