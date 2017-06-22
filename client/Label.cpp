#include "Label.h"

void Label::mostrar() {
    labels.mostrar(rect.getPunto() - camera.getPos(), currentClip);
}
