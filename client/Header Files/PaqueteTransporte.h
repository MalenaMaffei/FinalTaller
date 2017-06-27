#ifndef TPFINAL_PAQUETEDELIVERY_H
#define TPFINAL_PAQUETEDELIVERY_H

#include "common_Thread.h"
#include "common_Socket.h"
#include "common_SocketException.h"
#include "ColaPaquetes.h"
#include "Logger.h"

// Interfaz y funcionalidad comun para PaqueteReceiver y PaqueteSender que
// son los encargados de recibir y mandar paquetes respectivamente.
class PaqueteTransporte  : public Thread{
 public:
  PaqueteTransporte(const Socket &socket, ColaPaquetes &cola);
  virtual void run() = 0;
  void shutdown();
 protected:
  Socket socket;
  ColaPaquetes& cola;
  bool salir;
  Logger* logger = Logger::getInstancia();
};

#endif //TPFINAL_PAQUETEDELIVERY_H
