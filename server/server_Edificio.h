
#ifndef EDIFICIO_H
#define EDIFICIO_H

#include "server_Inmovible.h"

class Edificio : public Inmovible{
public:
    Edificio(int vida, double ancho, double alto, int idEquipo, int tipo);
    void colisionar(Municion& municion) override;
    void colisionar(Objeto& objeto) override;
    void colisionar (Unidad& personaje) override;
    void colisionar(Bloque& bloque) override; 
    void colisionar (Edificio& edificio) override;
    void colisionar (Bandera& bandera) override;
    void setFabricacion(int tiempoBase, int territorios, int tipo);
    int debeCrear();
    virtual ~Edificio();
private:
    int tiempoFabricacion;
    int tiempoParaFabricacion;
    int idEquipo;
    int tipo;   //Tipo de objeto a construir
    int territoriosTomados;
    int nivel;
};

#endif /* EDIFICIO_H */

