
#ifndef EDIFICIO_H
#define EDIFICIO_H

#include "server_Inmovible.h"

class Edificio : public Inmovible{
public:
    Edificio(int vida, double ancho, double alto, int equipo, int tipo);
    void colisionar(Municion& municion) override;
    void colisionar(Objeto& objeto) override;
    void colisionar (Unidad& personaje) override;
    void colisionar(Bloque& bloque) override; 
    void colisionar (Edificio& edificio) override;
    void colisionar (Bandera& bandera) override;
    void setEquipo(int equipo);
    int getEquipo();
    void setFabricacion(int tiempoBase, int territorios, int tipo);
    int getPorcentajeConstruccion();
    int getTipoCreando();
    int getNivel();
    bool estaCreando();
    int debeCrear();
    virtual ~Edificio();
private:
    int tiempoFabricacion;
    int tiempoParaFabricacion;
    int equipo;
    int tipoCreando;   //Tipo de objeto a construir
    int territoriosTomados;
    int construccionesRealizadas; // Cuento la cantidad de construcciones 
                                  // y a partir de eso calculo el nivel
    int nivel; // Cada 2 personajes construidos aumento el nivel
};

#endif /* EDIFICIO_H */

