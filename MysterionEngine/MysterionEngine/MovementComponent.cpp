#include "MovementComponent.h"

namespace MysterionEngine
{
	MovementComponent::MovementComponent(Vector3& _position, Vector3& _velocity, Vector3& _acceleration)
	{
		position = &_position;
		velocity = &_velocity;
		acceleration = &_acceleration;
	}
	bool MovementComponent::animate(double deltaTime)
	{
		//get the fraction of a second
		double secondFraction = (double)deltaTime / 1000;
		//calc velocity
		velocity->Move(acceleration->getX()*secondFraction, acceleration->getY()*secondFraction,
			acceleration->getZ()*secondFraction);
		//calc position
		position->Move(velocity->getX()*secondFraction, velocity->getY()*secondFraction,
			velocity->getZ()*secondFraction);
		return false;
	}
};