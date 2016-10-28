#pragma once
#include <forward_list>

#include "Component.h"
#include "Service.h"

//Main
#include "Activity.h"
#include "StartUpParams.h"

#include "WindowSystem.h"
#include "RenderSystem.h"

#include "RenderService.h"
#include "InputService.h"
#include "UpdateService.h"
#include "AnimationService.h"
#include "CorrectionService.h"
#include "ServiceManager.h"

extern MysterionEngine::StartUpParams initialize();
namespace MysterionEngine
{
	class Engine
	{
	public:
		Engine();
		void init();
		void update(double);
		void destroy();
		bool isRunning();
		void shutDown();
		void addComponent(Component*);
		void addService(Service*);
		void removeComponent(Component*);
		void removeService(Service*);
		void startActivity(Activity*);
		void finish();
	private:
		bool running;
		WindowSystem *window;
		InputSystem *input;
		RenderSystem *renderSystem;
		RenderService *renderService;
		InputService *inputService;
		UpdateService *updateService;
		AnimationService *animationService;
		CorrectionService *correctionService;
		Activity* nextActivity;
		bool finishActivity;
		std::forward_list<Activity*> activityStack;	
		ServiceManager serviceManager;

	};
};
extern MysterionEngine::Engine *MEngine;