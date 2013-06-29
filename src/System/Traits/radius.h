#pragma once
namespace subgine
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
