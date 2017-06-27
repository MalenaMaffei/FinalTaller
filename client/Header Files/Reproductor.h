#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include <string>
#include <SDL_mixer.h>
#include "Logger.h"

class Reproductor {
public:
    Reproductor();
    void playMuerte();
    void playCrearRobot();
    void playCrearVehiculo();
    ~Reproductor();
private:
  Mix_Chunk *robotManufactured;
  Mix_Chunk *vehicleManufactured;
  Mix_Chunk *muerte;
  Logger* logger = Logger::getInstancia();
  void reproducirFX(Mix_Chunk *fx);
};

#endif /* REPRODUCTOR_H */

