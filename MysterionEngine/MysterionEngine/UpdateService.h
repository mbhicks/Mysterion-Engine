#include "MysterionEngine.h"
#pragma once

namespace MysterionEngine
{
	class UpdateService : public Service
	{
	public:
		UpdateService();
		void performUpdateService(double);
		void pause();
		void resume();
	};
};