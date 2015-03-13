#include "resistance.h"

using namespace std;

namespace sbg {

template<int n>
Resistance<n>::Resistance(const double value) : _value(value)
{
	
}

template<int n>
Vector<n, double> Resistance<n>::getResult(const PhysicPoint<n>& object) const
{
	return -1 * object.getVelocity() * getValue();
}

template<int n>
double Resistance<n>::getValue() const
{
	return _value;
}

template<int n>
void Resistance<n>::setValue(const double value)
{
	_value = value;
}

template<int n>
Resistance<n>* Resistance<n>::clone() const
{
	return new Resistance<n>(*this);
}

template class Resistance<2>;
template class Resistance<3>;

}