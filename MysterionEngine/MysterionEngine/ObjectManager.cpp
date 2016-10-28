#include <forward_list>
#include "ObjectManager.h"
#include "Object.h"

namespace MysterionEngine
{
	std::forward_list<Object*> ObjectManager::objects;

	void ObjectManager::addObject(Object* object)
	{
		objects.push_front(object);
	}

	void ObjectManager::removeObject(Object* object)
	{
		objects.remove(object);
	}

	void ObjectManager::removeAll()
	{
		std::forward_list<Object*>::iterator search = objects.begin();
		std::forward_list<Object*>::iterator target = objects.before_begin();
		
		while (search != objects.end())
		{
			search = objects.erase_after(target);
		}
	}
	void ObjectManager::CollectGarbage()
	{
		std::forward_list<Object*>::iterator search = objects.begin();
		std::forward_list<Object*>::iterator target = objects.before_begin();

		while (search != objects.end())
		{
			if (!(*search)->isAlive())
			{
				delete (*search);
				search = objects.erase_after(target);
			}
			else
			{
				search++;
				target++;
			}
		}
	}
};