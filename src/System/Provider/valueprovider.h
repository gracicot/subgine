#pragma once

#include <functional>

namespace sbg {

template<typename T>
struct ValueProvider final {
	ValueProvider(std::function<T()> callback) : _callback{callback} {}
	ValueProvider(T value) : _callback{[=](){ return value; }} {}
	
	T operator()() const {
		return _callback();
	}
	
private:
	std::function<T()> _callback;
};

}
