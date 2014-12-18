#pragma once

#include "physicbodycomponentprovider.h"

#include "../../system.hpp"

namespace sbg {

template<int n>
class PhysicBodyDisplayComponentProvider : public virtual PhysicBodyComponentProvider<n>, public virtual DisplayComponentProvider<n>
{
public:
	PhysicBodyDisplayComponentProvider(const PhysicBody<n>& physicBody, Vector<n, double> scale = {});
	PhysicBodyDisplayComponentProvider(const PhysicBody<n>& physicBody, std::function<Vector<n, double>()> scale);
	
	void setScale(Vector<n, double> scale);
	void setScale(std::function<Vector<n, double>()> scale);
	
	virtual Vector<n, double> getScale() const override;
private:
	std::function<Vector<n, double>()> _scale;
};

extern template class PhysicBodyDisplayComponentProvider<2>;
extern template class PhysicBodyDisplayComponentProvider<3>;

typedef PhysicBodyDisplayComponentProvider<2> PhysicBody2DDisplayComponentProvider;
typedef PhysicBodyDisplayComponentProvider<3> PhysicBody3DDisplayComponentProvider;

}
