#pragma once

#include <map>
#include <memory>

namespace sbg {

struct Group;

struct GroupContainer {
	Group* group(std::string name);
	
private:
	std::map<std::string, std::unique_ptr<Group>> _groups;
};

}