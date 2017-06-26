#ifndef MOVIBLE_H_
#define MOVIBLE_H_

#include "server_Objeto.h"
#include <array>
#include <vector>

class Terreno;

/* Representa a todos los objetos que pueden moverse en el mapa (Unidades, 
 * Municiones).
 */

class Movible : public Objeto {
public:
    Movible(int vida, double ancho, double alto, int velocidad, int tipo);
    Movible(const Movible& orig);
    Movible& operator=(const Movible& orig);
    /* Recibe un destino final, 
     * guarda el destino para luego realizar pasos hacia el.
     */
    virtual void mover (std::array<double,2> destino);
    /* Realiza un paso hacia el destino.
     */
    bool mover(double factorTerreno);
    bool retroceder();
    void setObjetivo(std::string objetivo);
    int getEquipo();
    void setEquipo(int idEquipo);
    /* Define una trayectoria a seguir, cada posición en la trayectoria irá
     * ocupando un destino.
     */
    void setTrayectoria(std::vector< std::array<double,2> > trayectoria);
    
    // Necesario para realizar double dispatch con Terreno, necesario en A*.
    virtual double factorTerrenoEn(Terreno* terreno) = 0;

    virtual void setPosicion(std::array<double,2> posicion) override;
    
    /* En caso de que sea un movible con posibilidad de disparar devuelve el id
     * del objetivo.
     */
    virtual std::string puedeDisparar() = 0;
    /* En caso de que sea un movible que haya podido capturar una bansera, 
     * devuelve true, de lo contrario devuelve false.
     */
    virtual bool obtuvoBandera() = 0;
    
    //Las colisiones se resuelven en los hijos
    virtual void colisionar(Objeto& objeto) = 0;
    virtual void colisionar(Municion& municion) = 0;
    virtual void colisionar(Unidad& personaje) = 0;
    virtual void colisionar(Bloque& bloque) = 0;
    virtual void colisionar(Bandera& bandera) = 0;
    virtual ~Movible();

protected:
    /* Constructor necesario para inicialiar atributos en clases hijas
     */
    Movible (int vida, double ancho, double alto, 
            std::vector<std::array<double,2>> trayectoria,
            std::array<double,2> destino, int idEquipo, int velocidad, 
            std::string objetivo, double distancia, int tipo);
    
    std::vector< std::array<double,2> > trayectoria;
    std::array<double,2> destino;
    std::array<double,2> posicionAnterior;
    int velocidad;
    std::string objetivo;   //id objetivo
    int idEquipo;
    double distancia;
};


#endif /* MOVIBLE_H_ */
