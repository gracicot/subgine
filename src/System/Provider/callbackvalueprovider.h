#pragma once

#include "valueprovider.h"

#include <functional>

namespace sbg {

template<typename T>
struct CallBackValueProvider : ValueProvider<T> {
	CallBackValueProvider(T value = T{}) : _value{[value]{return value;}} {}
	CallBackValueProvider(std::function<T()> value) : _value(value) {}
	
	T getValue() const override {
		return _value();
	}
	
	void setValue(T value) {
		_value = [value]{return value;}; 
	}
	
	void setValue(std::function<T()> value) {
		_value = value;
	}
	
	CallBackValueProvider* clone() const override {
		return new CallBackValueProvider(*this);
	}
	
private:
	std::function<T()> _value;
};

}
