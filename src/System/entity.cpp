#include "entity.h"

using namespace std;

namespace sbg {

Entity::AbstractProperty::~AbstractProperty() {}

Entity::Entity(Entity&& o) : _properties{move(o._properties)}, _components{move(o._components)} {}

Entity& Entity::operator=(Entity&& o)
{
	_properties = move(o._properties);
	_components = move(o._components);
}


}