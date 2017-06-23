#ifndef TPFINAL_CREADORMAPA_H
#define TPFINAL_CREADORMAPA_H
#include <vector>
#include "Paquete.h"
#include "Tile.h"
class Mapa {
 public:
  Mapa(SDL_Renderer *gRenderer);
  void crearMapa(Paquete &paquete);
  void mostrar(Camara &camara);
 private:
  std::vector<Tile> tiles;
  Punto prevCamPos;
  Texture target;
  VistaTiles* vistaTiles;
  SDL_Renderer* gRenderer;
};

#endif //TPFINAL_CREADORMAPA_H
