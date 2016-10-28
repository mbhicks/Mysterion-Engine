#include "MysterionEngine.h"
#include <chrono>
using namespace std::chrono;
#define FPS 60
MysterionEngine::Engine *MEngine;
int main(int argc, char* args[])
{

	double secsPerFrame = 1.0/FPS;
	MEngine = new MysterionEngine::Engine();
	MEngine->init();
	high_resolution_clock::time_point oldTime = high_resolution_clock::now();
	while (MEngine->isRunning())
	{
		high_resolution_clock::time_point newTime = high_resolution_clock::now();
		duration<double> frameTime = duration_cast<duration<double>>(newTime - oldTime);
		double frameTimeDbl = frameTime.count();
		if (frameTimeDbl >= secsPerFrame)
		{
			while (frameTimeDbl >= secsPerFrame)
			{
				MEngine->update(secsPerFrame * 1000);
				frameTimeDbl -= secsPerFrame;
			}
			oldTime = newTime;
		}
	}
	MEngine->destroy();
	delete MEngine;
	return 1;
}