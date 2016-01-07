#pragma once

#include <memory>
#include <type_traits>
#include "../system.hpp"

namespace sbg {

template<class T>
typename std::enable_if<std::is_base_of<Clonable, T>::value, std::unique_ptr<T>>::type clone_unique(const T& arg) {
	return std::unique_ptr<T>(arg->clone());
}

template<class T>
typename std::enable_if<std::is_base_of<Clonable, T>::value, std::unique_ptr<T>>::type clone_unique(std::shared_ptr<T> arg) {
	if (arg) {
		return std::unique_ptr<T>(arg->clone());
	} else {
		return nullptr;
	}
}

template<class T>
constexpr typename std::enable_if<std::is_base_of<Clonable, T>::value, std::unique_ptr<T>>::type clone_unique(const std::unique_ptr<T>& arg) {
	return arg ? std::unique_ptr<T>(arg->clone()) : nullptr;
}

template<class T>
typename std::enable_if<std::is_base_of<Clonable, T>::value, std::shared_ptr<T>>::type clone_shared(const T& arg) {
	return std::shared_ptr<T>(arg->clone());
}

template<class T>
typename std::enable_if<std::is_base_of<Clonable, T>::value, std::shared_ptr<T>>::type clone_shared(std::shared_ptr<T> arg) {
	if (arg) {
		return std::shared_ptr<T>(arg->clone());
	} else {
		return nullptr;
	}
}

template<class T>
typename std::enable_if<std::is_base_of<Clonable, T>::value, std::shared_ptr<T>>::type clone_shared(const std::unique_ptr<T>& arg) {
	if (arg) {
		return std::shared_ptr<T>(arg->clone());
	} else {
		return nullptr;
	}
}

}