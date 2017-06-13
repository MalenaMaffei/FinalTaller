#include "Header Files/Canvas.h"
#include "Header Files/PaqueteReceiver.h"
#include "Header Files/PaqueteSender.h"

int main(int argc, char *argv[]){

    //    DESCOMENTAR PARA PROBAR CON SERVER
    Socket socket;
    socket.setClientMode(argv[1], argv[2]);

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
//    TODO cuando el sender esta bloqueado con condV, como hago para
// despertarlo?
    sender.shutdown();
    socket.Shutdown(SHUT_RDWR);

    receiver.join();
    sender.join();
}
