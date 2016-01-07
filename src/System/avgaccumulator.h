#pragma once

#include "accumulator.h"

namespace sbg {

template<typename T>
struct AvgAccumulator : Accumulator<T> {
	AvgAccumulator() : _total(), _count(0)
	{
		
	}
	
	void operator+=(T value) override
	{
		_total += value;
		_count++;
	}
	
	T value() const override
	{
		if (_count > 0) {
			return _total / _count;
		} else {
			return T();
		}
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
