#pragma once
#include "Component.h"

namespace MysterionEngine
{
	class InputComponent : Component
	{
	public:
		InputComponent();
		virtual void keyUp(int) {}
		virtual void keyDown(int) {}
		virtual void mouseBtnDown(int, int, int) {}
		virtual void mouseBtnUp(int, int, int) {}
		virtual void mouseMotion(int, int) {}
		virtual void mouseWheel(int, int) {}
		virtual void joyButtonUp(int, int) {}
		virtual void joyButtonDown(int, int) {}
		virtual void joyAxisMove(int, int, int) {}
		virtual void inputEnd() {}
	};
};