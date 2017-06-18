#include "Header Files/Canvas.h"
#include "Header Files/PaqueteReceiver.h"
#include "Header Files/PaqueteSender.h"
#include "Header Files/Greeter.h"

int main(int argc, char *argv[]){

    Greeter greeter;
    greeter.greet();

    //    DESCOMENTAR PARA PROBAR CON SERVER
    std::string ip;
    std::string puerto;
    if (argc >= 3){
        ip = argv[1];
        puerto = argv[2];
    } else {
//        TODO pedir por consola
    }


    Socket socket;
    socket.setClientMode(ip, puerto);

    std::mutex m;
    std::condition_variable cond;

    ColaPaquetes colaEntrada;
    ColaSalida colaSalida(&m, &cond);

    PaqueteReceiver receiver(socket, colaEntrada);
    PaqueteSender sender(socket, colaSalida, &m, &cond);

    receiver.start();
    sender.start();
    Canvas canvas(colaEntrada, colaSalida);
    canvas.startGame();
//    Si llegue aca es porque se cerro la ventana
    receiver.shutdown();
    sender.shutdown();
//    despierto al sender para que chequee condicion de salida.
    cond.notify_all();

    socket.Shutdown(SHUT_RDWR);

    receiver.join();
    sender.join();
}
