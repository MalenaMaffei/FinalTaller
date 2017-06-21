#ifndef TPFINAL_CREADORMAPA_H
#define TPFINAL_CREADORMAPA_H
#include <vector>
#include "Paquete.h"
#include "Tile.h"
class Mapa {
 public:
  Mapa();
  void crearMapa(Paquete &paquete, VistaTiles &tilesTexture);
  void mostrar(Camara &camara);
 private:
  std::vector<Tile> tiles;
  Punto prevCamPos;
};

#endif //TPFINAL_CREADORMAPA_H
