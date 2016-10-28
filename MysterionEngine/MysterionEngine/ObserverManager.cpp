#include "ObserverManager.h"

namespace MysterionEngine
{
	void ObserverManager::notify(std::string event)
	{
		for (std::forward_list<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it)
		{
			(*it)->onNotify(event);
		}
	}
};