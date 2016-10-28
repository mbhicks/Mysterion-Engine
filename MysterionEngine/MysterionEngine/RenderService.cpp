#include "MysterionEngine.h"
#include "SystemLocator.h"
#include "RenderComponent.h"
#include <thread>
namespace MysterionEngine
{
	std::atomic_bool startRender;
	std::atomic_bool rendering;
	std::atomic_bool terminate;
	std::atomic_bool finished;
	void backgroundRender()
	{
		while (!terminate)
		{
			if (startRender)
			{
				RenderSystem *renderSystem = SystemLocator::getRenderSystem();
				renderSystem->renderPost();
				startRender = false;
				rendering = false;
			}
		}
		finished = true;
	}
	RenderService::RenderService() : Service("Render")
	{
		startRender = false;
		rendering = false;
		terminate = false;
		finished = false;
		std::thread renderThread(backgroundRender);
		renderThread.detach();
	}
	RenderService::~RenderService()
	{
		terminate = true;
		while (!finished)
		{}
	}
	void RenderService::performRenderService()
	{
		if (!rendering)
		{
			RenderSystem *renderSystem = SystemLocator::getRenderSystem();
			std::forward_list<Component*> *components = this->getComponents();
			RenderComponent *component;
			renderSystem->renderBegin();
			for (std::forward_list<Component*>::iterator it = components->begin(); it != components->end(); ++it)
			{
				component = (RenderComponent*)(*it);
				if (component->isVisable())
					component->draw(renderSystem);
			}
			startRender = true;
			rendering = true;
		}
	}
	void RenderService::addComponent(Component* component)
	{
		std::forward_list<Component*> *components = this->getComponents();
		std::forward_list<Component*>::iterator search = components->begin();
		std::forward_list<Component*>::iterator target = components->before_begin();
		RenderComponent *renderCompo = (RenderComponent*)component;
		bool added = false;
		while (!added)
		{
			if (components->empty() || search == components->end())
			{
				components->insert_after(target, component);
				added = true;
			}
			else
			{
				RenderComponent *searchCompo = (RenderComponent*)(*search);
				if (searchCompo->getIndex() > renderCompo->getIndex())
				{
					components->insert_after(target, component);
					added = true;
				}
				else
				{
					search++;
					target++;
				}
			}
		}

	}
	void RenderService::pause()
	{}
	void RenderService::resume()
	{}
};