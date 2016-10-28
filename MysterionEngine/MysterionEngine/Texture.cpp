#include <SDL_image.h>
#include "Texture.h"
#include "RenderSystem.h"
#include "SystemLocator.h"

namespace MysterionEngine
{
	Texture::Texture()
	{
		this->texture = NULL;
	}

	Texture::~Texture()
	{
		Release();
	}

	int Texture::getWidth()
	{
		return m_sourceRectangle.w;
	};

	int Texture::getHeight()
	{
		return m_sourceRectangle.h;
	};
	//Load the image and get the height an width
	bool Texture::Load(std::string filename)
	{
		Release();
		RenderSystem *renderSysem = SystemLocator::getRenderSystem();
		SDL_Surface* pTempSurface = IMG_Load(filename.c_str());
		if (!pTempSurface)
		{
			return false;
		}
		texture = SDL_CreateTextureFromSurface(renderSysem->getSDLRederer(), pTempSurface);
		SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
		SDL_FreeSurface(pTempSurface);
		SDL_QueryTexture(texture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
		return true;
	}
	void Texture::setSDLTexture(SDL_Texture* _texture)
	{
		Release();
		texture = _texture;
		SDL_QueryTexture(texture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
	}
	void Texture::Release()
	{
		if (texture != NULL)
		{
			SDL_DestroyTexture(texture);
			texture = NULL;
		}
	}
};