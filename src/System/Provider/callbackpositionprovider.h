#pragma once

#include "positionprovider.h"

#include <functional>

namespace subgine {

template<int n>
class CallbackPositionProvider : public virtual PositionProvider<n>
{
public:
	CallbackPositionProvider(std::function<Vector<n, double>()> position);
	CallbackPositionProvider(Vector<n, double> position = Vector<n, double>());
	
	void setPosition(std::function<Vector<n, double>()> position);
	void setPosition(Vector<n, double> position);
	
	virtual Vector<n, double> getPosition() const override;
private:
	std::function<Vector<n, double>()> _position;
};

extern template class CallbackPositionProvider<2>;
extern template class CallbackPositionProvider<3>;

typedef CallbackPositionProvider<2> CallbackPositionProvider2D;
typedef CallbackPositionProvider<3> CallbackPositionProvider3D;

}