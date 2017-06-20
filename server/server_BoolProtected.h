/*
 *  server_BoolProtected.h
 */

#ifndef BOOLPROTECTED_H
#define BOOLPROTECTED_H

#include <mutex>

/* Represents a thread safe boolean
 */
class BoolProtected {
public:
    BoolProtected();
    explicit BoolProtected(bool value);
    bool get_value();
    void set_value(bool value);
private:
    std::mutex m;
    bool value;
};

#endif /* BOOLPROTECTED_H */

