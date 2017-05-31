#ifndef TPFINAL_CODIGOSPAQUETE_H
#define TPFINAL_CODIGOSPAQUETE_H

class CodigosPaquete {
 public:
  bool esUnidad(int tipo);
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
};

#endif //TPFINAL_CODIGOSPAQUETE_H
