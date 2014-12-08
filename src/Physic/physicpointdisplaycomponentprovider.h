#pragma once

#include "physicpointcomponentprovider.h"

#include "../system.hpp"

namespace subgine {
namespace physic {

template<int n>
class PhysicPointDisplayComponentProvider : public PhysicPointComponentProvider<n>, public DisplayComponentProvider<n>
{
public:
	PhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, Vector<freedom(n), double> orientation = Vector<freedom(n), double>(), double scale = 0);
	PhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, std::function<Vector<freedom(n), double>()> orientation, double scale = 0);
	PhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, Vector<freedom(n), double> orientation, std::function<double()> scale);
	PhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, std::function<Vector<freedom(n), double>()> orientation, std::function<double()> scale);
	
	void setScale(double scale);
	void setScale(std::function<double()> scale);
	
	virtual double getScale() const override;
	
private:
	std::function<double()> _scale;
};

extern template class PhysicPointDisplayComponentProvider<2>;
extern template class PhysicPointDisplayComponentProvider<3>;

typedef PhysicPointDisplayComponentProvider<2> PhysicPoint2DDisplayComponentProvider;
typedef PhysicPointDisplayComponentProvider<3> PhysicPoint3DDisplayComponentProvider;

}
}
