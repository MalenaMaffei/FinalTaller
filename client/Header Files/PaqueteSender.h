#ifndef TPFINAL_PAQUETESENDER_H
#define TPFINAL_PAQUETESENDER_H
#include <condition_variable>
#include "common_Socket.h"
#include "ColaPaquetes.h"
#include "common_Thread.h"
#include "PaqueteDelivery.h"
#include "../ColaSalida.h"

class PaqueteSender : public PaqueteDelivery{
 public:
  PaqueteSender(const Socket &socket,
                ColaSalida &cola,
                std::mutex *m,
                std::condition_variable *cond);
  void run();
 private:
  std::mutex *m;
  std::condition_variable *cond_v;
};

#endif //TPFINAL_PAQUETESENDER_H
