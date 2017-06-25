#ifndef TP2_ERRORMONITOR_H
#define TP2_ERRORMONITOR_H
#include <string>
#include <mutex>
using std::string;
class ErrorMonitor {
 public:
  ErrorMonitor();
  void outputError(string error);
 private:
  std::mutex m;
};

#endif //TP2_ERRORMONITOR_H
