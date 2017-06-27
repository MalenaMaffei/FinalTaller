
#ifndef MUNICION_H
#define MUNICION_H


#include "server_Objeto.h"
#include "server_Movible.h"
#include "server_Terreno.h"

class Unidad;
class Bloque;
class Bandera;

/* Es un Movible que representa a una munición. Son creadas por el Juego cuando
 * se produce un disparo.
 */

class Municion : public Movible {
public:
    Municion(int vida, double ancho, double alto, int tipo, int danio, 
            int velocidad);
    Municion(const Municion& orig);
    Municion &operator=(Municion &orig);
    Municion(Municion &&orig);
    Municion &operator=(Municion &&orig);
    int getTipo();
    int getDanio();
    double factorTerrenoEn(Terreno* terreno);
    void setAlcance(double alcance);
    void mover (std::array<double,2> destino) override;
    int calcularVelocidad(double factorTerreno) override;
    std::string puedeDisparar() override;
    bool obtuvoBandera() override;
    void colisionar(Municion& municion) override;
    void colisionar(Unidad& personaje) override;
    void colisionar(Bloque& bloque) override;
    void colisionar(Objeto& objeto) override;
    void colisionar(Edificio& edificio) override;
    void colisionar(Bandera& bandera) override;
    bool estaVivo() override;
    virtual ~Municion();
private:
    int danio;
    double alcance;
};

#endif /* MUNICION_H */

