#pragma once

#include <functional>
#include <type_traits>

namespace sbg {

template<typename T>
struct Provider final {
	Provider() = delete;
	~Provider() = default;
	Provider(const Provider& other) = default;
	Provider(Provider&& other) = default;
	Provider& operator=(Provider&& other) = default;
	Provider& operator=(const Provider& other) = default;
	
	template<typename U, typename std::enable_if<std::is_convertible<U, T>::value, int>::type = 0, typename std::enable_if<!std::is_same<U, T>::value, int>::type = 0>
	Provider<T>& operator=(Provider<U>&& other) {
		std::swap(other._function, _function);
		return *this;
	}
	
	template<typename U, typename std::enable_if<std::is_convertible<U, T>::value, int>::type = 0, typename std::enable_if<!std::is_same<U, T>::value, int>::type = 0>
	Provider<T>& operator=(const Provider<U>& other) {
		_function = other._function;
		return *this;
	}
	
	template<typename U, typename std::enable_if<std::is_convertible<U, T>::value, int>::type = 0, typename std::enable_if<!std::is_same<U, T>::value, int>::type = 0>
	Provider(const Provider<U>& other) : _function{other._function} {}
	
	template<typename U, typename std::enable_if<std::is_convertible<U, T>::value, int>::type = 0, typename std::enable_if<!std::is_same<U, T>::value, int>::type = 0>
	Provider(Provider<U>&& other) : _function{std::move(other._function)} {}

	template<typename U, typename std::enable_if<!std::is_constructible<T, U>::value && !std::is_convertible<U, T>::value && !std::is_same<U, T>::value, int>::type = 0>
	Provider(U function) : _function{function} {}
	
	template<typename U, typename std::enable_if<std::is_constructible<T, U>::value || std::is_convertible<U, T>::value || std::is_same<U, T>::value, int>::type = 0>
	Provider(U value) : _function{[=]{ return value; }} {}
	
	template<typename U>
	friend struct Provider;
	
	T operator()() const {
		return _function();
	}
	
private:
	std::function<T()> _function;
};

}
