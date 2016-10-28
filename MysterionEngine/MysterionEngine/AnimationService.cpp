#include "MysterionEngine.h"
#include "AnimationComponent.h"

namespace MysterionEngine
{
	AnimationService::AnimationService() : Service("Animation")
	{}
	void AnimationService::performAnimationService(double deltaTime)
	{
		std::forward_list<Component*> *components = this->getComponents();
		AnimationComponent *component;
		for (std::forward_list<Component*>::iterator it = components->begin(); it != components->end(); ++it)
		{
			component = (AnimationComponent*)(*it);
			component->animate(deltaTime);
		}
	}
	void AnimationService::pause()
	{}
	void AnimationService::resume()
	{}
};