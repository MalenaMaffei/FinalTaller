#ifndef TPFINAL_LTIMER_H
#define TPFINAL_LTIMER_H
#include <SDL2/SDL.h>
class Timer {
   public:
    Timer();

    //Arranca el timer
    void start();

    Uint32 getTicks();

   private:
    //clock time de cuando arranco el timer
    Uint32 mStartTicks;

    bool mStarted;
};

#endif //TPFINAL_LTIMER_H
