#include "Header Files/Camara.h"
#include "Header Files/Texture.h"
#include "Header Files/Punto.h"
Camara::Camara() : camRect(Punto(),SCREEN_WIDTH,SCREEN_HEIGHT),velX(0),velY(0){}

void Camara::handleEvent(SDL_Event& e){
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0){
        switch (e.key.keysym.sym){
            case SDLK_w: velY -= CAM_VEL; break;
            case SDLK_s: velY += CAM_VEL; break;
            case SDLK_a: velX -= CAM_VEL; break;
            case SDLK_d: velX += CAM_VEL; break;
        }
    }else if (e.type == SDL_KEYUP && e.key.repeat == 0){
        switch (e.key.keysym.sym){
            case SDLK_w: velY += CAM_VEL; break;
            case SDLK_s: velY -= CAM_VEL; break;
            case SDLK_a: velX += CAM_VEL; break;
            case SDLK_d: velX -= CAM_VEL; break;
            case SDLK_SPACE: Camara::centrar(); break;
        }
    }
}


void Camara::mover(float timeStep) {
    camRect = camRect.positiveShift(Punto(velX * timeStep, velY * timeStep));
    Camara::ajustar();
}

bool Camara::estaEnfocado(Rect b) {
    return camRect.hayColision(b);
}

Punto Camara::getPos() {
    return camRect.getPunto();
}

void Camara::centrar() {
    Punto origenCamara;
    origenCamara = centro - Punto(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    camRect.setPunto(origenCamara);
    Camara::ajustar();
}

void Camara::setCentro(const Punto &centro) {
    Camara::centro = centro;
    Camara::centrar();
}

void Camara::ajustar() {
    if (camRect.x < 0){
        camRect.x = 0;
    } else if (camRect.x > LEVEL_WIDTH - camRect.w){
        camRect.x = LEVEL_WIDTH - camRect.w;
    }

    if (camRect.y < 0){
        camRect.y = 0;
    } else if (camRect.y > LEVEL_HEIGHT - camRect.h){
        camRect.y  = LEVEL_HEIGHT - camRect.h;
    }
}
