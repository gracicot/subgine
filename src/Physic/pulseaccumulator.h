#pragma once

#include "../system.hpp"

namespace sbg {

template<int n>
struct PulseAccumulator : Accumulator<Vector<n, double>> {
	PulseAccumulator();
	
	void operator+=(Vector<n, double> value) override;
	Vector<n, double> value() const override;
	
	void clear() override;
	bool empty() const override;
	int count() const override;
	
private:
	Vector<n, double> _total;
	int _count;
};

template <> void PulseAccumulator<2>::operator+=(Vector2d value);
template <> void PulseAccumulator<3>::operator+=(Vector3d value);

extern template struct PulseAccumulator<2>;
extern template struct PulseAccumulator<3>;

typedef PulseAccumulator<2> PulseAccumulator2D;
typedef PulseAccumulator<3> PulseAccumulator3D;

}
