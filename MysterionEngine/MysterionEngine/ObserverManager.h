
#include "Observer.h"
#include <forward_list>
#pragma once
namespace MysterionEngine
{
	class ObserverManager
	{
	private:
		std::forward_list<Observer*> observers;
	public:
		void notify(std::string);
	};
}