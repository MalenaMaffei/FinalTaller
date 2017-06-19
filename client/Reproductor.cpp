
#include "Header Files/Reproductor.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


Reproductor::Reproductor () { }

Reproductor::~Reproductor () { }

void Reproductor::reproducirMusica(const std::string& fileName) {
	SDL_Init(SDL_INIT_AUDIO);

	Mix_Music *sound = NULL;
	int channel;
	
	int audioRate = 22050;
	Uint16 audioFormat = AUDIO_S16SYS;
	int audioChannels = 2;
	int audioBuffers = 4096;
	
	Mix_OpenAudio(audioRate,audioFormat,audioChannels,audioBuffers);
	
	sound = Mix_LoadMUS(fileName.c_str ());

	if (!sound) {
		printf("MixLoadMUS: %s\n", Mix_GetError());
		return;
	}
	
	Mix_VolumeMusic(MIX_MAX_VOLUME/2);
	
	if (Mix_PlayMusic(sound,1) == -1) {
		printf("MixPlayMusic: %s\n", Mix_GetError());
		return;
	}
	
	while(Mix_PlayingMusic() != 0); //Espero a que termine
	
	Mix_FreeMusic(sound);
	Mix_CloseAudio();
	SDL_Quit();

	return;	
}

void Reproductor::reproducirFX(const std::string& fileName) {
	SDL_Init(SDL_INIT_AUDIO);
  
	Mix_Chunk *sound = NULL;
	int channel;
	
	int audioRate = 22050;
	Uint16 audioFormat = AUDIO_S16SYS;
	int audioChannels = 2;
	int audioBuffers = 4096;
	
	Mix_OpenAudio(audioRate,audioFormat,audioChannels,audioBuffers);
	
	sound = Mix_LoadWAV(fileName.c_str());

	if (!sound) {
		printf("MixLoadWAV: %s\n", Mix_GetError());
		return;
	}
	
	Mix_VolumeMusic(MIX_MAX_VOLUME/2);
	
	if (Mix_PlayChannel(-1,sound,0) == -1) {
		printf("MixPlay: %s\n", Mix_GetError());
		return;
	}
	
	while(Mix_Playing(channel) != 0); //Espero a que termine
	
	Mix_FreeChunk(sound);
	Mix_CloseAudio();
	SDL_Quit();

	return;		
}
