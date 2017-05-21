#include "Camara.h"
#include "LTexture.h"

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

void Camara::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_w: mVelY -= DOT_VEL; break;
            case SDLK_s: mVelY += DOT_VEL; break;
            case SDLK_a: mVelX -= DOT_VEL; break;
            case SDLK_d: mVelX += DOT_VEL; break;
        }
    }
        //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_w: mVelY += DOT_VEL; break;
            case SDLK_s: mVelY -= DOT_VEL; break;
            case SDLK_a: mVelX += DOT_VEL; break;
            case SDLK_d: mVelX -= DOT_VEL; break;
        }
    }
}

void Camara::move()
{
    //Move the dot left or right
    mBox.x += mVelX;

    //If the dot went too far to the left or right or touched a wall
    if( ( mBox.x < 0 ) || ( mBox.x + mBox.w > LEVEL_WIDTH ))
    {
        //move back
        mBox.x -= mVelX;
    }

    //Move the dot up or down
    mBox.y += mVelY;

    //If the dot went too far up or down or touched a wall
    if( ( mBox.y < 0 ) || ( mBox.y + mBox.h  > LEVEL_HEIGHT ))
    {
        //move back
        mBox.y -= mVelY;
    }
}

//void Camara::setCamera() {
//    //Center the camera over the dot
//    camera.x = ( mBox.x + mBox.w / 2 ) - SCREEN_WIDTH / 2;
//    camera.y = ( mBox.y + DOT_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;
//
//    printf("------------DENTRO DE SETCAMERA-------------\n");
//    printf("x de la camara: %i    ",camera.x);
//    printf("y de la camara: %i\n",camera.y);
//    //Keep the camera in bounds
//    if( camera.x < 0 ){
//        printf("X menor que 0 ->");
//        camera.x = 0;
//        printf("x de la camara: %i    \n",camera.x);
//    }
//    if( camera.y < 0 ){
//        printf("Y menor que 0 ->");
//        camera.y = 0;
//        printf("y de la camara: %i\n",camera.y);
//    }
//    if( camera.x > LEVEL_WIDTH - camera.w ){
//        printf("X mayor que level width ->");
//        camera.x = LEVEL_WIDTH - camera.w;
//        printf("x de la camara: %i    \n",camera.x);
//    }
//    if( camera.y > LEVEL_HEIGHT - camera.h ){
//        printf("Y mayor que level height ->");
//        camera.y = LEVEL_HEIGHT - camera.h;
//        printf("y de la camara: %i\n",camera.y);
//    }
//}

//void Camara::mostrar(LTexture *dotTexture) {
//    //Show the dot
//    dotTexture->mostrar( mBox.x - camera.x, mBox.y - camera.y);
//}

bool Camara::checkCollision(SDL_Rect b) {
//    return true;
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = mBox.x;
    rightA = mBox.x + mBox.w;
    topA = mBox.y;
    bottomA = mBox.y + mBox.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}
//
int Camara::getCamaraX() {
    return mBox.x;
//    return 0;
}
//
int Camara::getCamaraY() {
    return mBox.y;
//    return 0;
}
//

SDL_Rect *Camara::getCamara() {
    &mBox;
}
