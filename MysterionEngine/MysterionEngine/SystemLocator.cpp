#include "SystemLocator.h"


namespace MysterionEngine
{
	WindowSystem *SystemLocator::windowSystem = NULL;
	InputSystem *SystemLocator::inputSystem = NULL;
	RenderSystem *SystemLocator::renderSystem = NULL;
	void SystemLocator::setWindowSystem(WindowSystem *_windowSystem)
	{
		windowSystem = _windowSystem;
	}

	WindowSystem *SystemLocator::getWindowSystem()
	{
		return windowSystem;
	}

	void SystemLocator::setInputSystem(InputSystem *_inputSystem)
	{
		inputSystem = _inputSystem;
	}
	InputSystem *SystemLocator::getInputSystem()
	{
		return inputSystem;
	}

	void SystemLocator::setRenderSystem(RenderSystem *_renderSystem)
	{
		renderSystem = _renderSystem;
	}
	RenderSystem *SystemLocator::getRenderSystem()
	{
		return renderSystem;
	}
}