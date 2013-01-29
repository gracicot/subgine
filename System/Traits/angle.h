#ifndef ANGLE_H
#define ANGLE_H

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

#endif // ANGLE_H
