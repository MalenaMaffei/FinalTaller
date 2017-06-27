
#include "Header Files/Reproductor.h"
#include "Header Files/constantes.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


Reproductor::Reproductor() {
	robotManufactured = Mix_LoadWAV(robotListoPath);
	if (!robotManufactured) {
        logger->logACerr(("MixLoadWAV: " + std::string(Mix_GetError())));
	}
	vehicleManufactured = Mix_LoadWAV(vehiculoListoPath);
	if (!vehicleManufactured) {
        logger->logACerr("MixLoadWAV: " + std::string(Mix_GetError()));
	}
	muerte = Mix_LoadWAV(avisoMuerte);
	if (!muerte) {
        logger->logACerr("MixLoadWAV: " + std::string(Mix_GetError()));
	}
}

Reproductor::~Reproductor() {
	Mix_FreeChunk(robotManufactured);
	Mix_FreeChunk(vehicleManufactured);
	Mix_FreeChunk(muerte);
}


void Reproductor::reproducirFX(Mix_Chunk *fx) {
	Mix_VolumeMusic(MIX_MAX_VOLUME/2);
	
	if (Mix_PlayChannel(-1,fx,0) == -1) {
        logger->logACerr("MixPlay: " + std::string(Mix_GetError()));
		return;
	}
}

void Reproductor::playCrearVehiculo() {
	reproducirFX(vehicleManufactured);
}

void Reproductor::playCrearRobot() {
	reproducirFX(robotManufactured);
}

void Reproductor::playMuerte() {
	reproducirFX(muerte);
}

