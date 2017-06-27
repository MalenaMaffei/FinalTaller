#ifndef TPFINAL_PAQUETEUNIDAD_H
#define TPFINAL_PAQUETEUNIDAD_H
#include <string>
#include "common_CodigosPaquete.h"
#include "Paquete.h"
class PaqueteUnidad : public Paquete {
 public:
  explicit PaqueteUnidad(const std::string &mensaje);
  int getTipo();
  float getVida();
  int getColor();
 private:
//  CodigosPaquete codigos;
//  std::string mensaje;
  enum{
    posTipo = 4,
    posVida = 6,
    largoVida = 3,
    posColor = 9
  };
};

#endif //TPFINAL_PAQUETEUNIDAD_H
