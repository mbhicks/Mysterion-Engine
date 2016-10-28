#include "StartUpParams.h"

namespace MysterionEngine
{
	StartUpParams::StartUpParams()
	{
		windowWidth = 800;
		windowHieght = 720;
		fullscreen = false;
		appName = "";
		startActivity = NULL;
	}
	void StartUpParams::setWindowWidth(int width)
	{
		windowWidth = width;
	}
	void StartUpParams::setWindowHeight(int height)
	{
		windowHieght = height;
	}
	void StartUpParams::setFullScreen(bool _fullscreen)
	{
		fullscreen = _fullscreen;
	}
	void StartUpParams::setAppName(std::string name)
	{
		appName = name;
	}
	void StartUpParams::setStartActivity(Activity* activity)
	{
		startActivity = activity;
	}
	int StartUpParams::getWindowWidth()
	{
		return windowWidth;
	}
	int StartUpParams::getWindowHeight()
	{
		return windowHieght;
	}
	bool StartUpParams::isFullScreen()
	{
		return fullscreen;
	}
	std::string StartUpParams::getAppName()
	{
		return appName;
	}
	Activity *StartUpParams::getStartAcivity()
	{
		return startActivity;
	}
};