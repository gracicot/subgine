#pragma once

class Material
{
public:
	Material(double restitution = 1, double density = 1, double staticFriction = 1, double dynamicFriction = 1);
	
	double getRestitution() const;
	double getDensity() const;
	double getStaticFriction() const;
	double getDynamicFriction() const;
	
	void setRestitution(double restitution);
	void setDensity(double density);
	void setStaticFriction(double staticFriction);
	void setDynamicFriction(double dynamicFriction);
	
private:
	double _restitution;
	double _density;
	double _staticFriction;
	double _dynamicFriction;
};
