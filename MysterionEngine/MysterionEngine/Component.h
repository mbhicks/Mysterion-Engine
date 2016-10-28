#pragma once
#include <iostream>

namespace MysterionEngine
{
	class Component
	{
	private:
		std::string tag;
	public:
		Component();
		Component(std::string);
		virtual ~Component();
		std::string getTag();
	};
};
