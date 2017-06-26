#ifndef TPFINAL_PAQUETESENDER_H
#define TPFINAL_PAQUETESENDER_H
#include <condition_variable>
#include "common_Socket.h"
#include "common_Thread.h"
#include "PaqueteDelivery.h"
#include "ColaPaquetes.h"

class PaqueteSender : public PaqueteDelivery{
 public:
  PaqueteSender(const Socket &socket,
                  ColaPaquetes &cola);
  void run();
};

#endif //TPFINAL_PAQUETESENDER_H
