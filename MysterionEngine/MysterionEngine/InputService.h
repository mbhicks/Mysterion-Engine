#include "MysterionEngine.h"
#pragma once
#include "InputSystem.h"

namespace MysterionEngine
{
	class InputService : public Service
	{
	private:
		void updateActivity(int, InputSystem*, Activity*);
	public:
		InputService();
		~InputService();
		void performInputService(Activity*);
		void pause();
		void resume();
	};
};