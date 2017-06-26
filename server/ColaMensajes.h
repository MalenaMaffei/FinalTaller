#ifndef TPFINAL_MONITORPAQUETES_H
#define TPFINAL_MONITORPAQUETES_H
#include <queue>
#include <mutex>
#include "Mensaje.h"

/* Cola protegida de mensajes (instancias de la clase Mensaje).
 * Es thread safe.
 */

class ColaMensajes {
    public:
        void encolar(Mensaje paquete);
        Mensaje desencolar();
        int size();
        bool isEmpty();
    private:
        std::queue<Mensaje> paquetes;
        std::mutex m;
};

#endif //TPFINAL_MONITORPAQUETES_H
