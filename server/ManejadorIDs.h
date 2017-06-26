#ifndef MANEJADORIDS_H
#define MANEJADORIDS_H

#include <string>
#include "RellenadorDeNumeros.h"

/* Se encarga de administrar los ids de los distintos objetos presentes en el 
 * Juego. Cada vez que se crea un Objeto en el Juego, se le pide un ID a esta
 * clase.
 */

class ManejadorIDs {
public:
    ManejadorIDs();
    std::string getIDMunicion();
    std::string getIDEdificio();
    std::string getIDMovible();
    std::string getIDInmovible();
    virtual ~ManejadorIDs();
private:
    RellenadorDeNumeros rellenador;
    int proximoIDMovible;
    int proximoIDEdificio;
    int proximoIDInmovible;
    int proximoIDMunicion;
};

#endif /* MANEJADORIDS_H */

