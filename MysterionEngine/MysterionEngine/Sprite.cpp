#include "Sprite.h"

namespace MysterionEngine
{
	Sprite::Sprite()
	{
		image = NULL;
		rotation = 0;
		scaling = 1;
		srcRect.h = 0;
		srcRect.w = 0;
		color.a = 255;
		color.r = 255;
		color.g = 255;
		color.b = 255;
		isHFlipImage = false;
		imageLoaded = false;
	}
	Sprite::~Sprite()
	{
		if (imageLoaded)
		{
			delete image;
		}
	}
	void Sprite::setImage(Texture *image)
	{
		this->image = image;
		this->setDimensions(image->getWidth(), image->getHeight());
		this->imageLoaded = false;
	}
	bool Sprite::loadImage(std::string filename)
	{
		if (image != NULL) delete image;

		image = new Texture();
		if (image->Load(filename))
		{
			this->setDimensions(image->getWidth(), image->getHeight());
			imageLoaded = true;
			return true;
		}
		else
			return false;
	}
	void Sprite::setDimensions(int _width, int _height)
	{
		srcRect.w = _width;
		srcRect.h = _height;
	}
	void Sprite::setSourcePosition(int x, int y)
	{
		srcRect.x = x;
		srcRect.y = y;
	}
	void Sprite::setCenterPoint(int x, int y)
	{
		center.x = x;
		center.y = y;
	}
	void Sprite::setRotation(double _rotation)
	{
		rotation = _rotation;
	}
	void Sprite::setScaling(double _scaling)
	{
		scaling = _scaling;
	}
	void Sprite::setARGB(int a, int r, int g, int b)
	{
		color.a = a;
		color.r = r;
		color.g = g;
		color.b = b;
	}
	Texture* Sprite::getTexture()
	{
		return image;
	}
	int Sprite::getWidth()
	{
		return srcRect.w;
	}
	int Sprite::getHeight()
	{
		return srcRect.h;
	}
	int Sprite::getSourceX()
	{
		return srcRect.x;
	}
	int Sprite::getSourceY()
	{
		return srcRect.y;
	}
	SDL_Rect Sprite::getSDLRect()
	{
		return srcRect;
	}
	int Sprite::getCenterX()
	{
		return center.x;
	}
	int Sprite::getCenterY()
	{
		return center.y;
	}
	SDL_Point Sprite::getSDLCenterPoint()
	{
		return center;
	}
	double Sprite::getRotation()
	{
		return rotation;
	}
	double Sprite::getScaling()
	{
		return scaling;
	}
	int Sprite::getAlpha()
	{
		return color.a;
	}
	int Sprite::getRed()
	{
		return color.r;
	}
	int Sprite::getGreen()
	{
		return color.g;
	}
	int Sprite::getBlue()
	{
		return color.b;
	}
	bool Sprite::imageIsHFlipped()
	{
		return isHFlipImage;
	}
	void Sprite::hFlipImage(bool val)
	{
		isHFlipImage = val;
	}
};