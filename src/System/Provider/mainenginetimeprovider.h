#pragma once

#include "valueprovider.h"
#include "../time.h"
#include "../mainengine.h"
#include <memory>

namespace sbg {

class MainEngineTimeProvider : public ValueProvider<Time>
{
public:
	MainEngineTimeProvider(std::weak_ptr<const MainEngine> mainEngine = {});
	
	Time getValue() const override;
	MainEngineTimeProvider* clone() const override;
	
private:
	std::weak_ptr<const MainEngine> _mainEngineRef;
};

}
