#pragma once

namespace sbg {

template<typename T>
class Accumulator
{
public:
	void take(T value) = 0;
	T flush() = 0;
};

}
