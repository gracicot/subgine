#pragma once

#include "accumulator.h"

namespace sbg {

template<typename T>
struct SumAccumulator : Accumulator<T> {
	SumAccumulator() : _total(), _count(0)
	{
		
	}
	
	void operator+=(T value) override
	{
		_total += value;
		_count++;
	}
	
	T value() const override
	{
		return _total;
	}
	
	void clear() override
	{
		_total = T();
		_count = 0;
	}
	
	bool empty() const override
	{
		return _count == 0;
	}
	
	int count() const override
	{
		return _count;
	}
	
private:
	T _total;
	int _count;
	
};

}
