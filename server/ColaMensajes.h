#ifndef TPFINAL_MONITORPAQUETES_H
#define TPFINAL_MONITORPAQUETES_H
#include <queue>
#include <mutex>
#include "Mensaje.h"

class ColaMensajes {
    public:
        void encolar(Mensaje paquete);
        Mensaje desencolar();
        bool isEmpty();
    private:
        std::queue<Mensaje> paquetes;
        std::mutex m;
};

#endif //TPFINAL_MONITORPAQUETES_H
