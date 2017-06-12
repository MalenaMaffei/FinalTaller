#include "Header Files/PaqueteReceiver.h"
#include <string>
#include <chrono>
PaqueteReceiver::PaqueteReceiver(const Socket &socket, ColaPaquetes &cola)
    : PaqueteDelivery(socket, cola) {}

void PaqueteReceiver::run() {
    while (!salir){
        Paquete color;
        color.setMensaje("60");
        cola.encolar(color);
        Paquete mapa;
        mapa.setMensaje
            ("50000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333000000000011111111112222222222333333333300000000001111111111222222222233333333330123012301333333333300000000001111111111222222222233333333330000000000111111111122222222223333333333012301230133333333330000000000111111111122222222223333333333000000000011111111112222222222333333333301230123013333333333");
        cola.encolar(mapa);

        int espera = 200;

        Paquete fuerte;
        fuerte.setMensaje("00010010000100030");

        cola.encolar(fuerte);
        std::this_thread::sleep_for(std::chrono::milliseconds(espera));



        salir = true;
//        string mensaje;
//        mensaje = socket.ReceiveStrWLen();
//		printf("paquete %s\n", mensaje.c_str());
//        Paquete paquete;
//        paquete.setMensaje(mensaje);
//        cola.encolar(paquete);
    }
}
