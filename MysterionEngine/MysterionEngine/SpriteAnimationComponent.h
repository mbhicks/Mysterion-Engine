#pragma once
#include "AnimationComponent.h"
#include "AnimSprite.h"

namespace MysterionEngine
{
	class SpriteAnimationComponent : public AnimationComponent
	{
	private:
		AnimSprite *sprite;
	public:
		SpriteAnimationComponent(AnimSprite&);
		bool animate(double);
		virtual void animationCallback(int, bool);
	};
};
