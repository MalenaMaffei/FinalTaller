#ifndef BANDERA_H
#define BANDERA_H

#include "Inmovible.h"

/* Es un Inmovible que representa a una bandera.
 */

class Bandera : public Inmovible {
public:
    Bandera(double ancho, double alto, int tipo);
    bool estaVivo() override;
    void colisionar(Municion& municion) override;
    void colisionar(Objeto& objeto) override;
    void colisionar(Unidad& personaje) override;
    void colisionar(Bloque& bloque) override; 
    void colisionar(Bandera& bandera) override; 
    void colisionar(Edificio& edificio) override; 
    void setEquipo(int equipo);
    int getEquipoAnterior();
    int getEquipo();
    virtual ~Bandera();
private:
    /* Las banderas tienen un equipo, inicialmente tienen como equipo 
     * SIN_EQUIPO (definido en "constantes.h").
     */
    int idEquipo;
    int idEquipoAnterior;
};

#endif /* BANDERA_H */

