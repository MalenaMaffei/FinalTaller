#ifndef RECEPTORCLIENTE_H
#define RECEPTORCLIENTE_H

#include "common_Thread.h"
#include "common_Socket.h"
#include "ColaMensajes.h"
#include "server_BoolProtected.h"

/* Es el representante de los clientes en servidor. Por medio de cada Jugador, 
 * el Juego intercambia información con los clientes.
 */

class Jugador : public Thread {
public:
    /* Instancia un Jugador con un socket (mediante el cual se comunicará
     * con el cliente), una colaDeRecibidos (donde irá encolando los mensajes)
     * y un id (que identifica al cliente).
     */
    Jugador(Socket &socket, ColaMensajes &colaDeRecibidos, int id);
    /* Envia un mensaje al cliente asociado, si coincide con su id, o si el
     * mensaje está destinado a todos los clientes.
     */
    void enviarMensaje(std::string& mensaje, int id);
    /* Finaliza el ciclo de comunicación del jugador.
     */
    void finalizar();
    void setEquipo(int equipo);
    int getEquipo();
    int getId();
    void run();
    void cerrarConexion();
    virtual ~Jugador();
private:
    BoolProtected salir;
    Socket socket;
    int equipo;
    ColaMensajes& colaDeRecibidos;
    int id;
};

#endif /* RECEPTORCLIENTE_H */

