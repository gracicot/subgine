#pragma once

#include <functional>
#include <type_traits>

namespace sbg {

template<typename T>
struct ValueProvider final {
	template<typename U, typename = typename std::enable_if<std::is_constructible<std::function<T()>, U>::value>::type>
	ValueProvider(U&& callback) : _callback{std::forward<U>(callback)} {}
	ValueProvider(typename std::enable_if<!std::is_constructible<std::function<T()>, T>::value, T>::type value) : _callback{[=]{ return value; }} {}
	
	T operator()() const {
		return _callback();
	}
	
private:
	std::function<T()> _callback;
};

}
