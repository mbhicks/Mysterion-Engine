#include "Component.h"
#include "MysterionEngine.h"

namespace MysterionEngine
{
	Component::Component() : Component("default")
	{	
	}
	Component::Component(std::string _tag)
	{
		tag = _tag;
		MEngine->addComponent(this);
	}
	Component::~Component()
	{
		MEngine->removeComponent(this);
	}
	std::string Component::getTag()
	{
		return tag;
	}
};