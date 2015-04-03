#include "mainenginetimeprovider.h"

namespace sbg {

MainEngineTimeProvider::MainEngineTimeProvider(std::weak_ptr< const sbg::MainEngine > mainEngine) : _mainEngineRef{mainEngine}
{

}

Time MainEngineTimeProvider::getValue() const
{
	return _mainEngineRef.expired() ? Time{} : _mainEngineRef.lock()->getTime();
}

MainEngineTimeProvider* MainEngineTimeProvider::clone() const
{
	return new MainEngineTimeProvider(*this);
}

}
