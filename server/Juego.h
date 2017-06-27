#ifndef JUEGO_H
#define JUEGO_H

#include "ManejadorIDs.h"
#include "FabricaInmovibles.h"
#include "FabricaEdificios.h"
#include "FabricaUnidades.h"
#include "FabricaMuniciones.h"
#include "Mapa.h"
#include "Movible.h"
#include "Inmovible.h"
#include <vector>
#include <map>
#include "common_Socket.h"
#include "common_Thread.h"
#include <queue>
#include <mutex>
#include <condition_variable>
#include <pthread.h>
#include "Jugador.h"
#include "ColaMensajes.h"
#include "BoolProtected.h"
#include <tinyxml2.h>
#include <string>

/* Es la clase principal, en ella se almacena el modelo. Hereda de Thread ya 
 * que en un Thread se corre el ciclo principal.
 * Intercambia mensajes con los clientes mediante los jugadores.
 */

class Juego : public Thread {
public:
    /* Se inicializa un Juego, con una colaDeRecibidos (en donde se 
     * intercambiarán los mensajes enviados por los clientes), y una lista de
     * jugadores. 
     * Al inicializarse el juego se definen los equipos de los jugadores, 
     * se envían los mapas, y se inicializa la configuración inicial del juego.
     */
    Juego(ColaMensajes& colaDeRecibidos, std::vector<Jugador*>& jugadores);
    /* Mueve los movibles que deben cambiar su posición. Encola los mensajes 
     * correspondientes en la colaDeEnviados.
     */
    void moverUnidades();
    /* Esta función debe ser llamada cuando se desea finalizar el ciclo de 
     * juego.
     */
    void finalizar();
    /* Verifica si el juego ya fue finalizado.
     */
    bool yaFinalizo();
    /* Verifica que haya un solo jugador activo.
     */
    bool hayGanador();
    /* Chequea las colisiones de los movibles con el resto de los objetos del 
     * mapa (inmovibles, edificios, movibles). En caso de colisión los 
     * Objetos reacción según lo esperado.
     * En caso de que una Unidad haya obtenido una Bandera, se actualiza el 
     * contador de banderas por equipo.
     * Encola los mensajes correspondientes en la colaDeEnviados.
     */
    void chequearColisiones();
    /* Elimina los Objetos muertos. Encola los mensajes correspondientes 
     * en la colaDeEnviados.
     */
    void eliminarMuertos();
    /* Actualiza los disparos, en caso de que haya un Movible con un objetivo,
     * crea una bala y comienza a disparar. Encola los mensajes 
     * correspondientes en la colaDeEnviados.
     */
    void actualizarDisparos();
    /* Actualiza los edificios, en caso de que haya un Edificio que haya 
     * cumplido el tiempo de creación, crea una Unidad. Encola los mensajes 
     * correspondientes en la colaDeEnviados.
     */
    void actualizarEdificios();
    /* Desencola de la colaDeRecibidos los mensajes y realiza las acciones
     * correspondientes.
     */    
    void actualizarRecibidos();
    /* Envia todos los mensajes que fueron encolados.
     */
    void enviarMensajesEncolados();
    /* Ciclo principal del Juego en el que se va actualizando el estado del
     * modelo.
     */
    void run();
    virtual ~Juego();

private:
    /* Método interno que permite crear los objetos iniciales del mapa. La 
     * configuración inicial se obtiene de configuracion.xml (generado por el
     * generador de mapas). Llama a inicializarEdificios e 
     * inicializarInmovibles.
     */
    void inicializarJuego(const std::string& nombreArchivo);
    /* Función que inicializa los edificios espeficiados en configuracion.xml.
     */
    void inicializarEdificios(int tipo, tinyxml2::XMLElement* padre, 
                                std::string nombreXML);
    /* Función que inicializa los bloques y banderas especificados en 
     * configuracion.xml.
     */
    void inicializarInmovibles(int tipo, tinyxml2::XMLElement* padre, 
                                std::string nombreXML, 
                                std::string nombreObjetos);
    /* Función llamada al recibir un mensaje de mover.
     */
    void recibirMover(std::string mensaje);
    /* Función llamada al recibir un mensaje de disparar.
     */
    void recibirDisparar(std::string mensaje);
    /* Función llamada al recibir un mensaje de obtejer información.
     */
    void recibirObtenerInfo(std::string mensaje, int src);
    /* Función llamada al recibir un mensaje de crear.
     */
    void recibirCrear(std::string mensaje);    
    /* Método interno que le pasa los mensajes a todos los jugadores.
     */
    void enviarMensaje(Mensaje& mensaje);
    /* Método interno que encola un mensaje de información de fábrica.
     */
    void enviarInfoFabrica(std::string id, int dst);
    /* Método interno que encola un mensaje de información de unidad.
     */
    void enviarInfoUnidad(std::string id, int dst);
    /* Método interno que le envía un mensaje a los jugadores que perdieron.
     */
    void eliminarPerdedores(int equipoPerdedor);
    
    Mapa mapa;

    /* Indica si el juego está finalizado
     */
    BoolProtected finalizado;
    
    ColaMensajes& colaDeRecibidos;
    ColaMensajes colaDeEnviados;
    
    std::vector<Jugador*>& jugadores;
    /* Los jugadores que van perdiendo se van encolando en perdedores.
     */
    std::vector<Jugador*> perdedores;
    int equiposActivos;
    
    FabricaUnidades fabricaUnidades;
    FabricaMuniciones fabricaMuniciones;
    FabricaEdificios fabricaEdificios;
    FabricaInmovibles fabricaInmovibles;
        
    std::array<int,4> banderasPorEquipo;

    std::map<std::string,Movible*> movibles; //Robots, vehiculos, balas
    std::map<std::string,Inmovible*> inmovibles; //Bloques, banderas
    std::map<std::string,Edificio*> edificios; //Edificios

    ManejadorIDs manejadorIDs;    
};

#endif /* JUEGO_H */
