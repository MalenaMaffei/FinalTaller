#ifndef BOOLPROTECTED_H
#define BOOLPROTECTED_H

#include <mutex>

/* Booleano protegido.
 * Es thread safe.
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

