#include <unordered_map>
#include "Music.h"
#include "Audio.h"
#pragma once

namespace MysterionEngine
{
	class ResourceManager
	{
	private:
		static std::unordered_map<std::string, Resource*> resources;
	public:
		static void loadResourcesFromFile(std::string);
		static void loadTexture(std::string);
		static void loadFont(std::string);
		static void loadMusic(std::string);
		static void loadAudio(std::string);
		static void loadResource(std::string, std::string);

		static Resource *getResource(std::string);
		static void release();
	};
};