#pragma once

#include "physicpointcomponentprovider.h"

#include "../../system.hpp"

namespace sbg {

template<int n>
class PhysicPointDisplayComponentProvider : public PhysicPointComponentProvider<n>, public DisplayComponentProvider<n>
{
public:
	PhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, Vector<freedom(n), double> orientation = Vector<freedom(n), double>(), Vector<n, double> scale = Vector<n, double>());
	PhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, std::function<Vector<freedom(n), double>()> orientation, Vector<n, double> scale = Vector<n, double>());
	PhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, Vector<freedom(n), double> orientation, std::function<Vector<n, double>()> scale);
	PhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, std::function<Vector<freedom(n), double>()> orientation, std::function<Vector<n, double>()> scale);
	
	void setScale(Vector<n, double> scale);
	void setScale(std::function<Vector<n, double>()> scale);
	
	virtual Vector<n, double> getScale() const override;
	PhysicPointDisplayComponentProvider<n>* clone() const override;
	
private:
	std::function<Vector<n, double>()> _scale;
};

extern template class PhysicPointDisplayComponentProvider<2>;
extern template class PhysicPointDisplayComponentProvider<3>;

typedef PhysicPointDisplayComponentProvider<2> PhysicPoint2DDisplayComponentProvider;
typedef PhysicPointDisplayComponentProvider<3> PhysicPoint3DDisplayComponentProvider;

}
