#include "mainenginetimeprovider.h"

#include <functional>

namespace sbg {

Provider<Time> makeMainEngineTimeProvider(std::weak_ptr<const MainEngine> mainEngine)
{
	return [=] {return mainEngine.expired() ? Time{} : mainEngine.lock()->getTime(); };
}

}
