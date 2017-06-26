#ifndef TPFINAL_COLASALIDA_H
#define TPFINAL_COLASALIDA_H
#include "Paquete.h"
#include <queue>
#include <condition_variable>
class ColaPaquetes {
 public:
  ColaPaquetes();
  void encolar(Paquete paquete);
  Paquete desencolarBloqueante();
  Paquete desencolar();
  void cerrar();
  bool isEmpty();
  bool estaCerrada();
 private:
  std::queue<Paquete> paquetes;
  bool salir;
  std::mutex m;
  std::condition_variable cond_v;
};

#endif //TPFINAL_COLASALIDA_H
