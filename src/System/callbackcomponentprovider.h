#pragma once

#include "componentprovider.h"

#include <functional>

namespace subgine {

template <int n>
class CallbackComponentProvider : public ComponentProvider<n>
{
public:
	CallbackComponentProvider(std::function<Vector<n, double>()> position, std::function<Vector<freedom(n), double>()> orientation);
	CallbackComponentProvider(Vector<n, double> position, std::function<Vector<freedom(n), double>()> orientation);
	CallbackComponentProvider(std::function<Vector<n, double>()> position, Vector<freedom(n), double> orientation);
	CallbackComponentProvider(Vector<n, double> position, Vector<freedom(n), double> orientation);
	
	void setPosition(std::function<Vector<n, double>()> position);
	void setPosition(Vector<n, double> position);
	void setOrientation(std::function<Vector<freedom(n), double>()> orientation);
	void setOrientation(Vector<freedom(n), double> orientation);
	
	virtual Vector<n, double> getPosition() const override;
	virtual Vector<freedom(n), double> getOrientation() const override;
	
private:
	std::function<Vector<n, double>()> _position;
	std::function<Vector<freedom(n), double>()> _orientation;
};

extern template class CallbackComponentProvider<2>;
extern template class CallbackComponentProvider<3>;

typedef CallbackComponentProvider<2> CallbackComponentProvider2D;
typedef CallbackComponentProvider<3> CallbackComponentProvider3D;

}
