#include "MysterionEngine.h"
#pragma once

namespace MysterionEngine
{
	class AnimationService : public Service
	{
	public:
		AnimationService();
		void performAnimationService(double);
		void pause();
		void resume();
	};
};