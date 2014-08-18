#pragma once

namespace subgine
{
namespace Traits
{

class Angle
{
public:
	Angle() = default;
	Angle(double angle);
	~Angle() = default;

	virtual double getAngle() const;

protected:
	double _angle;
};

}
}
