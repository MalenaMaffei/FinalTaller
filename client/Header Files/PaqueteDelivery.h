#ifndef TPFINAL_PAQUETEDELIVERY_H
#define TPFINAL_PAQUETEDELIVERY_H

#include "common_Thread.h"
#include "ColaPaquetes.h"
#include "common_Socket.h"
#include "common_SocketException.h"

// Interfaz y funcionalidad comun para PaqueteReceiver y PaqueteSender que
// son los encargados de recibir y mandar paquetes respectivamente.
class PaqueteDelivery  : public Thread{
 public:
  PaqueteDelivery(const Socket &socket, ColaPaquetes &cola);
  virtual void run() = 0;
  void shutdown();
 protected:
  Socket socket;
  ColaPaquetes& cola;
  bool salir;
  void displayError(SocketException &e);
};

#endif //TPFINAL_PAQUETEDELIVERY_H
