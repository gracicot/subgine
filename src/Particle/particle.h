#pragma once

#include "../physic.hpp"

class Particle : public PhysicPoint
{
public:
	Particle(const double lifetime = 1);
	~Particle() = default;
	
	double getTime() const;
	void setLifeTime(const double lifetime);
	double getLifetime() const;
	
private:
	double _lifetime;
};
