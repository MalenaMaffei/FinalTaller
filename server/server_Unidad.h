#ifndef UNIDAD_H
#define UNIDAD_H

#include "server_Objeto.h"
#include "server_Movible.h"
#include "server_Municion.h"

#include "server_Bloque.h"

/* Estados posibles de una unidad
 */

enum estado {
    DISPARAR,
    REPOSO
};

/* Es un Movible del cual heredan Robot y Vehiculo.
 */

class Unidad : public Movible {
public:
    Unidad(int vida, double ancho, double alto, int frecuenciaDisparo,
                int alcance, int velocidad, int tipo, int armamento);
    void dispararA(std::string objetivo);
    int getArmamento();
    std::string getBandera();
    std::string puedeDisparar() override;
    bool obtuvoBandera() override;
    void colisionar(Municion& municion) override;
    void colisionar(Objeto& objeto) override;
    void colisionar (Unidad& personaje) override;
    void colisionar(Bloque& bloque) override;
    void colisionar(Edificio& edificio) override;
    void colisionar (Bandera& bandera) override;
    virtual ~Unidad();
private:
    int frecuenciaDisparo;
    int alcance;
    int estado;
    int tiempoADisparo;
    std::string bandera;
    int armamento;
};

#endif /* UNIDAD_H */

