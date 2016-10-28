#pragma once
#include "AnimationComponent.h"

namespace MysterionEngine
{
	class ValueAnimationComponent : public AnimationComponent
	{
	protected:
		double *value;
		double from;
		double to;
		int length;
		double distance;
		double speed;
		double animDir;
	public:
		ValueAnimationComponent(double&, double, double, int length = 500);
		bool animate(int);
		virtual void animComplete();
	};
};