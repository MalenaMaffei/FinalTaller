#ifndef LOGGER_H
#define LOGGER_H

#include <mutex>

/* Logger protegido que permite imprimir mensajes en stderr o stdout.
 * Es thread safe.
 */

class Logger {
public:
    static Logger* getInstancia();
    void logACout(const std::string& mensaje);
    void logACerr(const std::string& mensaje);
    virtual ~Logger();
private:
    static Logger* instancia;
    std::mutex coutMutex;
    std::mutex cerrMutex;
};

#endif /* LOGGER_H */

