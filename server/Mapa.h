#ifndef SERVER_MAPA_H_
#define SERVER_MAPA_H_

#include <vector>
#include "Casillero.h"
#include <array>
#include "Movible.h"
#include <string>

/* Representa el mapa, cuenta con una matriz de Casilleros, junto con las 
 * dimensiones del mapa. 
 * El mapa se inicializa a partir de un archivo provisto por el generador de 
 * mapa.
 */

class Mapa {
public:
    /* Instancia un mapa a partir del mapa presente en el archivo especificado.
     */
    explicit Mapa(const std::string& archivoMapa);
    virtual ~Mapa();
    /* Devuelve el factor de terreno de una posición en particular, para el 
     * movible pasado por parámetro.
     */
    double obtenerFactorTerreno(std::array<int,2> posicion, Movible* movible);
    int obtenerDimensionX();
    int obtenerDimensionY();
    /* Devuelve el contenido del mapa en el formato de un string para poder ser
     * enviado a los clientes.
     */
    std::string obtenerMensajeMapa();
    /* Devuelve el tipo de terreno de la posición especificada.
     */
    int obtenerTipo(std::array<int,2> posicion);
private:
    unsigned int dimensionX;
    unsigned int dimensionY;
    std::vector< std::vector<Casillero> > mapa;
};

#endif /* SERVER_MAPA_H_ */
