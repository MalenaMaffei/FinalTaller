#ifndef TPFINAL_PAQUETESENDER_H
#define TPFINAL_PAQUETESENDER_H
#include <condition_variable>
#include "common_Socket.h"
#include "common_Thread.h"
#include "PaqueteTransporte.h"
#include "ColaPaquetes.h"

class PaqueteSender : public PaqueteTransporte{
 public:
  PaqueteSender(const Socket &socket,
                  ColaPaquetes &cola);
  void run();
};

#endif //TPFINAL_PAQUETESENDER_H
