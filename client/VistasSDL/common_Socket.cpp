/*
 *	commonSocket.cpp
 */

#include "common_Socket.h"

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <string>
#include <netdb.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include "common_SocketException.h"

#define OK 0
#define ERROR 1
#define CLOSED 2
#define NUM_CLIENTS 10

Socket::Socket() { 
    this->fd = socket(AF_INET, SOCK_STREAM,0);
    if (this->fd == -1) {
        throw SocketException("Error al crear socket, fd es -1. ");
    }
}

Socket::Socket(int fd) : fd(fd) { }

Socket::~Socket() {
	if (this->fd == -1) {
		return;
	}
	if (close(this->fd) == -1) {
        throw SocketException("Error al cerrar socket. ");
    }
}

Socket::Socket(Socket &&orig) : fd(orig.fd) {
	orig.fd = -1;
}

Socket &Socket::operator=(Socket &&orig) {
	this->fd = orig.fd;
	orig.fd = -1;
	return *this;
}

int Socket::connect(const std::string& host, const std::string& service) {
    struct addrinfo hints;
    struct addrinfo *result, *ptr;
        
    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_family = AF_INET;  /* IPv4 */
    hints.ai_socktype = SOCK_STREAM;    /* TCP */
    hints.ai_flags = 0;
    int s = getaddrinfo(host.c_str(), service.c_str(), &hints, &result);
    
    if (s != 0) {
		throw SocketException(
			"En connect, error en getaddrinfo (return value: %d). ", s);
    }
    
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
        s = ::connect(this->fd, ptr->ai_addr, ptr->ai_addrlen);
        if (s != -1) break;
    }
    
    freeaddrinfo(result);
    
    if (!ptr) {
		throw SocketException("En connect, !ptr. ");
    }
    
    return OK;	
}

int Socket::bindandlisten(const std::string& service) {
    struct addrinfo hints;
    struct addrinfo *result, *ptr;
    
    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_family = AF_INET;  /* IPv4 */
    hints.ai_socktype = SOCK_STREAM;    /* TCP */
    hints.ai_flags = AI_PASSIVE;
    int s = getaddrinfo(NULL, service.c_str(), &hints, &result);
        
    if (s != 0) {		
		throw SocketException(
			"En bindandlisten, error en getaddrinfo (return value: %d). ", s);
    }
    
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
        s = ::bind(this->fd, ptr->ai_addr, ptr->ai_addrlen);
        if (s != -1) break;
    }
    
    freeaddrinfo(result);

    if (!ptr) {
		throw SocketException("En bindandlisten, !ptr. ");
    }

    listen(this->fd,NUM_CLIENTS);
    
    return OK;    	
}

Socket Socket::accept() {
	int fd = ::accept(this->fd,NULL,NULL);
	if (fd == -1) {
		throw SocketException("En accept, fd es -1. ");
    }
	Socket new_socket(fd);
	
    return std::move(new_socket);
}

int Socket::shutdown(const std::string& mode) {
    int how;
    if (mode == "read&write"){
        how = SHUT_RDWR;
    } else if (mode == "read"){
        how = SHUT_RD;
    } else if (mode == "write"){
        how = SHUT_WR;
    } else {
		throw SocketException("En shutdown, %s no es un modo. ", mode);
    }
    if (::shutdown(this->fd,how)) {
		throw SocketException("Error en shutdown. ");
	}
    return OK;	
}

int Socket::send(const char* buffer, size_t length) {
    bool socket_error = false;
    bool socket_closed = false;
    size_t bytes_sent = 0;
    
    while (bytes_sent < length && !socket_error && !socket_closed) {
        int s = ::send(this->fd, &buffer[bytes_sent], 
                length - bytes_sent, MSG_NOSIGNAL);

		if (s<0) {
			socket_error = true;
		} else if (s == 0) {
			socket_closed = true;
		} else {
			bytes_sent += s;
		}
	}
    if (socket_error) {
		throw SocketException("Error en receive. ");
	}
	if (socket_closed) {
		return CLOSED;
	}
    return OK;	
}

int Socket::receive(char* buffer, size_t length) {
	bool socket_error = false;
    bool socket_closed = false;
    size_t bytes_recv = 0;
    
    while (bytes_recv < length && !socket_error && !socket_closed) {
        int s = ::recv(this->fd, &buffer[bytes_recv],
                length - bytes_recv, MSG_NOSIGNAL);
    	        
        if (s<0) {
                socket_error = true;
        } else if (s == 0) {
                socket_closed = true;
        } else {
                bytes_recv += s;
        }
    }
    if (socket_error) {
		throw SocketException("Error en receive. ");
	}
	if (socket_closed) {
		return CLOSED;
	}
	return OK;  
}

int Socket::set_reuseaddr() {
	int val = 1;
	return setsockopt(this->fd,SOL_SOCKET,SO_REUSEADDR,&val,sizeof(val));
}
