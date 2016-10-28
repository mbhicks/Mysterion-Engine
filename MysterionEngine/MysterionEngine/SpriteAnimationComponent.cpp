#include "SpriteAnimationComponent.h"

namespace MysterionEngine
{
	SpriteAnimationComponent::SpriteAnimationComponent(AnimSprite& _sprite)
	{
		sprite = &_sprite;
	}
	bool SpriteAnimationComponent::animate(double deltaTime)
	{
		bool looped = sprite->animate(deltaTime);
		if (looped)
		{
			animationCallback(sprite->getTotalFrames(), true);
		}
		else
		{
			animationCallback(sprite->getCurrentFrame(), false);
		}
		return false;
	}
	void SpriteAnimationComponent::animationCallback(int currentFrame, bool looped)
	{}
};