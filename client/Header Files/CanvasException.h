#ifndef TPFINAL_CANVASEXCEPTION_H
#define TPFINAL_CANVASEXCEPTION_H

#include <stdexcept>
class CanvasException : public std::runtime_error {
 public:
  explicit CanvasException(std::string what_arg);
};

#endif //TPFINAL_CANVASEXCEPTION_H
