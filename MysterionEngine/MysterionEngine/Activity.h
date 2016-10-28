#pragma once
namespace MysterionEngine
{
	class Activity
	{
	public:
		virtual ~Activity() {}
		virtual void start() {}
		virtual void restart() {}
		virtual void update(double) {}
		virtual void pause() {}
		virtual void destroy() {}
		virtual void render() {}

		virtual void keyUp(int key) {}
		virtual void keyDown(int key) {}
		virtual void mouseBtnDown(int x, int y, int btn) {}
		virtual void mouseBtnUp(int x, int y, int btn) {}
		virtual void mouseMotion(int x, int y) {}
		virtual void mouseWheel(int x, int y) {}
	};
};