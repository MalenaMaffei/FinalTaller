#ifndef TPFINAL_CREADORMAPA_H
#define TPFINAL_CREADORMAPA_H
#include <vector>
#include "Header Files/Paquete.h"
#include "Header Files/Tile.h"
class CreadorMapa {
 public:
  void crearMapa(Paquete &paquete,
                   std::vector<Tile> &tiles,
                   VistaTiles &tilesTexture);
};

#endif //TPFINAL_CREADORMAPA_H
