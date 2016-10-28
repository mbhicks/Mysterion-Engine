#pragma once
#include <unordered_map>
namespace MysterionEngine
{
	class ServiceManager
	{
	private:
		std::unordered_map<std::string, Service*> services;
	public:
		ServiceManager();
		~ServiceManager();
		void addComponent(Component*);
		void removeComponent(Component*);
		void addService(Service*);
		void removeService(Service*);
	};
}