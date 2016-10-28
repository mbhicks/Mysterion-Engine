#include "FontSprite.h"
#include "RenderSystem.h"
#include "SystemLocator.h"

namespace MysterionEngine
{
	FontSprite::FontSprite()
	{
		font = NULL;
	}
	FontSprite::~FontSprite()
	{
		if (font)
		{
			TTF_CloseFont(font);
		}
	}
	void FontSprite::setText(std::string _text)
	{
		text = _text;
		RenderSystem *renderSystem = SystemLocator::getRenderSystem();
		SDL_Surface* pTempSurface;
		SDL_Texture* SDLtexture;
		Texture *texture = this->getTexture();
		if (texture != NULL) delete texture;
		texture = new Texture();


		//write the text to a SDL texture
		pTempSurface = TTF_RenderText_Blended(font, text.c_str(), color);
		SDLtexture = SDL_CreateTextureFromSurface(renderSystem->getSDLRederer(), pTempSurface);
		SDL_FreeSurface(pTempSurface);

		//put the sdl texture in an engine Texure
		texture->setSDLTexture(SDLtexture);
		this->setImage(texture);

		//update parent sprite attributes
		this->setDimensions(texture->getWidth(), texture->getHeight());
		imageLoaded = true;
	}
	void FontSprite::loadFont(std::string filename, int fontSize)
	{
		font = TTF_OpenFont(filename.c_str(), fontSize);
	}
	std::string FontSprite::getText()
	{
		return text;
	}
};