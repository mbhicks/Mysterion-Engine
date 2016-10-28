#include "MysterionEngine.h"
#include "SystemLocator.h"
#include "ResourceManager.h"
#include "ObjectManager.h"
#include <time.h>

namespace MysterionEngine
{
	Engine::Engine()
	{
		running = true;
		nextActivity = NULL;
		finishActivity = false;
	}
	void Engine::init()
	{
		//set the random number seed
		srand((int)time(NULL));
		//Let the game inicialize before systems are created
		StartUpParams perams = initialize();
		//Must create the window system first in order to create the other systems
		window = WindowSystem::createWindowSystem(perams);
		SystemLocator::setWindowSystem(window);
		//create render system
		renderSystem = RenderSystem::createRenderSystem(window);
		SystemLocator::setRenderSystem(renderSystem);
		//Create the input system
		input = InputSystem::createInputSystem();
		SystemLocator::setInputSystem(input);

		//Start Engine Services
		renderService = new RenderService();
		inputService = new InputService();
		updateService = new UpdateService();
		animationService = new AnimationService();
		correctionService = new CorrectionService();

		//Start the initial activity
		Activity *startActivity = perams.getStartAcivity();
		startActivity->start();
		activityStack.push_front(startActivity);
	}
	void Engine::update(double deltaTime)
	{
		//change activity if needed
		if (finishActivity)
		{
			activityStack.front()->destroy();
			delete activityStack.front();
			activityStack.pop_front();
			activityStack.front()->restart();
		}
		if (nextActivity)
		{
			activityStack.front()->pause();
			nextActivity->start();
			activityStack.push_front(nextActivity);
		}
		//Get Input first
		inputService->performInputService(activityStack.front());

		//Move the game objects
		animationService->performAnimationService(deltaTime);

		//update game
		updateService->performUpdateService(deltaTime);
		activityStack.front()->update(deltaTime);

		//Render the game to the screen
		renderService->performRenderService();

		//make corrections before next frame
		correctionService->performCorrectionService(deltaTime);

		ObjectManager::CollectGarbage();
	}
	void Engine::startActivity(Activity* activity)
	{
		nextActivity = activity;
	}
	void Engine::finish()
	{
		finishActivity = true;
	}
	bool Engine::isRunning()
	{
		return running;
	}
	void Engine::shutDown()
	{
		running = false;
	}
	void Engine::addComponent(Component* component)
	{
		serviceManager.addComponent(component);
	}
	void Engine::addService(Service* service)
	{
		serviceManager.addService(service);
	}
	void Engine::removeService(Service* service)
	{
		serviceManager.removeService(service);
	}
	void Engine::removeComponent(Component* component)
	{
		serviceManager.removeComponent(component);
	}
	void Engine::destroy()
	{
		//Destroy all objects
		ObjectManager::removeAll();
		//Clear Activities
		for (auto it = activityStack.begin(); it != activityStack.end(); ++it)
		{
			(*it)->destroy();
			delete (*it);
		}
		activityStack.clear();

		//destroy services
		delete renderService;
		delete inputService;
		delete updateService;
		delete animationService;

		//clear resouces
		ResourceManager::release();

		//destroySystems
		delete input;
		delete renderSystem;
		delete window;
	}
};