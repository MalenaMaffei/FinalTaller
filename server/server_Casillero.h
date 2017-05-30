
#ifndef SERVER_CASILLERO_H
#define SERVER_CASILLERO_H

#include <tuple>
#include "server_Terreno.h"

class Casillero {
    public:
        Casillero (Terreno &&terreno);
        Casillero(const Casillero& orig);
        Casillero& operator=(const Casillero& orig);
        bool estaOcupado();
        double getFactorTerreno();
        virtual ~Casillero();

    private:
        bool ocupado;
        Terreno terreno;

};

#endif /* SERVER_CASILLERO_H */