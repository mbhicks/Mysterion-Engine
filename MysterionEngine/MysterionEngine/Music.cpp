#include "Music.h"
namespace MysterionEngine
{
	Music::Music()
	{
		gMusic = NULL;
	}
	Music::~Music()
	{
		Release();
	}
	bool Music::load(std::string file)
	{
		Release();
		gMusic = Mix_LoadMUS(file.c_str());
		if( gMusic == NULL )
		{
			return false;
		}
		return true;
	}
	void Music::play(int num)
	{
		Mix_PlayMusic( gMusic, num );
	}
	void Music::pause()
	{
		Mix_PauseMusic();
	}
	void Music::resume()
	{
		Mix_ResumeMusic();
	}
	void Music::stop()
	{
		Mix_HaltMusic();
	}
	bool Music::isPlaying()
	{
		if(Mix_PlayingMusic())
		{
			return true;
		}
		return false;
	}
	bool Music::isPaused()
	{
		if(Mix_PausedMusic())
		{
			return true;
		}
		return false;
	}
	bool Music::isStopped()
	{
		if(Mix_PlayingMusic())
		{
			return true;
		}
		return false;
	}
	void Music::Release()
	{
		if(gMusic != NULL)
		{
			Mix_FreeMusic(gMusic);
			gMusic = NULL;
		}
	}
}