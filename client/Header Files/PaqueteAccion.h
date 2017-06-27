#ifndef TPFINAL_PAQUETEACCION_H
#define TPFINAL_PAQUETEACCION_H
#include <string>
#include "common_CodigosPaquete.h"
#include "Paquete.h"

class PaqueteAccion : public Paquete {
 public:
  PaqueteAccion(Paquete paquete);
  PaqueteAccion();
  void atacar(std::string idAgresor, std::string idAgredido);
  void crear(std::string id, int tipo);
  void pedirInfo(std::string id);
  void mover(std::string id, int x, int y);
  std::string getId() const;
  int getX();
  int getY();
  int getTipo() const;
  int getColor() const;

 private:
  int coordToServer(double coord);
  int coordToClient(double coord);
  std::string crearCampo(int campo, int contenido);
  std::string crearCampo(int campo, std::string contenidoStr);
};

#endif //TPFINAL_PAQUETE_H
