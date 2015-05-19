#pragma once

#include "valueprovider.h"
#include "../time.h"
#include "../mainengine.h"
#include <memory>

namespace sbg {

ValueProvider<Time> makeMainEngineTimeProvider(std::weak_ptr<const MainEngine> mainEngine);

}
