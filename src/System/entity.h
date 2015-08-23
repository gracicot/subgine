#pragma once

#include "./memory.h"
#include "type_id.h"
#include "Provider/provider.h"

#include <exception>
#include <memory>
#include <unordered_map>
#include <map>

namespace sbg {

struct Entity {
private:
	struct AbstractProperty {
		virtual ~AbstractProperty();
	};
	
	template<typename T>
	struct AbstractRProperty : AbstractProperty {
		virtual T get() const = 0;
		virtual std::function<T()> functor() const = 0;
	};
	
	template<typename T>
	struct RProperty : AbstractRProperty<T> {
		using Type = T;
		RProperty(std::function<T()> getter) : _getter{getter} {}
		
		T get() const override {
			return _getter();
		}
		
		std::function<T()> functor() const override {
			return _getter;
		}
		
	private:
		std::function<T()> _getter;
	};
	
	template<typename T>
	struct RWProperty : AbstractRProperty<T> {
		using Type = T;
		RWProperty() : _value{} {}
		
		RWProperty(T&& value) : _value{std::move(value)} {}
		RWProperty(const T& value) : _value{value} {}
		
		RWProperty(Provider<T>&& value) : _value{std::move(value)} {}
		RWProperty(const Provider<T>& value) : _value{value} {}
		
		template<typename Arg>
		void set(Arg&& arg) {
			_value = std::forward<Arg>(arg);
		}
		
		T get() const override {
			return _value();
		}
		
		std::function<T()> functor() const override {
			return _value.function();
		}
		
	private:
		Provider<T> _value;
	};

public:
	Entity() = default;
	Entity(const Entity&) = delete;
	Entity& operator=(const Entity&) = delete;
	Entity(Entity&& o);
	Entity& operator=(Entity&& o);
	
	template<typename T>
	void assign(std::shared_ptr<T> component) {
		if(component) _components[type_id<T>] = std::move(component);
	}
	
	template<typename T, typename... Args>
	typename std::enable_if<std::is_constructible<T, Args...>::value, void>::type assign(Args&&... args) {
		_components[type_id<T>] = std::make_shared<T>(std::forward<Args>(args)...);
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
	
	template<typename T>
	void property(std::string name, T&& value) {
		_properties[name] = std::make_unique<RWProperty<T>>(std::forward<T>(value));
	}
	
	template<typename T>
	void property(std::string name) {
		_properties[name] = std::make_unique<RWProperty<T>>();
	}

	template<typename T>
	void accessor(std::string name, T getter) {
		_properties[name] = std::make_unique<RProperty<decltype(getter())>>(getter);
	}

	template<typename T, typename U>
	void accessor(std::string name, U getter) {
		_properties[name] = std::make_unique<RProperty<T>>(getter);
	}

	bool contains(std::string name) {
		return _properties.find(name) != _properties.end();
	}
	
	template<typename T>
	T get(std::string name) const {
		auto it = _properties.find(name);
		
		if (it != _properties.end()) {
			if (auto property = dynamic_cast<AbstractRProperty<T>*>(it->second.get())) {
				return property->get();
			} else {
				throw std::runtime_error{std::string{"The property with the name "} + name + "has the wrong type"};
			}
		}
		
		throw std::runtime_error{std::string{"The property with the name "} + name + "has not been found"};
	}
	
	template<typename T>
	std::function<T()> provider(std::string name) const {
		auto it = _properties.find(name);
		
		if (it != _properties.end()) {
			if (auto property = dynamic_cast<AbstractRProperty<T>*>(it->second.get())) {
				return property->functor();
			} else {
				throw std::runtime_error{std::string{"The property with the name "} + name + "has the wrong type"};
			}
		}
		
		throw std::runtime_error{std::string{"The property with the name "} + name + "has not been found"};
	}
	
	template<typename T, typename Arg>
	void set(std::string name, Arg&& arg) {
		auto it = _properties.find(name);
		
		if (it != _properties.end()) {
			if (auto property = dynamic_cast<RWProperty<T>*>(it->second.get())) {
				return property->set(std::forward<Arg>(arg));
			} else {
				throw std::runtime_error{std::string{"The property with the name "} + name + "has the wrong type or the wrong access type"};
			}
		}
		
		throw std::runtime_error{std::string{"The property with the name "} + name + "has not been found"};
	}
	
private:
	std::unordered_map<std::string, std::unique_ptr<AbstractProperty>> _properties;
	std::unordered_map<type_id_t, std::shared_ptr<void>> _components;
};

}
