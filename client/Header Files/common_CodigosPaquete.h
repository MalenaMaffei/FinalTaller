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
    verde = 3,
    gris = 4
  };

  enum comandos{
    crear = 0,
    matar = 1,
    mover = 2,
    disparar = 3,
    infoUnidad = 4,
    mapa = 5,
    equipo = 6,
    infoFabrica = 7
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
    x = 5,
    y = 5,
    tipo = 2,
    color = 1
  };

  enum posiciones{
    posComando = 0,
    posId = 1,
    posX = 4,
    posY = 9,
    posTipo = 14,
    posColor = 16
  };
};

#endif //TPFINAL_CODIGOSPAQUETE_H
