
#ifndef SERVER_CASILLERO_H
#define SERVER_CASILLERO_H

#include <tuple>
#include "server_Terreno.h"
#include "server_Movible.h"

class Casillero {
    public:
        Casillero (Terreno &&terreno);
        Casillero(const Casillero& orig);
        Casillero& operator=(const Casillero& orig);
        bool estaOcupado();
        double getFactorTerreno(Movible* movible);
        int getTipoTerreno();
        virtual ~Casillero();

    private:
        bool ocupado;
        Terreno terreno;

};

#endif /* SERVER_CASILLERO_H */