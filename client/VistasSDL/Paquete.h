#ifndef TPFINAL_PAQUETE_H
#define TPFINAL_PAQUETE_H
#include <string>
class Paquete {
 public:
    void atacar(int idAgresor, int idAgredido);
    void crear(int id, int x, int y, int tipo);
    void pedirInfo(int id);
    void mover(int id, int x, int y);
    std::string & getMensaje();
    void setMensaje(const std::string &mensaje);

 protected:
  std::string mensaje;
//  TODO nombre horrible
  std::string crearCampo(int campo, int contenido);
};

#endif //TPFINAL_PAQUETE_H
