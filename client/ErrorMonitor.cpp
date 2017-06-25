#include <iostream>
#include <string>
#include "ErrorMonitor.h"
using std::cerr;
using std::endl;

void ErrorMonitor::outputError(string error) {
  //    CRITICAL SECTION
  std::lock_guard<std::mutex> lock(m);
  cerr << error << endl;
}
