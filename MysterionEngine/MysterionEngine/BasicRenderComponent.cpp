#include "BasicRenderComponent.h"

namespace MysterionEngine
{
	BasicRenderComponent::BasicRenderComponent(Sprite& _sprite, Vector3& _position)
	{
		sprite = &_sprite;
		position = &_position;
	}
	void BasicRenderComponent::draw(RenderSystem* renderSystem)
	{
		renderSystem->renderSprite(sprite, position->getX(), position->getY());
	}
};