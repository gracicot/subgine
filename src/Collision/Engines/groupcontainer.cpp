#include "groupcontainer.h"

#include "group.h"

// This is for the make_unique function
#include "../../system.hpp"

using namespace std;

namespace sbg {

Group* GroupContainer::group(string name)
{
	auto it = _groups.find(name);
	
	if (it != _groups.end()) {
		return it->second.get();
	} else {
		return (_groups[name] = make_unique<Group>()).get();
	}
}

}
