#include "MysterionEngine.h"
#include "UpdateComponent.h"
namespace MysterionEngine
{
	UpdateService::UpdateService() : Service("Update")
	{}
	void UpdateService::performUpdateService(double deltaTime)
	{
		std::forward_list<Component*> *components = this->getComponents();
		UpdateComponent *component;
		for (std::forward_list<Component*>::iterator it = components->begin(); it != components->end(); ++it)
		{
			component = (UpdateComponent*)(*it);
			component->update(deltaTime);
		}
	}
	void UpdateService::pause()
	{}
	void UpdateService::resume()
	{}
};