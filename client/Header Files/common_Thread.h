/*
 *  server_Thread.h
 */

#ifndef THREAD_H
#define THREAD_H

#include <thread>

/* Thread executes a virtual method (defined in the son classes, thar inherit 
 * from Thread) on its own thread.
 */
class Thread {
public:
    Thread();
    Thread(const Thread& orig) = delete;
    Thread& operator=(const Thread&) = delete;
    Thread(Thread&& other);
    Thread& operator=(Thread&& other);
    virtual ~Thread();
    
    void start();
    void join();
    /* run is defined in son classes
     */
    virtual void run() = 0;
    
private:
    std::thread thread;
};

#endif /* THREAD_H */

