#ifndef TPFINAL_PAQUETE_H
#define TPFINAL_PAQUETE_H
#include <string>
#include "CodigosPaquete.h"

class Paquete {
 public:
  Paquete();
  std::string & getMensaje();
  void setMensaje(const std::string &mensaje);
  int getComando() const;
 protected:
  std::string mensaje;
  CodigosPaquete codigos;
//  Wrapper para cuando stoi falle, de un mensaje mas descriptivo
  int toInt(std::string str) const;
};

#endif //TPFINAL_PAQUETE_H
