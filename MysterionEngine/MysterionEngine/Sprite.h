#pragma once
#include "Texture.h"

namespace MysterionEngine
{
	class Sprite
	{
	private:
		Texture *image;
		SDL_Rect srcRect;
		double rotation, scaling;
		SDL_Point center;
		bool isHFlipImage;
	protected:
		bool imageLoaded;
		SDL_Color color;

	public:
		Sprite();
		virtual ~Sprite();
		void setImage(Texture*);
		bool loadImage(std::string filename);
		void setDimensions(int, int);
		void setSourcePosition(int, int);
		void setCenterPoint(int, int);
		void setRotation(double);
		void setScaling(double);
		void setARGB(int, int, int, int);

		Texture* getTexture();
		int getWidth();
		int getHeight();
		int getSourceX();
		int getSourceY();
		SDL_Rect getSDLRect();
		int getCenterX();
		int getCenterY();
		SDL_Point getSDLCenterPoint();
		double getRotation();
		double getScaling();
		int getAlpha();
		int getRed();
		int getGreen();
		int getBlue();
		bool imageIsHFlipped();
		void hFlipImage(bool);
	};
};