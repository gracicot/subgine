#pragma once

#include <functional>
#include <type_traits>

namespace sbg {

template<typename T>
struct Provider final {
	Provider() = delete;
	~Provider() = default;
	Provider(const Provider& other) : _function{other._function} {}
	Provider(Provider&& other) : _function{std::move(other._function)} {}
	
	Provider& operator=(Provider&& other) {
		std::swap(other._function, _function);
		return *this;
	}
	
	Provider& operator=(const Provider& other) {
		_function = other._function;
		return *this;
	}
	
	template<typename U, typename = typename std::enable_if<std::is_convertible<U, T>::value>::type, typename = typename std::enable_if<!std::is_same<U, T>::value>::type>
	Provider<T>& operator=(Provider<U>&& other) {
		std::swap(other._function, _function);
		return *this;
	}
	
	template<typename U, typename = typename std::enable_if<std::is_convertible<U, T>::value>::type, typename = typename std::enable_if<!std::is_same<U, T>::value>::type>
	Provider<T>& operator=(const Provider<U>& other) {
		_function = other._function;
		return *this;
	}
	
	template<typename U, typename = typename std::enable_if<std::is_convertible<U, T>::value>::type, typename = typename std::enable_if<!std::is_same<U, T>::value>::type>
	Provider(const Provider<U>& other) : _function{other._function} {}
	
	template<typename U, typename = typename std::enable_if<std::is_convertible<U, T>::value>::type, typename = typename std::enable_if<!std::is_same<U, T>::value>::type>
	Provider(Provider<U>&& other) : _function{std::move(other._function)} {}

	template<typename U,
		typename = typename std::enable_if<!std::is_convertible<U, T>::value>::type,
		typename = typename std::enable_if<!std::is_same<U, T>::value>::type
	>
	Provider(U function) : _function{function} {}

	Provider(T value) : _function{[=]{ return value; }} {}
	
	template<typename U>
	friend struct Provider;
	
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
