#include "MysterionEngine.h"

namespace MysterionEngine
{
	bool InputSystem::created = false;
	InputSystem::InputSystem()
	{
		init();
	}
	InputSystem::~InputSystem()
	{}
	bool InputSystem::init()
	{
		return true;
	}
	int InputSystem::grabInput()
	{
		return SDL_PollEvent(&event);
	}
	int InputSystem::getInputEventType()
	{
		return event.type;
	}
	int InputSystem::getKeyCode()
	{
		return event.key.keysym.sym;
	}
	int InputSystem::getMouseBtnX()
	{
		return event.button.x;
	}
	int InputSystem::getMouseBtnY()
	{
		return event.button.y;
	}
	int InputSystem::getMouseBtnIndex()
	{
		return event.button.button;
	}
	int InputSystem::getMouseMotionX()
	{
		return event.motion.x;
	}
	int InputSystem::getMouseMotionY()
	{
		return event.motion.y;
	}
	int InputSystem::getMouseWheelX()
	{
		return event.wheel.x;
	}
	int InputSystem::getMouseWheelY()
	{
		return event.wheel.y;
	}
	SDL_Event InputSystem::getSDLEvent()
	{
		return event;
	}
	InputSystem *InputSystem::createInputSystem()
	{
		if (!created)
		{
			created = true;
			return new InputSystem();
		}
		return NULL;
	}
};