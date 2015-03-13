#pragma once

#include "../../system.hpp"

#include <memory>

namespace sbg {

template<int n> class PhysicPoint;

template<int n>
class PhysicPointPositionProvider : public virtual PositionProvider<n>
{
public:
	PhysicPointPositionProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint);
	
	virtual Vector<n, double> getPosition() const override;
	PhysicPointPositionProvider<n>* clone() const override;
	
protected:
	std::weak_ptr<const PhysicPoint<n>> _physicPoint;
};

extern template class PhysicPointPositionProvider<2>;
extern template class PhysicPointPositionProvider<3>;

typedef PhysicPointPositionProvider<2> PhysicPoint2DPositionProvider;
typedef PhysicPointPositionProvider<3> PhysicPoint3DPositionProvider;

}
