#pragma once
#include "AnimationComponent.h"
#include "Vector3.h"

namespace MysterionEngine
{
	class MovementComponent : public AnimationComponent
	{
	protected:
		Vector3 *position;
		Vector3 *velocity;
		Vector3 *acceleration;
	public:
		MovementComponent(Vector3&, Vector3&, Vector3&);
		bool animate(double);
	};
};