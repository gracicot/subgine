#include "pulseaccumulator.h"

using namespace std;

namespace sbg {

template<int n>
PulseAccumulator<n>::PulseAccumulator() : _total(), _count(0)
{
	
}

template<>
void PulseAccumulator<2>::operator+=(Vector2d value)
{
	_total.x = abs(_total.x) > abs(value.x) ? _total.x : value.x;
	_total.y = abs(_total.y) > abs(value.y) ? _total.y : value.y;
	_count++;
}

template<>
void PulseAccumulator<3>::operator+=(Vector3d value)
{
	_total.x = abs(_total.x) > abs(value.x) ? _total.x : value.x;
	_total.y = abs(_total.y) > abs(value.y) ? _total.y : value.y;
	_total.z = abs(_total.z) > abs(value.z) ? _total.z : value.z;
	_count++;
}

template<int n>
Vector<n, double> PulseAccumulator<n>::value() const
{
	if (_count > 0) {
		return _total;
	} else {
		return Vector<n, double>();
	}
}

template<int n>
void PulseAccumulator<n>::clear()
{
	_total = Vector<n, double>();
	_count = 0;
}

template<int n>
bool PulseAccumulator<n>::empty() const
{
	return _count == 0;
}

template<int n>
int PulseAccumulator<n>::count() const
{
	return _count;
}

template struct PulseAccumulator<2>;
template struct PulseAccumulator<3>;

}