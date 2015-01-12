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
	return std::unique_ptr<T>(arg->clone());
}

template<class T>
typename std::enable_if<std::is_base_of<Clonable, T>::value, std::unique_ptr<T>>::type clone_unique(const std::unique_ptr<T>& arg) {
	return std::unique_ptr<T>(arg->clone());
}

template<class T>
typename std::enable_if<std::is_base_of<Clonable, T>::value, std::shared_ptr<T>>::type clone_shared(const T& arg) {
	return std::shared_ptr<T>(arg->clone());
}

template<class T>
typename std::enable_if<std::is_base_of<Clonable, T>::value, std::shared_ptr<T>>::type clone_shared(std::shared_ptr<T> arg) {
	return std::shared_ptr<T>(arg->clone());
}

template<class T>
typename std::enable_if<std::is_base_of<Clonable, T>::value, std::shared_ptr<T>>::type clone_shared(const std::unique_ptr<T>& arg) {
	return std::shared_ptr<T>(arg->clone());
}

}