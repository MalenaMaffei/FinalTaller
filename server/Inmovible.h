#ifndef INMOVIBLE_H
#define INMOVIBLE_H

#include "Objeto.h"

/* Representa a todos los objetos que no pueden moverse en el mapa (Edificio, 
 * Bloque, Bandera).
 */

class Inmovible : public Objeto{
    public:
        Inmovible(int vida, double ancho, double alto, int tipo);
        Inmovible(const Inmovible& orig);
        Inmovible& operator=(const Inmovible& orig);
        
        // Las colisiones se resuelven en los hijos
        virtual void colisionar(Objeto& objeto) = 0;
        virtual void colisionar(Municion& municion) = 0;
        virtual void colisionar(Unidad& personaje) = 0;
        virtual void colisionar(Bloque& bloque) = 0;                
        virtual ~Inmovible();
    private:
};

#endif /* INMOVIBLE_H */

