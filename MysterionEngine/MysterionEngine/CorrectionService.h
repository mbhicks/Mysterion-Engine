#include "MysterionEngine.h"
#pragma once

namespace MysterionEngine
{
	class CorrectionService : public Service
	{
	public:
		CorrectionService();
		void performCorrectionService(double);
		void pause();
		void resume();
	};
};
