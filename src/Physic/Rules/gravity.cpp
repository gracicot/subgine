#include "gravity.h"

using namespace std;

namespace sbg {

template<int n>
Gravity<n>::Gravity(const Vector<n, double> value) : _value(value)
{
	
}

template<int n>
Vector<n, double> Gravity<n>::getResult(const PhysicPoint<n>& object) const
{
	return _value * object.getMass();
}

template<int n>
Vector<n, double> Gravity<n>::getValue() const
{
	return _value;
}

template<int n>
Gravity<n>* Gravity<n>::clone() const
{
	return new Gravity<n>(*this);
}

template<int n>
void Gravity<n>::setValue(const Vector<n, double> value)
{
	_value = value;
}

template struct Gravity<2>;
template struct Gravity<3>;

}