#include "Audio.h"

namespace MysterionEngine
{
	Audio::Audio()
	{
		audio = NULL;
	}
	Audio::~Audio()
	{
		Release();
	}
	bool Audio::load(std::string file)
	{
		if(audio != NULL)
		{
			Release();
		}
		audio = Mix_LoadWAV(file.c_str());
		if( audio == NULL )
		{
			std::cout<<"Cannot load music resource.";
			return false;
		}
		return true;
	}
	void Audio::play()
	{
		Mix_PlayChannel(-1, audio, 0 );
	}
	void Audio::Release()
	{
		Mix_FreeChunk(audio);
		audio = NULL;
	}
}