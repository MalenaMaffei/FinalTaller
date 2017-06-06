/*
 *  server_Lock.h
 */

#ifndef LOCK_H
#define LOCK_H

#include <mutex>

/*RAII encapsulation of a mutex*/
class Lock {
public:
    /*Lock the mutex in the constructor*/
    explicit Lock(std::mutex &m);
    /*Unlock the mutex in the destructor*/
    ~Lock();

private:
    Lock(const Lock& orig) = delete;
    Lock& operator=(const Lock&) = delete;
    Lock(Lock&&) = delete;
    Lock& operator=(Lock&&) = delete;

    std::mutex &m;    
};

#endif /* LOCK_H */
