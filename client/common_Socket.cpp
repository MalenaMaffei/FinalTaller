#include "Header Files/common_Socket.h"
// #define _POSIX_C_SOURCE 200112L
#include "Header Files/common_SocketException.h"
#include <sys/socket.h>
#include <unistd.h>
#include <memory.h>
#include "Header Files/common_SocketException.h"
#include <cstring>
#include <string>
#define SERVER_MODE 0
#define CLIENT_MODE 0
#define BACKLOG 10
#define LENGTH_SIZE 4
#define BUFFSIZE 300000

int Socket::filladdrinfo(const char *ip, const char *port, int
mode){
    int status = 0;

    struct addrinfo hints;
//    struct addrinfo *res;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (mode == SERVER_MODE){
        hints.ai_flags = AI_PASSIVE;
    } else{
        hints.ai_flags = 0;
    }

    status = getaddrinfo(ip, port, &hints, &res);
    if (status < 0) { return (NOK); }
    if (!res) { return NOK; }
    return OK;
}

void Socket::Create(const char *ip, const char *port, int mode){
    int skt = 0;
    filladdrinfo(ip, port, mode);
    skt = socket(res->ai_family, res->ai_socktype,
                 res->ai_protocol);
    if (skt == NOK) {
        throw SocketException("Error creando socket\n", fD);
    }
    fD = skt;
}

void Socket::CreateAndConnect(const char *ip, const char *port){
    struct addrinfo* ptr;
    bool connected = false;
    int status = 0;
    int skt = 0;

    filladdrinfo(ip, port, CLIENT_MODE);

    for (ptr = res; ptr != NULL && !connected; ptr = ptr->ai_next) {
        skt = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

        if (skt == NOK) {
            throw SocketException("Error creando socket\n", fD);
        } else {
            fD = skt;
            status = connect(fD,  ptr->ai_addr, ptr->ai_addrlen);
            if (status == NOK) {
                close(skt);
                continue;
            }
            connected = (status != NOK);
        }
    }

    if (!connected){
        throw SocketException("No se pudo conectar al Socket\n");
    }

    fD = skt;
}

void Socket::Send(unsigned char *source, size_t length){
    int bytes_left;
    int bytes_sent = 0;
    unsigned char *buffer_ptr = source;
    for (bytes_left = length; bytes_left>0; bytes_left-=bytes_sent) {
        if (!isConnected()) {
            throw SocketException("Intentaba enviar, pero se cerro el "
                                      "socket\n",
                                  fD);
        }
        bytes_sent=send(fD, buffer_ptr, bytes_left, MSG_NO_SIGNAL);
        if (bytes_sent<=0) {
            throw SocketException("Se intentaba enviar.\n", fD);
        } else {
            buffer_ptr+=bytes_sent;
        }
    }
}

void Socket::BindAndListen(int backlog){
    int s_bind = bind(fD, res->ai_addr, res->ai_addrlen);
    if (s_bind < 0){ throw SocketException("Error en bind.\n", fD); }
    int s_lis = listen(fD, backlog);
    if (s_lis <0){ throw SocketException("Error en listen.\n", fD); }
}

Socket Socket::Accept() {
    struct sockaddr_storage c_addr;
    struct sockaddr *a;
    socklen_t *l;
    socklen_t addr_s = sizeof c_addr;

    a = (struct sockaddr *)&c_addr;
    l= &addr_s;
    int new_fd = accept(fD, a, l);
    if (new_fd < 0){
        throw SocketException("Error en Accept\n", fD);
    }
    Socket newSocket;
    newSocket.fD = new_fd;
    newSocket.res = nullptr;
    return newSocket;
}

int Socket::Receive(unsigned char *buffer, size_t length){
    int bytes_read = recv(fD, buffer, length, MSG_NO_SIGNAL);
    if (bytes_read == MSG_NO_SIGNAL){
        throw SocketException("Intentaba recibir pero se cerro el socket\n",
                              fD);
    }
    return bytes_read;
}

void Socket::Shutdown(int mode){
    if (mode != SHUT_RDWR && mode != SHUT_RD && mode != SHUT_WR){
        throw SocketException("Modo de shutdown incorrecto.\n", fD);
    }
    int status = shutdown(fD, mode);
    if (status<0){
        throw SocketException("Error en shutdown.\n", fD);
    }
}

void Socket::Close(){
    if (res){
        freeaddrinfo(res);
    }
    int status = close(fD);
    if (status<0){
        throw SocketException("Error en close.\n", fD);
    }
}

string Socket::ReceiveStrWLen() {
    int read = 0;
    unsigned char buffer_leer[BUFFSIZE] = {0};
    while (read < LENGTH_SIZE){
        read = Receive(buffer_leer,LENGTH_SIZE);
    }

    int net_length;
    std::memcpy(&net_length, buffer_leer, sizeof net_length);
    int normal_length = ntohl(net_length);
    int bytes_read = 0;
    int left_to_read = normal_length;
    unsigned char *buffer_ptr = buffer_leer;
    while (left_to_read != 0){
        bytes_read = Receive(buffer_ptr,left_to_read);
        left_to_read -= bytes_read;
        buffer_ptr += bytes_read;
    }
    buffer_leer[normal_length] = '\0';
    string received((char *)buffer_leer);
    return received;
}

void Socket::SendStrWLen(string &str) {
    int normal_length = str.size();
    int net_length = htonl(normal_length);
    Send((unsigned char*)&net_length, LENGTH_SIZE);
    char *char_message = &str[0];
    Send((unsigned char *)char_message, str.size());
}

bool Socket::isConnected() {
    int read = recv(fD, NULL, 0, MSG_DONTWAIT | MSG_PEEK);
    return read != 0;
}

void Socket::setServerMode(string port) {
    Create(0, port.c_str(), SERVER_MODE);
    BindAndListen(BACKLOG);
}

void Socket::setClientMode(string ip, string port) {
    CreateAndConnect(ip.c_str(), port.c_str());
}

Socket::~Socket() {}
