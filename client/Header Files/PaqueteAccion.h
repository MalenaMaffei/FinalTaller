#ifndef TPFINAL_PAQUETEACCION_H
#define TPFINAL_PAQUETEACCION_H
#include <string>
#include "CodigosPaquete.h"
#include "Paquete.h"

class PaqueteAccion : public Paquete {
 public:
  explicit PaqueteAccion(Paquete paquete);
  PaqueteAccion();
//  Para setear los campos del paquete dependiendo que accion se va a
// realizar, despues se manda al servidor
  void atacar(std::string idAgresor, std::string idAgredido);
  void crear(std::string id, int tipo);
  void pedirInfo(std::string id);
  void mover(std::string id, int x, int y);
//  Para obtener los datos del paquete llegado del servidor
  std::string getId() const;
  int getX();
  int getY();
  int getTipo() const;
  int getColor() const;

 private:
//  El servidor y el cliente tienen una escala distinta de coordenadas, con
// estos métodos se hace la conversión de ida y vuelta
  int coordToServer(double coord);
  int coordToClient(double coord);
//  Los campos tienen que ser de largos especifícos, estos métodos completan
// con el padding correspondiente
  std::string crearCampo(int campo, int contenido);
  std::string crearCampo(int campo, std::string contenidoStr);
};

#endif //TPFINAL_PAQUETE_H
