#pragma once
#include "Vector3.h"
#include "RenderComponent.h"

namespace MysterionEngine
{
	class BasicRenderComponent : public RenderComponent
	{
	private:
		Sprite *sprite;
		Vector3 *position;
	public:
		BasicRenderComponent(Sprite&, Vector3&);
		void draw(RenderSystem*);
	};
};