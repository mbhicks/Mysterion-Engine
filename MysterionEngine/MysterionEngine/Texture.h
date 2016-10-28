#pragma once
#include <iostream>
#include <SDL.h>
#include "Resource.h"
namespace MysterionEngine
{
	class Texture : public Resource
	{
	public:
		Texture();
		~Texture();
		//	bool create(int width,int height);
		bool Load(std::string filename);
		void Release();
		SDL_Texture* GetSDLTexture() { return texture; }
		void setSDLTexture(SDL_Texture*);
		int getWidth();
		int getHeight();
	private:
		SDL_Texture* texture;
		SDL_Rect m_sourceRectangle;
	};
}