#include "MysterionEngine.h"

namespace MysterionEngine
{
	Service::Service() : Service("default")
	{
	}
	Service::Service(std::string _tag)
	{
		tag = _tag;
		MEngine->addService(this);
	}
	Service::~Service()
	{
		components.clear();
		MEngine->removeService(this);
	}
	std::string Service::getTag()
	{
		return tag;
	}
	std::forward_list<Component*> *Service::getComponents()
	{
		return &components;
	}
	void Service::addComponent(Component* component)
	{
		components.push_front(component);
	}
	void Service::removeComponent(Component* component)
	{
		components.remove(component);
	}
};