#include "WindowSystem.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#pragma once

namespace MysterionEngine
{
	/*Gives access to all engine systems*/
	class SystemLocator
	{
	private:
		static WindowSystem *windowSystem;
		static InputSystem *inputSystem;
		static RenderSystem *renderSystem;
	public:
		static void setWindowSystem(WindowSystem *);
		static WindowSystem *getWindowSystem();

		static void setInputSystem(InputSystem *);
		static InputSystem *getInputSystem();

		static void setRenderSystem(RenderSystem *);
		static RenderSystem *getRenderSystem();
	};
};