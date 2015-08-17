#pragma once

#include "provider.h"
#include "../time.h"
#include "../mainengine.h"
#include <memory>

namespace sbg {

Provider<Time> makeMainEngineTimeProvider(std::weak_ptr<const MainEngine> mainEngine);

}
