#include "MysterionEngine.h"
#pragma once

namespace MysterionEngine
{
	class AnimSprite : public Sprite
	{
	private:
		int animColumns;
		double currentFrame;
		int totalFrames;
		int animdir;
		int fps;
	public:
		AnimSprite();
		bool animate(int);

		int getAnimColumns();
		double getCurrentFrame();
		int getTotalFrames();
		int getAnimDir();
		int getFps();

		void setAnimColumns(int);
		void setCurrentFrame(double);
		void setTotalFrames(int);
		void setAnimDir(int);
		void setFps(int);

		void cutFrame();
	};
};
