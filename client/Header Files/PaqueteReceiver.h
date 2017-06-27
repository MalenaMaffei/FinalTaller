#ifndef TPFINAL_PAQUETERECEIVER_H
#define TPFINAL_PAQUETERECEIVER_H

#include "common_Thread.h"
#include "common_Socket.h"
#include "PaqueteTransporte.h"
class PaqueteReceiver : public PaqueteTransporte{
 public:
  PaqueteReceiver(const Socket &socket, ColaPaquetes &cola);
  void run();
};

#endif //TPFINAL_PAQUETERECEIVER_H
