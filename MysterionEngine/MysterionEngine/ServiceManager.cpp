#include "MysterionEngine.h"

namespace MysterionEngine
{
	ServiceManager::ServiceManager()
	{}
	ServiceManager::~ServiceManager()
	{}
	void ServiceManager::addService(Service* service)
	{
		//add service to service map
		services[service->getTag()] = service;
	}
	void ServiceManager::removeService(Service* service)
	{
		services.erase(service->getTag());
	}
	void ServiceManager::addComponent(Component* component)
	{
		//Add the component to the service with the same tag
		services[component->getTag()]->addComponent(component);
	}
	void ServiceManager::removeComponent(Component* component)
	{
		services[component->getTag()]->removeComponent(component);
	}
};