#ifndef TPFINAL_PAQUETERECEIVER_H
#define TPFINAL_PAQUETERECEIVER_H

#include "common_Thread.h"
#include "common_Socket.h"
#include "ColaPaquetes.h"
#include "PaqueteDelivery.h"
class PaqueteReceiver : public PaqueteDelivery{
 public:
  PaqueteReceiver(Socket &socket, ColaPaquetes &cola);
  void run();
};

#endif //TPFINAL_PAQUETERECEIVER_H
