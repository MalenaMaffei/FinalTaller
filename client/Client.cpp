#include "Header Files/Canvas.h"
#include "Header Files/PaqueteReceiver.h"
#include "Header Files/PaqueteSender.h"

int main(int argc, char *argv[]){
    printf("probando thread\n");
    ColaPaquetes colaEntrada;
    ColaPaquetes colaSalida;

//    DESCOMENTAR PARA PROBAR CON SERVER
    Socket socket;
    socket.setClientMode(argv[1], argv[2]);


    PaqueteReceiver receiver(socket, colaEntrada);
    PaqueteSender sender(socket, colaSalida);

    receiver.start();
    sender.start();
    Canvas canvas(colaEntrada, colaSalida);
    canvas.startGame();

//    Si llegue aca es porque se cerro la ventana
//    Agregar paquet Receiver quit y Sender quit.


//   TODO FALTA CONDICION DE QUIT!
}
