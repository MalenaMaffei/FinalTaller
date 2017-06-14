#ifndef TPFINAL_MONITORPAQUETES_H
#define TPFINAL_MONITORPAQUETES_H
#include <queue>
#include <mutex>
#include <string>

class ColaMensajes {
 public:
    void encolar(const std::string& paquete);
    std::string desencolar();
    bool isEmpty();
 protected:
  std::queue<std::string> paquetes;
 private:
  std::mutex m;
};

#endif //TPFINAL_MONITORPAQUETES_H
