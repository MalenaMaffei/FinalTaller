#include "ElementoRobot.h"
ElementoRobot::ElementoRobot(int id,
                             int x,
                             int y,
                             Vista *textura) : Elemento(id,
                                                        x,
                                                        y,
                                                        textura->getWidth(),
                                                        textura->getWidth(),
                                                        textura) {}
