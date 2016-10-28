#pragma once
#include "StartUpParams.h"
#include <SDL.h>

namespace MysterionEngine
{
	class WindowSystem
	{
	private:
		WindowSystem(StartUpParams);
		bool init(StartUpParams);
		static bool created;
		SDL_Window *SDLWindow;
		StartUpParams gameConfig;

	public:
		~WindowSystem();
		static WindowSystem *createWindowSystem(StartUpParams);
		StartUpParams getGameConfig();
		//sdl wrapper stuff
		SDL_Window *getSDLWindow();
	};
};