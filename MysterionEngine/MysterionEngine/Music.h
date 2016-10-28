
#pragma once
#include "Resource.h"
#include <iostream>
#include <SDL_mixer.h>

namespace MysterionEngine
{
	class Music : public Resource
	{
	private:
		Mix_Music *gMusic;
	public:
		Music();
		~Music();
		bool load(std::string);
		void play(int num);
		void pause();
		void resume();
		void stop();
		bool isPlaying();
		bool isPaused();
		bool isStopped();
		void Release();
	};
};