#include <SDL_ttf.h>
#include "Sprite.h"
#pragma once

namespace MysterionEngine
{
	class FontSprite : public Sprite, public Resource
	{
	private:
		TTF_Font *font;
		std::string text;
	public:
		FontSprite();
		~FontSprite();
		void setText(std::string);
		void loadFont(std::string, int);
		std::string getText();
	};
};
