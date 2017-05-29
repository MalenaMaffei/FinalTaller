/*
 *  common_Socket.h
 */

#ifndef SOCKET_H
#define SOCKET_H

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif

#include <string>

/* TDA Socket
 */

class Socket {
public:
    Socket();
    ~Socket();
    Socket(const Socket& orig) = delete;
    Socket &operator=(const Socket &orig) = delete;
    Socket(Socket &&orig);
    Socket &operator=(Socket &&orig);
    int connect(const std::string& host, const std::string& service);
    int bindandlisten(const std::string& service);
    Socket accept();
    int shutdown(const std::string& mode);
    int send(const char* buffer, size_t length);
    int receive(char* buffer, size_t length);
    int set_reuseaddr();
private:
    explicit Socket(int fd);
    int fd;
};

#endif /* SOCKET_H */

