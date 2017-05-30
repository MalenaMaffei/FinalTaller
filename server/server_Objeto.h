#ifndef OBJETO_H_
#define OBJETO_H_

#include <array>

class Unidad;
class Municion;
class Bloque;

class Objeto {
    public:
        Objeto();
        Objeto(int vida, double ancho, double alto);
        virtual bool colisiona(Objeto& objeto);
        virtual void colisionar(Municion& municion) = 0;
        virtual void colisionar(Unidad& personaje) = 0;
        virtual void colisionar(Bloque& bloque) = 0;
        virtual void colisionar(Objeto& objeto) = 0;
        int getVida();
        bool estaVivo();
        std::array<double, 2> getPosicion();
        virtual void setPosicion (std::array<double,2> posicion);
        bool recibirDanio(int danio);
        virtual ~Objeto();
    protected:
        int vida;
        double ancho;
        double alto;
        std::array<double, 2> posicion;
};

#endif /* OBJETO_H_ */
