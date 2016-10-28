#include "AnimSprite.h"

namespace MysterionEngine
{
	AnimSprite::AnimSprite()
	{
		animColumns = 0;
		currentFrame = 0;
		totalFrames = 0;
		animdir = 1;
		fps = 30;
	}
	bool AnimSprite::animate(int deltaTime)
	{
		bool animLooped = false;
		double secondFrac = (double)deltaTime / 1000;
		currentFrame += fps*secondFrac*animdir;
		if (currentFrame > totalFrames || currentFrame < 0)
		{
			animLooped = true;
			//need to do modulus with decimals
			double deci = currentFrame - (int)currentFrame;
			currentFrame = (int)currentFrame % totalFrames;
			currentFrame += deci;
		}
		cutFrame();
		return animLooped;
	}
	void AnimSprite::cutFrame()
	{
		//set the source rectangle
		int fx = ((int)this->currentFrame % this->animColumns) * this->getWidth();
		int fy = ((int)this->currentFrame / this->animColumns) * this->getHeight();

		setSourcePosition(fx, fy);
	}
	int AnimSprite::getAnimColumns()
	{
		return animColumns;
	}
	double AnimSprite::getCurrentFrame()
	{
		return currentFrame;
	}
	int AnimSprite::getTotalFrames()
	{
		return totalFrames;
	}
	int AnimSprite::getAnimDir()
	{
		return animdir;
	}
	int AnimSprite::getFps()
	{
		return fps;
	}

	void AnimSprite::setAnimColumns(int val)
	{
		animColumns = val;
	}
	void AnimSprite::setCurrentFrame(double val)
	{
		currentFrame = val;
	}
	void AnimSprite::setTotalFrames(int val)
	{
		totalFrames = val;
	}
	void AnimSprite::setAnimDir(int val)
	{
		animdir = val;
	}
	void AnimSprite::setFps(int val)
	{
		fps = val;
	}
};