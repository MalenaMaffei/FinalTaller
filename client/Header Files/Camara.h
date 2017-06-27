#ifndef TPFINAL_CAMARA_H
#define TPFINAL_CAMARA_H
#include <SDL2/SDL.h>
#include "Texture.h"
#include "constantes.h"
#include "Punto.h"
#include "Rect.h"
class Camara {
 public:
  static const int CAM_VEL = 700;
  explicit Camara();

//  Chequea si el evento es w, a, s, d y setea direccion y velocidad del
// movimiento
  void handleEvent(SDL_Event& e);

//  Mueve la camara con la velocidad y direccion seteadas por handleEvent.
  void mover(float timeStep);

  Punto getPos();

//  Chequea si el Rect pasado esta dentro de la camara.
  bool estaEnfocado(Rect b);

  void setCentro(const Punto &centro);

 private:
//  REctangulo que representa a la camara
    Rect camRect;
//  Centro del mapa, al que la camara vuelve a pedido del usuario.
    Punto centro;
    float velX, velY;
  //    Centra a al camara. El centro es la ubicación del fuerte del jugador
    void centrar();
//  Ajusta la ubicación de camRect para que no se vaya de la pantalla.
    void ajustar();
};

#endif //TPFINAL_CAMARA_H
