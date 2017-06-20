#ifndef TPFINAL_COLASALIDA_H
#define TPFINAL_COLASALIDA_H

#include <condition_variable>
#include "ColaPaquetes.h"
class ColaSalida : public ColaPaquetes{
 public:
  ColaSalida(std::mutex &m, std::condition_variable &cond_v);
  void encolar(Paquete paquete);
  Paquete desencolar();

 private:
  std::mutex &m;
  std::condition_variable &cond_v;
};

#endif //TPFINAL_COLASALIDA_H
