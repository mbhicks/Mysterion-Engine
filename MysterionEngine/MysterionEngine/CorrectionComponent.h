#pragma once
#include "Component.h"

namespace MysterionEngine
{
	class CorrectionComponent : Component
	{
	public:
		CorrectionComponent();
		virtual void correct(double) = 0;
	};
};
