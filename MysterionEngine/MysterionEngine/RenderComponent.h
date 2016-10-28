#pragma once
#include "RenderSystem.h"
#include "Component.h"
namespace MysterionEngine
{
	class RenderComponent : public Component
	{
	private:
		int index;
		bool visable;
	public:
		RenderComponent();
		virtual ~RenderComponent();
		virtual void draw(RenderSystem*) = 0;
		int getIndex();
		void setIndex(int);
		void setVisable(bool);
		bool isVisable();
	};
};