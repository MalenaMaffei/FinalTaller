
#ifndef BLOQUE_H
#define BLOQUE_H

#include "Inmovible.h"
#include "Unidad.h"
#include "Municion.h"
#include "Bandera.h"
#include "Edificio.h"

/* Es un Inmovible que representa a un bloque.
 */

class Bloque : public Inmovible {
public:
    Bloque(int vida, double ancho, double alto, int tipo);
    void colisionar(Municion& municion) override;
    void colisionar(Objeto& objeto) override;
    void colisionar(Unidad& personaje) override;
    void colisionar(Bloque& bloque) override; 
    void colisionar(Bandera& bandera) override; 
    void colisionar(Edificio& edificio) override;
    virtual ~Bloque();
private:
};

#endif /* BLOQUE_H */

