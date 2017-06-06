#ifndef SERVER_MAPA_H_
#define SERVER_MAPA_H_

#include <vector>
#include "server_Casillero.h"
#include <array>

class Mapa {
    public:
        Mapa(const std::string& archivoMapa);
        virtual ~Mapa();
        double obtenerFactorTerreno(std::array<int,2> posicion);
        int obtenerDimensionX();
        int obtenerDimensionY();
    private:
        unsigned int dimensionX;
        unsigned int dimensionY;
        std::vector< std::vector<Casillero> > mapa;

};

#endif /* SERVER_MAPA_H_ */
