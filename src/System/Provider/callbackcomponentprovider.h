#pragma once

#include "componentprovider.h"
#include "callbackpositionprovider.h"

#include <functional>

namespace sbg {

template <int n>
class CallbackComponentProvider : public virtual ComponentProvider<n>, public virtual CallbackPositionProvider<n>
{
public:
	CallbackComponentProvider(std::function<Vector<n, double>()> position, std::function<Vector<freedom(n), double>()> orientation);
	CallbackComponentProvider(Vector<n, double> position, std::function<Vector<freedom(n), double>()> orientation);
	CallbackComponentProvider(std::function<Vector<n, double>()> position, Vector<freedom(n), double> orientation);
	CallbackComponentProvider(Vector<n, double> position, Vector<freedom(n), double> orientation);
	
	void setOrientation(std::function<Vector<freedom(n), double>()> orientation);
	void setOrientation(Vector<freedom(n), double> orientation);
	
	Vector<freedom(n), double> getOrientation() const override;
	CallbackComponentProvider<n>* clone() const override;
	
private:
	std::function<Vector<freedom(n), double>()> _orientation;
};

extern template class CallbackComponentProvider<2>;
extern template class CallbackComponentProvider<3>;

typedef CallbackComponentProvider<2> CallbackComponentProvider2D;
typedef CallbackComponentProvider<3> CallbackComponentProvider3D;

}
