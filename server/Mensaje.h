#ifndef MENSAJE_H
#define MENSAJE_H

#include <string>
#include "server_Mapa.h"
#include "server_Objeto.h"
#include "server_Movible.h"
#include "server_Unidad.h"
#include "FabricaUnidades.h"
#include <array>
#include <vector>

class Jugador;

/* Contenedor de mensajes, los mensajes a recibir y o enviar se almacenan 
 * dentro del modelo en instancias de la clase Mensaje.
 */

class Mensaje {
public:
    Mensaje();
    /* Instancia un Mensaje con un mensaje (string) y un id.
     */
    Mensaje(std::string mensaje, int id);
    /* Inicializa un Mensaje con la información del equipo del Jugador.
     */
    void mensajeDeEquipo(Jugador* jugador);
    /* Inicializa un Mensaje con la información del Mapa.
     */
    void mensajeDeMapa(Mapa& mapa);
    /* Inicializa un Mensaje con la información necesaria del Objeto creado.
     */
    void mensajeDeCrear(Objeto* objeto, std::string id, int equipo);
    /* Inicializa un Mensaje con la información del id del Objeto muerto. 
     */
    void mensajeDeMatar(std::string id);
    /* Inicializa un Mensaje con la información necesaria del Movible que se 
     * movió.
     */
    void mensajeDeMover(Movible* movible, std::string id);
    /* Inicializa un Mensaje con la información necesaria del disparo ocurrido.
     */
    void mensajeDeDisparar(std::string id, Objeto* objetivo);
    /* Inicializa un Mensaje con la información necesaria de la Unidad 
     * solicitada.
     */
    void mensajeDeInfoUnidad(Unidad* unidad, std::string id, int dst);
    /* Inicializa un Mensaje con la información necesaria del Edificio 
     * solicitado.
     */
    void mensajeDeInfoFabrica(Edificio* edificio, std::string id, 
                                FabricaUnidades& fabricaUnidades,
                                int dst, int territorios);
    /* Inicializa un Mensaje con la información de que el Jugador con el id
     * especifiado perdió.
     */
    void mensajeDePerdedor(int id);
    /* Inicializa un Mensaje con la información de que el Jugador con el id 
     * especificado perdió.
     */
    void mensajeDeGanador(int id);
    /* Inicializa un Mensaje con la información de que se deben desconectar 
     * todos los jugadores.
     */
    void mensajeDeSalir();
    /* Devuelve el mensaje propiamente dicho (string).
     */
    std::string getMensaje();
    /* Devuelve el id de destinatario.
     */
    int getId();
    virtual ~Mensaje();
private:
    /* El propio mensaje a ser enviado a los clientes.
     */
    std::string mensaje;
    /* El id del jugador que debe recibir la información, o TODOS (definido en 
     * "constantes.h") en caso de que deba ser enviada a todos los jugadores.
     */
    int id;
};

#endif /* MENSAJE_H */

