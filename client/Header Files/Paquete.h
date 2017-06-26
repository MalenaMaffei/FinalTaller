#ifndef TPFINAL_PAQUETE_H
#define TPFINAL_PAQUETE_H
#include <string>
#include "common_CodigosPaquete.h"

class Paquete {
 public:
  Paquete();
  std::string & getMensaje();
  void setMensaje(const std::string &mensaje);
  int getComando() const;
 protected:
  std::string mensaje;
  CodigosPaquete codigos;
  int toInt(std::string str) const;
};

#endif //TPFINAL_PAQUETE_H
