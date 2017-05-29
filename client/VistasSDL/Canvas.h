#ifndef TPFINAL_CANVAS_H
#define TPFINAL_CANVAS_H
#include "common_Thread.h"

class Canvas : public Thread{
 public:
  void init();
  void close();
  void run();
  void gameLoop();

};

#endif //TPFINAL_CANVAS_H
