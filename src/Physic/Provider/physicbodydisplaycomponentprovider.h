#pragma once

#include "physicbodycomponentprovider.h"

#include "../../system.hpp"

namespace sbg {

template<int n>
class PhysicBodyDisplayComponentProvider : public virtual PhysicBodyComponentProvider<n>, public virtual DisplayComponentProvider<n>
{
public:
	PhysicBodyDisplayComponentProvider(const PhysicBody<n>& physicBody, double scale = 0);
	PhysicBodyDisplayComponentProvider(const PhysicBody<n>& physicBody, std::function<double()> scale);
	
	void setScale(double scale);
	void setScale(std::function<double()> scale);
	
	virtual double getScale() const override;
private:
	std::function<double()> _scale;
};

extern template class PhysicBodyDisplayComponentProvider<2>;
extern template class PhysicBodyDisplayComponentProvider<3>;

typedef PhysicBodyDisplayComponentProvider<2> PhysicBody2DDisplayComponentProvider;
typedef PhysicBodyDisplayComponentProvider<3> PhysicBody3DDisplayComponentProvider;

}
