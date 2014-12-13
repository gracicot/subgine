#pragma once
namespace sbg
{
namespace Traits
{

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
}
