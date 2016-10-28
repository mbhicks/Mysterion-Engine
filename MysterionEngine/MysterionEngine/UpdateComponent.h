#pragma once
#include "Component.h"

namespace MysterionEngine
{
	class UpdateComponent : public Component
	{
	public:
		UpdateComponent();
		virtual void update(int) = 0;
	};
};