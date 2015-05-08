#pragma once

#include <map>
#include <memory>

namespace sbg {

struct Group;

class GroupContainer
{
public:
	Group* group(std::string name);
	
private:
	std::map<std::string, std::unique_ptr<Group>> _groups;
};

}