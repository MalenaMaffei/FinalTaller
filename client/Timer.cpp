#include "Header Files/Timer.h"

Timer::Timer() : mStartTicks(0), mStarted(false) {}

void Timer::start() {
    mStarted = true;
    mStartTicks = SDL_GetTicks();
}

Uint32 Timer::getTicks() {
    Uint32 time = 0;
    if (mStarted) {
            time = SDL_GetTicks() - mStartTicks;
    }
    return time;
}
