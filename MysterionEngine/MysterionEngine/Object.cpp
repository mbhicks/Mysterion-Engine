#include "Object.h"

namespace MysterionEngine
{
	Object::Object()
	{
		alive = true;
	}
	Object::~Object()
	{}
	Vector3& Object::getPosition()
	{
		return position;
	}
	Vector3& Object::getVelocity()
	{
		return velocity;
	}
	Vector3& Object::getAcceleration()
	{
		return acceleration;
	}
	void Object::setPosition(Vector3& _position)
	{
		position.Set(_position);
	}
	void Object::setVelocity(Vector3& _velocity)
	{
		velocity.Set(_velocity);
	}
	void Object::setAcceleration(Vector3& _acceleration)
	{
		acceleration.Set(_acceleration);
	}
	void Object::destroy()
	{
		alive = false;
	}
	bool Object::isAlive()
	{
		return alive;
	}
};