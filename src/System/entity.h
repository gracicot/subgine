#pragma once

#include "./memory.h"
#include "type_id.h"

#include <exception>
#include <memory>
#include <unordered_map>

namespace sbg {

struct Entity {
	template<typename T>
	void assign(std::shared_ptr<T> component) {
		if(component) _components[type_id<T>] = std::move(component);
	}
	
	template<typename T>
	const T& component() const {
		auto it = _components.find(type_id<T>);
		
		if (it != _components.end()) {
			return *(std::static_pointer_cast<T>(it->second));
		}
		
		throw std::runtime_error{"No component with the specified type was found"};
	}
	
	template<typename T>
	T& component() {
		auto it = _components.find(type_id<T>);
		
		if (it != _components.end()) {
			return *(std::static_pointer_cast<T>(it->second));
		}
		
		throw std::runtime_error{"No component with the specified type was found"};
	}
	
	template<typename T>
	bool has() const {
		return _components.find(type_id<T>) != _components.end();
	}
	
private:
	std::unordered_map<type_id_t, std::shared_ptr<void>> _components;
};

}
