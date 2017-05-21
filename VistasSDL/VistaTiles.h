#ifndef TPFINAL_VISTATILES_H
#define TPFINAL_VISTATILES_H
#include "Vista.h"

class VistaTiles : public Vista {
 public:
  VistaTiles(SDL_Renderer *gRenderer, const std::string &fileName);
  void mostrar(int x, int y, int clip);

 private:

};

#endif //TPFINAL_VISTATILES_H
