#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
//#include "VistaAnimada.h"
#include "LTimer.h"
#include "Vista.h"
#include "LTexture.h"
#include "Camara.h"

//The dimensions of the level
//const int LEVEL_WIDTH = 1280;
//const int LEVEL_HEIGHT = 960;
//
////Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;

const int SCREEN_FPS = 8;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;
#define SPRITE_SIZE 32


//Starts up SDL and creates window
bool init();

//Loads media
//bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

void close()
{

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


int main( int argc, char* args[] ){

	//Start up SDL and create window
	if( !init() ){
		printf( "Failed to initialize!\n" );
	}
	else{

        //Main loop flag
        bool quit = false;

        //Event handler
        SDL_Event e;

        Camara dot;



        //The frames per second timer
        LTimer fpsTimer;

        //The frames per second cap timer
        LTimer capTimer;
        //Current animation frame
        int frame = 0;

        //While application is running
        int i =1;
        int pos = 213;
//        Vista Tank(gRenderer);

//        LTexture gDotTexture(gRenderer);
//        gDotTexture.loadFromFile("../VistasSDL/imgs/dot.bmp");
        LTexture gBGTexture(gRenderer);
        gBGTexture.loadFromFile("../VistasSDL/imgs/bg.png");

//        SDL_Rect cuadro = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT   };


        while( !quit )
        {
            capTimer.start();
            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }

                //Handle input for the dot
                dot.handleEvent( e );
            }


            //Move the dot
            dot.move();
//            dot.setCamera();
//            //Center the camera over the dot
//            camera.x = ( dot.getPosX() + Dot::DOT_WIDTH / 2 ) - SCREEN_WIDTH / 2;
//            camera.y = ( dot.getPosY() + Dot::DOT_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;




            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );

//			printf("y de la camara: %i    ",dot.getCamaraY());
//			printf("x de la camara: %i\n",dot.getCamaraX());

            //Render background

            gBGTexture.render( 0, 0, dot.getCamara() );




			//Render objects
//			dot.render( &gDotTexture );


            pos = (i%42)*15;
//            cuadro.x = pos;

//            gBGTexture.render( 0, 0, &cuadro );
//            Tank.mostrar(pos, 100);
            ++i;
            //Update screen
            SDL_RenderPresent( gRenderer );


//            int frameTicks = capTimer.getTicks();
//            if( frameTicks < SCREEN_TICK_PER_FRAME ){
//                //Wait remaining time
//                SDL_Delay( SCREEN_TICK_PER_FRAME - frameTicks );
//            }
        }
	}

	//Free resources and close SDL
	close();

	return 0;
}
