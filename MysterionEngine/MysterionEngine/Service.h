#include "MysterionEngine.h"

#pragma once
#include "Component.h"

namespace MysterionEngine
{
	class Service
	{
	private:
		std::forward_list<Component*> components;
		std::string tag;
	public:
		Service();
		Service(std::string);
		virtual ~Service();
		std::string getTag();
		std::forward_list<Component*> *getComponents();
		virtual void addComponent(Component*);
		virtual void removeComponent(Component*);
		virtual void pause() = 0;
		virtual void resume() = 0;
	};
};