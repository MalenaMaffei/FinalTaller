#ifndef SERVER_AESTRELLA_H_
#define SERVER_AESTRELLA_H_

#include "server_Casillero.h"
#include "server_Mapa.h"
#include <array>
#include <vector>
#include <map>

/* Algoritmo A* que genera caminos para un Movible en un Mapa.
 */

class AEstrella {
public:
    AEstrella(const Mapa& mapa);
    std::vector < std::array<double,2> > 
        getRecorrido(Movible* movible,
                        const std::array<int,2>& inicio, 
                        const std::array<int,2>& destino);        
    virtual ~AEstrella();


private:
    Mapa mapa;
};

#endif /* SERVER_AESTRELLA_H_ */
