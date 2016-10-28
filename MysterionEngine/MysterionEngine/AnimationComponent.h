#pragma once
#include "Component.h"

namespace MysterionEngine
{
	class AnimationComponent : public Component
	{
	public:
		AnimationComponent();
		//returns true when animation is over
		virtual bool animate(double) = 0;
	};
};