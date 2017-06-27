#ifndef OBJETO_H_
#define OBJETO_H_

#include <array>

class Unidad;
class Municion;
class Bloque;
class Edificio;
class Bandera;

/* Representa todo objeto presente en el Juego, tanto Movibles como Inmvoibles
 * heredan de objeto.
 */

class Objeto {
public:
    Objeto();
    Objeto(int vida, double ancho, double alto,int tipo);
    int getTipo();

    //Las colisiones se resuelven en los hijos
    virtual bool colisiona(Objeto& objeto);
    virtual void colisionar(Municion& municion) = 0;
    virtual void colisionar(Unidad& personaje) = 0;
    virtual void colisionar(Bloque& bloque) = 0;
    virtual void colisionar(Objeto& objeto) = 0;
    virtual void colisionar(Edificio& edificio) = 0;
    virtual void colisionar(Bandera& bandera) = 0;
    void setId(std::string id);
    std::string getId();
    int getPorcentajeVida();
    int getVida();
    double distanciaCuadrada(Objeto* objeto);
    virtual bool estaVivo();
    std::array<double, 2> getPosicion();
    std::array<double, 2> getPosicionCentral();
    virtual void setPosicion (std::array<double,2> posicion);
    bool recibirDanio(int danio);
    virtual ~Objeto();
protected:
    std::string id;
    int vidaTotal;
    int vida;
    double ancho;
    double alto;
    std::array<double, 2> posicion;
    int tipo;
};

#endif /* OBJETO_H_ */
