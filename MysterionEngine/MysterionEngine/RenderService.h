#include "MysterionEngine.h"
#include <atomic>
#pragma once

namespace MysterionEngine
{
	class RenderService : public Service
	{
	public:
		RenderService();
		~RenderService();
		void performRenderService();
		void pause();
		void resume();
		void addComponent(Component*);
	};
};