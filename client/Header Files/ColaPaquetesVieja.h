#ifndef TPFINAL_MONITORPAQUETES_H
#define TPFINAL_MONITORPAQUETES_H
#include "Paquete.h"
#include <queue>
#include <mutex>
class ColaPaquetesVieja {
 public:
    ColaPaquetesVieja();
    virtual void encolar(Paquete paquete);
    virtual Paquete desencolar();
    bool isEmpty();
    bool estaCerrada();
    virtual void cerrar();
 protected:
  std::queue<Paquete> paquetes;
  bool salir;
 private:
  std::mutex m;
};

#endif //TPFINAL_MONITORPAQUETES_H
