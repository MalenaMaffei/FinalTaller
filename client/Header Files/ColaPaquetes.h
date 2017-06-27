#ifndef TPFINAL_COLASALIDA_H
#define TPFINAL_COLASALIDA_H
#include "Paquete.h"
#include <queue>
#include <condition_variable>
class ColaPaquetes {
 public:
  ColaPaquetes();
  void encolar(Paquete paquete);
//  Usa una condition variable para bloquear al invocante hasta que se haya
// encolado algo
  Paquete desencolarBloqueante();
  Paquete desencolar();
//  Cierra la cola
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
