#ifndef TPFINAL_PAQUETE_H
#define TPFINAL_PAQUETE_H
#include <string>
#include "common_CodigosPaquete.h"
class Paquete {
 public:
  void atacar(std::string idAgresor, std::string idAgredido);
  void crear(std::string id, int x, int y, int tipo);
  void pedirInfo(std::string id);
  void mover(std::string id, int x, int y);
  std::string & getMensaje();
  void setMensaje(const std::string &mensaje);
  std::string getId() const;
  int getComando() const;
  int getX();
  int getY();
  int getTipo() const;
  int getColor() const;

 protected:
  int coordToServer(double coord);
  int coordToClient(double coord);
  std::string mensaje;
  CodigosPaquete codigos;
//  TODO nombre horrible
  std::string crearCampo(int campo, int contenido);
  std::string crearCampo(int campo, std::string contenidoStr);
};

#endif //TPFINAL_PAQUETE_H
