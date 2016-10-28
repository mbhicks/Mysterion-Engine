#pragma once
#include "Sprite.h"
#include "WindowSystem.h"

namespace MysterionEngine
{
	class RenderSystem
	{
	private:
		RenderSystem(WindowSystem*);
		bool init(WindowSystem*);
		SDL_Renderer* SDLRenderer;
		static bool created;

	public:
		~RenderSystem();
		static RenderSystem *createRenderSystem(WindowSystem*);
		SDL_Renderer *getSDLRederer();

		void renderSprite(Sprite*, double, double);
		void renderBegin();
		void renderPost();
	};
};