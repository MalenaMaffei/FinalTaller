#ifndef TPFINAL_PAQUETE_H
#define TPFINAL_PAQUETE_H
#include <string>
#include <map>
#include "Vista.h"
#include "VistaDireccionada.h"
#include "Elemento.h"
#include "ElementoUnidad.h"
class PaqueteEntrada {
 public:
  PaqueteEntrada(std::string mensaje);
//  PaqueteEntrada(int id, int comando, int x, int y, int tipo, bool esMio, int color);
  int getId() const;
  int getComando() const;
  int getX() const;
  int getY() const;
  int getTipo() const;
  bool isEsMio() const;
  int getColor() const;

 private:

  enum comando{
    crear = 0,
    matar = 1,
    mover = 2,
    disparar = 3
  };

  enum tipo{
      roca = 0,
      puente = 1,
      bandera = 2,
      fuerte = 3,
      fabricaRobot = 4,
      fabricaVehiculo = 5,
      grunt = 6,
      psycho = 7,
      tough = 8,
      pyro = 9,
      sniper = 10,
      laser = 11,
      jeep = 12,
      light = 13,
      medium = 14,
      heavy = 15,
      missile = 16
  };

  int id;
  int comando;
  int x;
  int y;
  int tipo;
  bool esMio;
  int color;

};

#endif //TPFINAL_PAQUETE_H
