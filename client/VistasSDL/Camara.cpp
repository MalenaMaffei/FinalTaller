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


void Camara::move(float timeStep)
{
    //Move the dot left or right
    mBox.x += mVelX * timeStep;

    //If the dot went too far to the left or right
    if( mBox.x < 0 )
    {
        mBox.x = 0;
    }
    else if( mBox.x > LEVEL_WIDTH - mBox.w )
    {
        mBox.x = LEVEL_WIDTH - mBox.w;
    }
    //If the dot went too far to the left or right or touched a wall
//    if( ( mBox.x < 0 ) || ( mBox.x + mBox.w > LEVEL_WIDTH ))
//    {
//        //move back
//        mBox.x -= mVelX;
//    }

    //Move the dot up or down
    mBox.y += mVelY * timeStep;

//    //If the dot went too far up or down or touched a wall
//    if( ( mBox.y < 0 ) || ( mBox.y + mBox.h  > LEVEL_HEIGHT ))
//    {
//        //move back
//        mBox.y -= mVelY;
//    }

    //If the dot went too far up or down
    if( mBox.y < 0 )
    {
        mBox.y = 0;
    }
    else if( mBox.y > LEVEL_HEIGHT - mBox.h )
    {
        mBox.y  = LEVEL_HEIGHT - mBox.h;
    }
}
//
//void Camara::move()
//{
//    //Move the dot left or right
//    mBox.x += mVelX;
//
//    //If the dot went too far to the left or right or touched a wall
//    if( ( mBox.x < 0 ) || ( mBox.x + mBox.w > LEVEL_WIDTH ))
//    {
//        //move back
//        mBox.x -= mVelX;
//    }
//
//    //Move the dot up or down
//    mBox.y += mVelY;
//
//    //If the dot went too far up or down or touched a wall
//    if( ( mBox.y < 0 ) || ( mBox.y + mBox.h  > LEVEL_HEIGHT ))
//    {
//        //move back
//        mBox.y -= mVelY;
//    }
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
