#pragma once
#include <iostream>
#include "Activity.h"

namespace MysterionEngine
{
	class StartUpParams
	{
	private:
		int windowWidth;
		int windowHieght;
		bool fullscreen;
		std::string appName;
		Activity *startActivity;
	public:
		StartUpParams();
		void setWindowWidth(int);
		void setWindowHeight(int);
		void setFullScreen(bool);
		void setAppName(std::string);
		void setStartActivity(Activity*);

		int getWindowWidth();
		int getWindowHeight();
		bool isFullScreen();
		std::string getAppName();
		Activity *getStartAcivity();
	};
};