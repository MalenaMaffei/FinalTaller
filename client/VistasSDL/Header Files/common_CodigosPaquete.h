#ifndef TPFINAL_CODIGOSPAQUETE_H
#define TPFINAL_CODIGOSPAQUETE_H

class CodigosPaquete {
 public:
  bool esUnidad(int tipo);
  int unidadesBegin();
  int unidadesEnd();
  bool esRobot(int tipo);
  bool esTanque(int tipo);

  enum colores{
    amarillo = 0,
    azul = 1,
    rojo = 2,
    verde = 3
  };

  enum comandos{
    crear = 0,
    matar = 1,
    mover = 2,
    disparar = 3,
    info = 4
  };

  enum tipos{
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

  enum largos{
    comando = 1,
    id = 3,
    x = 4,
    y = 4,
    delCliente = 1,
    tipo = 2,
    color = 1
  };
};

#endif //TPFINAL_CODIGOSPAQUETE_H
