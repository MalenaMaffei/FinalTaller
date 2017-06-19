#include "Header Files/Canvas.h"
#include "Header Files/PaqueteReceiver.h"
#include "Header Files/PaqueteSender.h"
#include "Header Files/Greeter.h"
#include <iostream>
#include <string>
int main(int argc, char *argv[]){
    Greeter greeter;
    greeter.greet();

    std::string ip;
    std::string puerto;
    if (argc >= 3){
        ip = argv[1];
        puerto = argv[2];
    } else {
        ip = greeter.pedirIp();
        puerto = greeter.pedirPuerto();
    }

    Socket socket;
    try {
        socket.setClientMode(ip, puerto);
    } catch(SocketException &e){
        std::cout << "No se pudo establecer una conexión con el Servidor, "
            "inténtelo más tarde. IP: " << ip << " puerto: " << puerto <<
            "." << std::endl;
        std::cerr << e.what() << std::endl;
        return -1;
    }


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
