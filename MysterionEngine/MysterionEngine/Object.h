#pragma once
#include "Vector3.h"

namespace MysterionEngine
{
	class Object
	{
	private:
		Vector3 position;
		Vector3 velocity;
		Vector3 acceleration;
		bool alive;
	public:
		Object();
		virtual ~Object();
		Vector3& getPosition();
		Vector3& getVelocity();
		Vector3& getAcceleration();

		void setPosition(Vector3&);
		void setVelocity(Vector3&);
		void setAcceleration(Vector3&);
		void destroy();
		bool isAlive();
	};
};