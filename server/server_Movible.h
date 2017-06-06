#ifndef MOVIBLE_H_
#define MOVIBLE_H_

#include "server_Objeto.h"
#include <array>
#include <vector>

class Movible : public Objeto {
    public:
        Movible(int vida, double ancho, double alto, int velocidad, int tipo);
        Movible(const Movible& orig);
        Movible& operator=(const Movible& orig);
        /* Recibe un destino final y realiza un paso hacia el destino, 
         * guarda el destino para luego realizar pasos hacia el.
         */
        bool mover (std::array<double,2> destino);
        /* Realiza un paso hacia el destino.
         */
        bool mover(double factorTerreno);
        bool retroceder();
        void setObjetivo(std::string objetivo);
        int getEquipo();
        void setEquipo(int idEquipo);
        virtual void setPosicion(std::array<double,2> posicion) override;
        virtual bool superaMaxDistancia() = 0;
        virtual std::string puedeDisparar() = 0;
        virtual bool obtuvoBandera() = 0;
        virtual void colisionar(Objeto& objeto) = 0;
        virtual void colisionar(Municion& municion) = 0;
        virtual void colisionar(Unidad& personaje) = 0;
        virtual void colisionar(Bloque& bloque) = 0;
        virtual void colisionar(Bandera& bandera) = 0;
        virtual ~Movible();

    protected:
        Movible (int vida, double ancho, double alto, 
                std::vector<std::array<int,2>> trayectoria,
                std::array<double,2> destino, int idEquipo, int velocidad, 
                std::string objetivo, double distancia, int tipo);
        std::string objetivo;   //id objetivo
        std::vector<std::array<int,2>> trayectoria;
        std::array<double,2> destino;
        std::array<double,2> posicionAnterior;
        int velocidad;
        int idEquipo;
        double distancia;
};


#endif /* MOVIBLE_H_ */
