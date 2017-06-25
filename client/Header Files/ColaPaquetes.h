#ifndef TPFINAL_MONITORPAQUETES_H
#define TPFINAL_MONITORPAQUETES_H
#include "Paquete.h"
#include <queue>
#include <mutex>
class ColaPaquetes {
 public:
    ColaPaquetes();
    virtual void encolar(Paquete paquete);
    virtual Paquete desencolar();
    bool isEmpty();
    bool estaCerrada();
    virtual void cerrar();
 protected:
  std::queue<Paquete> paquetes;
  bool salir;
 private:
  std::mutex mutex;
};

#endif //TPFINAL_MONITORPAQUETES_H
