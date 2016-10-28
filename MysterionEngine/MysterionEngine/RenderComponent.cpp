#include "RenderComponent.h"
#include "MysterionEngine.h"

namespace MysterionEngine
{

	RenderComponent::RenderComponent() : Component("Render")
	{
		index = 0;
		visable = true;
	}
	RenderComponent::~RenderComponent()
	{}

	int RenderComponent::getIndex()
	{
		return index;
	}
	void RenderComponent::setIndex(int _index)
	{
		index = _index;
		MEngine->removeComponent(this);
		MEngine->addComponent(this);
	}
	void RenderComponent::setVisable(bool val)
	{
		visable = val;
	}
	bool RenderComponent::isVisable()
	{
		return visable;
	}
};