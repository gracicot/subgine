#pragma once

#include <functional>
#include <type_traits>

namespace sbg {

template<typename T>
struct Provider final {
	Provider() = delete;
	Provider(const Provider& other) : _callback{other._callback} {}
	Provider(Provider&& other) : _callback{std::move(other._callback)} {}
	
	Provider& operator=(Provider&& other) {
		std::swap(other._callback, _callback);
		return *this;
	}
	
	Provider& operator=(const Provider& other) {
		_callback = other._callback;
		return *this;
	}
	
	template<typename U, typename = typename std::enable_if<std::is_convertible<U, T>::value>::type, typename = typename std::enable_if<!std::is_same<U, T>::value>::type>
	Provider<T>& operator=(Provider<U>&& other) {
		std::swap(other._callback, _callback);
		return *this;
	}
	
	template<typename U, typename = typename std::enable_if<std::is_convertible<U, T>::value>::type, typename = typename std::enable_if<!std::is_same<U, T>::value>::type>
	Provider<T>& operator=(const Provider<U>& other) {
		_callback = other._callback;
		return *this;
	}
	
	template<typename U, typename = typename std::enable_if<std::is_convertible<U, T>::value>::type, typename = typename std::enable_if<!std::is_same<U, T>::value>::type>
	Provider(const Provider<U>& other) : _callback{other._callback} {}
	
	template<typename U, typename = typename std::enable_if<std::is_convertible<U, T>::value>::type, typename = typename std::enable_if<!std::is_same<U, T>::value>::type>
	Provider(Provider<U>&& other) : _callback{std::move(other._callback)} {}
	
	template<typename U, typename = typename std::enable_if<std::is_constructible<std::function<T()>, U>::value>::type>
	Provider(U callback) : _callback{callback} {}
	Provider(typename std::enable_if<!std::is_constructible<std::function<T()>, T>::value, T>::type value) : _callback{[=]{ return value; }} {}
	
	template<typename U>
	friend struct Provider;
	
	T operator()() const {
		return _callback();
	}
	
private:
	std::function<T()> _callback;
};

}
