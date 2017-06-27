#ifndef TPFINAL_PAQUETEFABRICA_H
#define TPFINAL_PAQUETEFABRICA_H
#include <string>
#include <vector>
#include <map>
#include "Paquete.h"
class PaqueteFabrica : public  Paquete{
 public:
  explicit PaqueteFabrica(const std::string &mensaje);
  std::string getId();
  int getTipoFabrica();
  std::string getVidaFabrica();
  std::map<int, std::string>  getConstruibles();
  bool estaConstruyendo();
  int tipoEnConstruccion();
  float porcentajeConstruido();
  int getCantConstuibles();
//  const std::string &getMensaje() const;

 private:
  int getOffsetConstruibles();
  enum largos{
    comando = 1,
    id = 3,
    tipo = 2,
    vida = 3,
    cant = 2,
    tiempo = 4,
    isConstruyendo = 1,
    porConstruido = 3
  };
  enum posiciones{
    posComando = 0,
    posId = 1,
    posTipoFabrica = 4,
    posVida = 6,
    posCant = 9
  };
  std::string mensaje;
};

#endif //TPFINAL_PAQUETEFABRICA_H
