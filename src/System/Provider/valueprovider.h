#pragma once

#include <functional>
#include <type_traits>

namespace sbg {

template<typename T>
struct ValueProvider final {
	ValueProvider() = delete;
	ValueProvider(const ValueProvider& other) : _callback{other._callback} {}
	ValueProvider(ValueProvider&& other) : _callback{std::move(other._callback)} {}
	
	ValueProvider& operator=(ValueProvider&& other) {
		std::swap(other._callback, _callback);
	}
	
	ValueProvider& operator=(const ValueProvider& other) {
		_callback = other._callback;
	}
	
	template<typename U, typename = typename std::enable_if<std::is_constructible<std::function<T()>, U>::value>::type>
	ValueProvider(U callback) : _callback{callback} {}
	ValueProvider(typename std::enable_if<!std::is_constructible<std::function<T()>, T>::value, T>::type value) : _callback{[=]{ return value; }} {}
	
	T operator()() const {
		return _callback();
	}
	
private:
	std::function<T()> _callback;
};

}
