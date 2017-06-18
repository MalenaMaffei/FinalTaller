
#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include <string>

class Reproductor {
public:
    Reproductor();
    void reproducirMusica(const std::string& fileName);
    void reproducirFX(const std::string& fileName);
    ~Reproductor();
private:
};

#endif /* REPRODUCTOR_H */

