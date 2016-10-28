#include "ResourceManager.h"
#include "tinyxml.h"
#include "Texture.h"
#include "FontSprite.h"

namespace MysterionEngine
{
	std::unordered_map<std::string, Resource*> ResourceManager::resources;
	void ResourceManager::loadTexture(std::string filename)
	{
		Texture *texture = new Texture();
		texture->Load(filename);
		resources[filename] = texture;
	}
	void ResourceManager::loadFont(std::string filename)
	{
		FontSprite *fontSprite = new FontSprite();
		fontSprite->loadFont(filename, 36);
		resources[filename] = fontSprite;
	}
	void ResourceManager::loadMusic(std::string filename)
	{
		Music *music = new Music();
		music->load(filename);
		resources[filename] = music;
	}
	void ResourceManager::loadAudio(std::string filename)
	{
		Audio *audio = new Audio();
		audio->load(filename);
		resources[filename] = audio;
	}
	void ResourceManager::loadResourcesFromFile(std::string filename)
	{
		TiXmlDocument doc;
		TiXmlNode* current;
		bool success = doc.LoadFile(filename.c_str());
		if (success)
		{
			current = doc.FirstChild()->FirstChild();
			while (current)
			{
				std::string rFile;
				TiXmlElement *element = current->ToElement();
				rFile = element->Attribute("filename");
				loadResource(current->Value(), rFile);
				current = current->NextSibling();
			}
		}
	}
	void ResourceManager::loadResource(std::string type, std::string filename)
	{
		if (type == "Texture")
		{
			loadTexture(filename);
		}
		else if (type == "Font")
		{
			loadFont(filename);
		}
		else if (type == "Music")
		{
			loadMusic(filename);
		}
		else if (type == "Audio")
		{
			loadAudio(filename);
		}
	}
	Resource *ResourceManager::getResource(std::string filename)
	{
		return resources[filename];
	}
	void ResourceManager::release()
	{
		Resource *resource;
		auto it = resources.begin();
		while (it != resources.end())
		{
			resource = it->second;
			it = resources.erase(it);
			delete resource;
		}
	}
};