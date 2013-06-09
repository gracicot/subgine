#pragma once

namespace Traits{

class Angle
{
public:
	Angle() = default;
	~Angle() = default;
	
	virtual double getAngle() const;
	
protected:
	double _angle;
};

}
