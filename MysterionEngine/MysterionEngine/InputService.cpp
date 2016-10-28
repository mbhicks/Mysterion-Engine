#include "MysterionEngine.h"
#include "SystemLocator.h"
#include "InputComponent.h"
namespace MysterionEngine
{
	InputService::InputService() : Service("Input")
	{}
	InputService::~InputService()
	{}
	void InputService::performInputService(Activity* activity)
	{
		InputSystem* inputSystem = SystemLocator::getInputSystem();
		while (inputSystem->grabInput())
		{
			int eventType = inputSystem->getInputEventType();
			if (eventType == SDL_QUIT)
			{
				MEngine->shutDown();
			}
			//update current activity input
			updateActivity(eventType, inputSystem, activity);

			std::forward_list<Component*> *components = this->getComponents();
			InputComponent *component;
			for (std::forward_list<Component*>::iterator it = components->begin(); it != components->end(); ++it)
			{
				component = (InputComponent*)(*it);
				switch (eventType)
				{
				case SDL_KEYUP:
					component->keyUp(inputSystem->getKeyCode());
					break;
				case SDL_KEYDOWN:
					component->keyDown(inputSystem->getKeyCode());
					break;
				case SDL_MOUSEBUTTONUP:
					component->mouseBtnUp(inputSystem->getMouseBtnX(), inputSystem->getMouseBtnY(), inputSystem->getMouseBtnIndex());
					break;
				case SDL_MOUSEBUTTONDOWN:
					component->mouseBtnDown(inputSystem->getMouseBtnX(), inputSystem->getMouseBtnY(), inputSystem->getMouseBtnIndex());
					break;
				case SDL_MOUSEMOTION:
					component->mouseMotion(inputSystem->getMouseMotionX(), inputSystem->getMouseMotionY());
					break;
				case SDL_MOUSEWHEEL:
					component->mouseWheel(inputSystem->getMouseWheelX(), inputSystem->getMouseWheelY());
					break;
				case SDL_JOYBUTTONUP:
					component->joyButtonUp(inputSystem->getSDLEvent().jbutton.button, inputSystem->getSDLEvent().jbutton.which);
					break;
				case SDL_JOYBUTTONDOWN:
					//gameJoyButtonDown(event.jbutton.button, event.jbutton.which);
					component->joyButtonDown(inputSystem->getSDLEvent().jbutton.button, inputSystem->getSDLEvent().jbutton.which);
					break;
				case SDL_JOYAXISMOTION:
					//gameJoyAxis(event.jaxis.value, event.jaxis.axis, event.jbutton.which);
					component->joyAxisMove(inputSystem->getSDLEvent().jaxis.value, inputSystem->getSDLEvent().jaxis.axis,
						inputSystem->getSDLEvent().jbutton.which);
					break;
				case SDL_JOYDEVICEADDED:
					//gameJoyAddRmv(event.jdevice.which, SDL_JOYDEVICEADDED);
					SDL_JoystickOpen(0);
					std::cout << "found Joystick";
					break;
				case SDL_JOYDEVICEREMOVED:
					//gameJoyAddRmv(event.jdevice.which, SDL_JOYDEVICEREMOVED);
					break;
				default:
					break;
				}
			}
		}
		std::forward_list<Component*> *components = this->getComponents();
		InputComponent *component;
		for (std::forward_list<Component*>::iterator it = components->begin(); it != components->end(); ++it)
		{
			component = (InputComponent*)(*it);
			component->inputEnd();
		}
	}
	void InputService::updateActivity(int eventType, InputSystem* inputSystem, Activity* activity)
	{
		switch (eventType)
		{
		case SDL_KEYUP:
			activity->keyUp(inputSystem->getKeyCode());
			break;
		case SDL_KEYDOWN:
			activity->keyDown(inputSystem->getKeyCode());
			break;
		case SDL_MOUSEBUTTONUP:
			activity->mouseBtnUp(inputSystem->getMouseBtnX(), inputSystem->getMouseBtnY(), inputSystem->getMouseBtnIndex());
			break;
		case SDL_MOUSEBUTTONDOWN:
			activity->mouseBtnDown(inputSystem->getMouseBtnX(), inputSystem->getMouseBtnY(), inputSystem->getMouseBtnIndex());
			break;
		case SDL_MOUSEMOTION:
			activity->mouseMotion(inputSystem->getMouseMotionX(), inputSystem->getMouseMotionY());
			break;
		case SDL_MOUSEWHEEL:
			activity->mouseWheel(inputSystem->getMouseWheelX(), inputSystem->getMouseWheelY());
			break;
		default:
			break;
		}
	}
	void InputService::pause()
	{}
	void InputService::resume()
	{}
};