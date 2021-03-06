#include "spring.h"

using namespace std;

namespace sbg {

template<int n>
Spring<n>::Spring() : _strength{0}, _length{0}, _provider{makeZeroPositionProvider<n>()}
{
	
}

template<int n>
Spring<n>::Spring(const double strength, const double length, PositionProvider<n> provider) : _strength{strength}, _length{length}, _provider{provider}
{
	
}

template<int n>
Spring<n>::Spring(const double strength, const double length) : _strength{strength}, _length{length}, _provider{makeZeroPositionProvider<n>()}
{
	
}

template<int n>
Vector<n, double> Spring<n>::getPosition() const
{
	return _provider.getPosition();
}

template<int n>
void Spring<n>::setPositionProvider(PositionProvider<n> provider)
{
	_provider = provider;
}

template<int n>
double Spring<n>::getLength() const
{
	return _length;
}

template<int n>
void Spring<n>::setLength(const double size)
{
	_length = size;
}

template<int n>
Vector<n, double> Spring<n>::getResult(const PhysicPoint<n>& object) const
{
	auto relative = getPosition() - object.getPosition();
	return relative.unit() * getStrength() * (relative.length() - getLength());
}

template<int n>
double Spring<n>::getStrength() const
{
	return _strength;
}

template<int n>
void Spring<n>::setStrength(const double strength)
{
	_strength = strength;
}

template<int n>
Spring<n>* Spring<n>::clone() const
{
	return new Spring<n>(*this);
}

template struct Spring<2>;
template struct Spring<3>;

}