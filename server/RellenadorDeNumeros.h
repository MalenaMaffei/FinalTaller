#ifndef RELLENADORDENUMEROS_H
#define RELLENADORDENUMEROS_H

#include <string>

/* Tanto los campos de los mensajes intercambiados, como los ids devueltos por 
 * el ManejadorIDs, tienen un largo preestablecido. El RellenadorDeNumeros
 * se encarga de rellenar los numeros con 0 en caso de que tenga menos dígitos
 * de los esperados.
 */

class RellenadorDeNumeros {
public:
    RellenadorDeNumeros();
    std::string rellenar(int n, int len);
    virtual ~RellenadorDeNumeros();
private:

};

#endif /* RELLENADORDENUMEROS_H */

