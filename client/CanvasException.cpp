#include "Header Files/CanvasException.h"
#include <string>
CanvasException::CanvasException(std::string what_arg) : std::runtime_error(
(what_arg.c_str())) {}
