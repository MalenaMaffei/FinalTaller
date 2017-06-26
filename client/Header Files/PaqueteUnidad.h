#ifndef TPFINAL_PAQUETEUNIDAD_H
#define TPFINAL_PAQUETEUNIDAD_H
#include <string>
#include "common_CodigosPaquete.h"
class PaqueteUnidad {
 public:
  explicit PaqueteUnidad(const std::string &mensaje);
  int getTipo();
  float getVida();
  int getColor();
 private:
  CodigosPaquete codigos;
  std::string mensaje;
};

#endif //TPFINAL_PAQUETEUNIDAD_H