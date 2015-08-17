#include "mainenginetimeprovider.h"

namespace sbg {

ValueProvider<Time> makeMainEngineTimeProvider(std::weak_ptr<const MainEngine> mainEngine)
{
	return [=]{return mainEngine.expired() ? Time{} : mainEngine.lock()->getTime();};
}

}