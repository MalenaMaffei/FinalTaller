#include "Header Files/CanvasException.h"
CanvasException::CanvasException(std::string what_arg) : std::runtime_error(
(what_arg.c_str())) {}
