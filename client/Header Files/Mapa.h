#ifndef TPFINAL_CREADORMAPA_H
#define TPFINAL_CREADORMAPA_H
#include <vector>
#include "PaqueteAccion.h"
#include "Tile.h"
class Mapa {
 public:
  explicit Mapa(SDL_Renderer *gRenderer);
  void crearMapa(PaqueteAccion &paquete);
  void mostrar(Camara &camara);
  virtual ~Mapa();
 private:
  std::vector<Tile> tiles;
  Punto prevCamPos;
  Texture target;
  VistaTiles* vistaTiles;
  SDL_Renderer* gRenderer;
};

#endif //TPFINAL_CREADORMAPA_H
