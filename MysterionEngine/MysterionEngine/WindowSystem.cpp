#include "WindowSystem.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>


namespace MysterionEngine
{
	bool WindowSystem::created = false;
	WindowSystem::WindowSystem(StartUpParams params)
	{
		//initialize SDL first
		SDL_Init(SDL_INIT_EVERYTHING);
		init(params);
	}

	WindowSystem::~WindowSystem()
	{
		//close the audio
		Mix_CloseAudio();

		//Close the font
		TTF_Quit();

		SDL_DestroyWindow(SDLWindow);
		SDL_Quit();
	}
	bool WindowSystem::init(StartUpParams params)
	{
		gameConfig = params;
		if (params.isFullScreen())
		{
			//if succeeded create our window in fullscreen
			SDLWindow = SDL_CreateWindow(params.getAppName().c_str(),
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				params.getWindowWidth(), params.getWindowHeight(),
			SDL_WINDOW_FULLSCREEN);
		}
		else
		{
			//if succeeded create our window
			SDLWindow = SDL_CreateWindow(params.getAppName().c_str(),
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				params.getWindowWidth(), params.getWindowHeight(),
				SDL_WINDOW_SHOWN);
		}
		//This is here because the Sound system would be so small and not worth making a whole class
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		//This is here because the Font system would be so small and not worth making a whole class
		TTF_Init();
		return true;
	}
	WindowSystem *WindowSystem::createWindowSystem(StartUpParams params)
	{
		if (!created)
		{
			created = true;
			return new WindowSystem(params);
		}
		return NULL;
	}

	StartUpParams WindowSystem::getGameConfig()
	{
		return gameConfig;
	}

	SDL_Window *WindowSystem::getSDLWindow()
	{
		return SDLWindow;
	}
};