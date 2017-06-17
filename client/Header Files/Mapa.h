#ifndef TPFINAL_CREADORMAPA_H
#define TPFINAL_CREADORMAPA_H
#include <vector>
#include "Paquete.h"
#include "Tile.h"
class Mapa {
 public:
  void crearMapa(Paquete &paquete, VistaTiles &tilesTexture);
  void mostrar(Camara &camara);
 private:
  std::vector<Tile> tiles;
};

#endif //TPFINAL_CREADORMAPA_H
