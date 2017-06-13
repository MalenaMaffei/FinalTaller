#ifndef TPFINAL_PAQUETEDELIVERY_H
#define TPFINAL_PAQUETEDELIVERY_H

#include "common_Thread.h"
#include "ColaPaquetes.h"
#include "common_Socket.h"
class PaqueteDelivery  : public Thread{
 public:
  PaqueteDelivery(const Socket &socket, ColaPaquetes &cola);
  virtual void run() = 0;
  void shutdown();
 protected:
  Socket socket;
  ColaPaquetes& cola;
  bool salir;
};

#endif //TPFINAL_PAQUETEDELIVERY_H
