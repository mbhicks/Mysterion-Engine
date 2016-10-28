
#pragma once

namespace MysterionEngine
{
	class InputSystem
	{
	private:
		InputSystem();
		bool init();
		static bool created;
		SDL_Event event;

	public:
		~InputSystem();
		static InputSystem *createInputSystem();
		int grabInput();
		int getInputEventType();
		int getKeyCode();
		int getMouseBtnX();
		int getMouseBtnY();
		int getMouseBtnIndex();
		int getMouseMotionX();
		int getMouseMotionY();
		int getMouseWheelX();
		int getMouseWheelY();
		SDL_Event getSDLEvent();
	};
};