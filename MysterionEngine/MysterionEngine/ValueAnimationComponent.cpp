#include "ValueAnimationComponent.h"

namespace MysterionEngine
{
	ValueAnimationComponent::ValueAnimationComponent(double& _value, double _from, double _to, int _length)
	{
		value = &_value;
		*value = _from;
		from = _from;
		to = _to;
		length = _length;
		distance = to - from;
		speed = distance / (length / (double)1000);
		if (distance > 0)
		{
			animDir = 1;
		}
		else
		{
			animDir = -1;
		}
	}

	bool ValueAnimationComponent::animate(int deltaTime)
	{
		double fracSecond = deltaTime / (double)1000;
		*value += speed*fracSecond;
		if ((to - *value)*animDir <= 0)
		{
			*value = to;
			animComplete();
			return true;
		}
		return false;
	}
	void ValueAnimationComponent::animComplete()
	{}
};