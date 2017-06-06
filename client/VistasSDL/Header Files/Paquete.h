#ifndef TPFINAL_PAQUETE_H
#define TPFINAL_PAQUETE_H
#include <string>
#include "common_CodigosPaquete.h"
class Paquete {
 public:
    void atacar(int idAgresor, int idAgredido);
    void crear(int id, int x, int y, int tipo);
    void pedirInfo(int id);
    void mover(int id, int x, int y);
    std::string & getMensaje();
    void setMensaje(const std::string &mensaje);
    int getId() const;
    int getComando() const;
    int getX() const;
    int getY() const;
    int getTipo() const;
    bool esMio() const;
    int getColor() const;

 protected:
  std::string mensaje;
  CodigosPaquete codigos;
//  TODO nombre horrible
  std::string crearCampo(int campo, int contenido);
};

#endif //TPFINAL_PAQUETE_H
