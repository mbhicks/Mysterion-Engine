#include "RenderSystem.h"

namespace MysterionEngine
{
	bool RenderSystem::created = false;
	RenderSystem::RenderSystem(WindowSystem* windowSystem)
	{
		init(windowSystem);
	}
	RenderSystem::~RenderSystem()
	{
		SDL_DestroyRenderer(SDLRenderer);
	}
	bool RenderSystem::init(WindowSystem* windowSystem)
	{
		SDLRenderer = SDL_CreateRenderer(windowSystem->getSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_SetRenderDrawBlendMode(SDLRenderer,
			SDL_BLENDMODE_BLEND);
		return true;
	}
	RenderSystem *RenderSystem::createRenderSystem(WindowSystem* windowSystem)
	{
		if (!created)
		{
			created = true;
			return new RenderSystem(windowSystem);
		}
		return NULL;
	}
	SDL_Renderer *RenderSystem::getSDLRederer()
	{
		return SDLRenderer;
	}
	void RenderSystem::renderSprite(Sprite *sprite, double x, double y)
	{
		SDL_SetTextureColorMod(sprite->getTexture()->GetSDLTexture(), sprite->getRed(), sprite->getGreen(), sprite->getBlue());
		SDL_SetTextureAlphaMod(sprite->getTexture()->GetSDLTexture(), sprite->getAlpha());

		//Account for scaling in destination rect
		SDL_Rect destRect;
		destRect.x = (int)x;
		destRect.y = (int)y;
		destRect.w = (int)(sprite->getWidth()*sprite->getScaling());
		destRect.h = (int)(sprite->getHeight()*sprite->getScaling());
		SDL_RendererFlip flip;
		if (sprite->imageIsHFlipped())
			flip = SDL_FLIP_HORIZONTAL;
		else
			flip = SDL_FLIP_NONE;

		SDL_RenderCopyEx(SDLRenderer,
			sprite->getTexture()->GetSDLTexture(),
			&sprite->getSDLRect(),
			&destRect,
			sprite->getRotation(),
			&sprite->getSDLCenterPoint(),
			flip);
	}
	void RenderSystem::renderBegin()
	{
		//clear the window to black
		SDL_SetRenderDrawColor(SDLRenderer, 0, 0, 0, 255);
		SDL_RenderClear(SDLRenderer);
	}
	void RenderSystem::renderPost()
	{
		//draw the game
		SDL_RenderPresent(SDLRenderer);
	}
};