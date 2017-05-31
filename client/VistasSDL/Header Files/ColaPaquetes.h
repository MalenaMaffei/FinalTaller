#ifndef TPFINAL_MONITORPAQUETES_H
#define TPFINAL_MONITORPAQUETES_H
#include "common_Paquete.h"
#include <queue>
#include <mutex>
class ColaPaquetes {
 public:
    void encolar(Paquete& paquete);
    Paquete desencolar();
 private:
  std::queue<Paquete> paquetes;
  std::mutex &m;
};

#endif //TPFINAL_MONITORPAQUETES_H
