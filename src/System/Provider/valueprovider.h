#pragma once

#include <functional>
#include <type_traits>

namespace sbg {

template<typename T>
struct ValueProvider final {
	ValueProvider() = delete;
	~ValueProvider() = default;
	ValueProvider(const ValueProvider& other) : _function{other._function} {}
	ValueProvider(ValueProvider&& other) : _function{std::move(other._function)} {}
	
	ValueProvider& operator=(ValueProvider&& other) {
		std::swap(other._function, _function);
		return *this;
	}
	
	ValueProvider& operator=(const ValueProvider& other) {
		_function = other._function;
		return *this;
	}
	
	template<typename U, typename = typename std::enable_if<std::is_convertible<U, T>::value>::type, typename = typename std::enable_if<!std::is_same<U, T>::value>::type>
	ValueProvider<T>& operator=(ValueProvider<U>&& other) {
		std::swap(other._function, _function);
		return *this;
	}
	
	template<typename U, typename = typename std::enable_if<std::is_convertible<U, T>::value>::type, typename = typename std::enable_if<!std::is_same<U, T>::value>::type>
	ValueProvider<T>& operator=(const ValueProvider<U>& other) {
		_function = other._function;
		return *this;
	}
	
	template<typename U, typename = typename std::enable_if<std::is_convertible<U, T>::value>::type, typename = typename std::enable_if<!std::is_same<U, T>::value>::type>
	ValueProvider(const ValueProvider<U>& other) : _function{other._function} {}
	
	template<typename U, typename = typename std::enable_if<std::is_convertible<U, T>::value>::type, typename = typename std::enable_if<!std::is_same<U, T>::value>::type>
	ValueProvider(ValueProvider<U>&& other) : _function{std::move(other._function)} {}
	
	template<typename U, typename = typename std::enable_if<std::is_constructible<std::function<T()>, U>::value>::type>
	ValueProvider(U callback) : _function{callback} {}
	ValueProvider(typename std::enable_if<!std::is_constructible<std::function<T()>, T>::value, T>::type value) : _function{[=]{ return value; }} {}
	
	template<typename U>
	friend struct ValueProvider;
	
	std::function<T()> function() const {
		return _function;
	}
	
	T operator()() const {
		return _function();
	}
	
private:
	std::function<T()> _function;
};

}
