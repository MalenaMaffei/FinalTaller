#ifndef TPFINAL_MONITORPAQUETES_H
#define TPFINAL_MONITORPAQUETES_H
#include "Paquete.h"
#include <queue>
#include <mutex>
class ColaPaquetes {
 public:
    virtual void encolar(Paquete paquete);
    virtual Paquete desencolar();
    bool isEmpty();
 protected:
  std::queue<Paquete> paquetes;
 private:
  std::mutex m;
};

#endif //TPFINAL_MONITORPAQUETES_H
