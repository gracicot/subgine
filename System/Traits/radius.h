#ifndef RADIUS_H
#define RADIUS_H

namespace Traits{

class Radius
{
public:
	Radius() = default;
	~Radius() = default;
	
	virtual double getRadius() const;
	
protected:
	double _radius;
};

}

#endif // RADIUS_H
