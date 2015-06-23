#pragma once

namespace sbg {
namespace shape {

template<int n>
class NSphere
{
public:
	explicit NSphere(double radius = 0);
	void setRadius(double radius);
	double getRadius() const;
	
	constexpr static auto dimensions = n;
	
private:
	double _radius;
};

using Circle = NSphere<2>;
using Sphere = NSphere<3>;

extern template class NSphere<2>;
extern template class NSphere<3>;

}
}
