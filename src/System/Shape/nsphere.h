#pragma once

namespace sbg {
namespace shape {

template<int n>
struct NSphere {
	explicit NSphere(double radius = 0);
	void setRadius(double radius);
	double getRadius() const;
	
	constexpr static auto dimensions = n;
	
private:
	double _radius;
};

extern template struct NSphere<2>;
extern template struct NSphere<3>;

using Circle = NSphere<2>;
using Sphere = NSphere<3>;

}
}
