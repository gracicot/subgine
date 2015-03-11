#include "spring.h"

using namespace std;

namespace sbg {

template<int n>
Spring<n>::Spring() : _strength(0), _length(0), _provider(make_unique<ZeroPositionProvider<n>>())
{
	
}

template<int n>
Spring<n>::Spring(const double strength, const double length, std::unique_ptr<PositionProvider<n>> provider) : _strength(strength), _length(length), _provider(move(provider))
{
	
}

template<int n>
Spring<n>::Spring(const double strength, const double length) : _strength(strength), _length(length), _provider(make_unique<ZeroPositionProvider<n>>())
{
	
}

template<int n>
Spring<n>::Spring(const Spring& other) : _strength(other._strength), _length(other._length), _provider(clone_unique(other._provider))
{
	
}

template<int n>
Vector<n, double> Spring<n>::getPosition() const
{
	return _provider ? _provider->getPosition():Vector<n, double>{};
}

template<int n>
void Spring<n>::setPositionProvider(std::unique_ptr<PositionProvider<n>> provider)
{
	_provider = move(provider);
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
	return relative.unit() * getStrength() * (relative.getLength() - getLength());
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

template class Spring<2>;
template class Spring<3>;

}