#include "../Header Files/VistaMuerteTanque.h"
#define HEIGHT 32
#define WIDTH 32
#define CLIPS 7

VistaMuerteTanque::VistaMuerteTanque(SDL_Renderer *gRenderer) : Vista(
    gRenderer,
    HEIGHT,
    WIDTH,
    CLIPS,
    tanqueMuertePath) {}

//bool VistaMuerteTanque::isLastClip(int clip) const {
//    return clip == clips-1 ;
//}
