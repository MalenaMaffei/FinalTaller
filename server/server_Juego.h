#ifndef SERVER_JUEGO_H
#define SERVER_JUEGO_H

#include "a*/server_Mapa.h"

class Juego {
public:
    Juego();
    Juego(const server_Juego& orig);
    virtual ~Juego();
private:
    Mapa mapa;
    
};

#endif /* SERVER_JUEGO_H */

