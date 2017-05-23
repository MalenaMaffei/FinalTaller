#ifndef SERVER_JUEGO_H
#define SERVER_JUEGO_H

#include "a*/server_Mapa.h"

class server_Juego {
public:
    server_Juego();
    server_Juego(const server_Juego& orig);
    virtual ~server_Juego();
private:
    Mapa mapa;
};

#endif /* SERVER_JUEGO_H */

