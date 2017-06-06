/*
 *  server_SocketException.h
 */

#ifndef SOCKETEXCEPTION_H
#define SOCKETEXCEPTION_H

#include <typeinfo>

#define BUF_LEN 256

/*
 * Exception thrown by socket while an error occurs
 */

class SocketException : public std::exception {
public:
    explicit SocketException(const char* fmt, ...) noexcept;
    virtual const char *what() const noexcept;
    virtual ~SocketException() noexcept;
private:
    char msg_error[BUF_LEN];
};

#endif /* SOCKETEXCEPTION_H */

