#include "Header Files/Camara.h"
#include "Header Files/Texture.h"
#include "Header Files/Punto.h"
Camara::Camara(){
    //Initialize the collision box
    mBox.x = 0;
    mBox.y = 0;
    mBox.w = SCREEN_WIDTH;
    mBox.h = SCREEN_HEIGHT;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
//    SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
}

void Camara::handleEvent(SDL_Event& e){
    //If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0){
        //Adjust the velocity
        switch (e.key.keysym.sym){
            case SDLK_w: mVelY -= CAM_VEL; break;
            case SDLK_s: mVelY += CAM_VEL; break;
            case SDLK_a: mVelX -= CAM_VEL; break;
            case SDLK_d: mVelX += CAM_VEL; break;
        }
    }else if (e.type == SDL_KEYUP && e.key.repeat == 0){
        //Adjust the velocity
        switch (e.key.keysym.sym){
            case SDLK_w: mVelY += CAM_VEL; break;
            case SDLK_s: mVelY -= CAM_VEL; break;
            case SDLK_a: mVelX += CAM_VEL; break;
            case SDLK_d: mVelX -= CAM_VEL; break;
        }
    }
}


void Camara::move(float timeStep) {
    mBox.x += mVelX * timeStep;

    if (mBox.x < 0){
        mBox.x = 0;
    } else if (mBox.x > LEVEL_WIDTH - mBox.w){
        mBox.x = LEVEL_WIDTH - mBox.w;
    }

    mBox.y += mVelY * timeStep;

    if (mBox.y < 0){
        mBox.y = 0;
    }else if (mBox.y > LEVEL_HEIGHT - mBox.h){
        mBox.y  = LEVEL_HEIGHT - mBox.h;
    }
}

bool Camara::estaEnfocado(Rect b) {
    return mBox.hayColision(b);
}

int Camara::getCamaraX() {
    return mBox.x;
}

int Camara::getCamaraY() {
    return mBox.y;
}

SDL_Rect *Camara::getCamara() {
    &mBox;
}

Punto Camara::getPos() {
    return mBox.getPunto();
}
