
#include <string>
#pragma once
namespace MysterionEngine
{
	class Observer
	{
	public:
		virtual void onNotify(std::string) = 0;
	};
};