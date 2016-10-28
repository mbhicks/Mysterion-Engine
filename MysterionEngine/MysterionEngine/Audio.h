
#pragma once
#include <iostream>
#include <SDL_mixer.h>
#include "Resource.h"

namespace MysterionEngine
{
	class Audio : public Resource
	{
	private:
		Mix_Chunk *audio;
	public:
		Audio();
		~Audio();
		bool load(std::string);
		void play();
		void Release();
	};
};