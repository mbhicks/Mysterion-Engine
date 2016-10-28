#pragma once
#include "Object.h"

namespace MysterionEngine
{
	class ObjectManager
	{
	private:
		static std::forward_list<Object*> objects;
	public:
		static void addObject(Object*);
		static void removeObject(Object*);
		static void removeAll();
		static void CollectGarbage();
	};
};