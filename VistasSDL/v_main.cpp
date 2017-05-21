#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
//#include "VistaAnimada.h"
#include "LTimer.h"
#include "Vista.h"
#include "LTexture.h"
#include "Camara.h"
#include "VistaTiles.h"
#include "Tile.h"
#include "VistaAnimada.h"

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

        Camara camara;



        //The frames per second timer
        LTimer fpsTimer;

        //The frames per second cap timer
        LTimer capTimer;
        //Current animation frame
        int frame = 0;

        //While application is running
        int i =1;
        int pos = 213;
        VistaAnimada Tank(gRenderer);


//        LTexture gBGTexture(gRenderer);
//        gBGTexture.loadFromFile("../VistasSDL/imgs/bg.png");
        VistaTiles tilesTexture(gRenderer);


        Tile tile1(0,0, 0, &tilesTexture );
        Tile tile2(20,0, 1, &tilesTexture );
        Tile tile3(200,0, 2, &tilesTexture );
        Tile tile4(700,0, 3, &tilesTexture );
        Tile tile5(880,0, 0, &tilesTexture );
        Tile tile6(0,200, 1, &tilesTexture );
        Tile tile7(0,1000, 3, &tilesTexture );
        Tile tile8(0,100, 1, &tilesTexture );
        Tile tile8b(16,100, 1, &tilesTexture );
        Tile tile9(0,116, 1, &tilesTexture );
        Tile tile9b(16,116, 1, &tilesTexture );
        Tile tile10(0,132, 1, &tilesTexture );
        Tile tile10b(16,132, 1, &tilesTexture );





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
                camara.handleEvent( e );
            }


            //Move the dot
            camara.move();


            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );


            //Render background

            tile1.mostrar(camara);
            tile2.mostrar(camara);
            tile3.mostrar(camara);
            tile4.mostrar(camara);
            tile5.mostrar(camara);
            tile6.mostrar(camara);
            tile7.mostrar(camara);
            tile8.mostrar(camara);
            tile8b.mostrar(camara);
            tile9.mostrar(camara);
            tile9b.mostrar(camara);
            tile10.mostrar(camara);
            tile10b.mostrar(camara);



//            tilesTexture.mostrar(0,0,0);
//            tilesTexture.mostrar(0,20,1);


//            gBGTexture.mostrar( 0, 0, camara.getCamara() );




			//Render objects
//			dot.mostrar( &gDotTexture );


            pos = (i%42)*15;
//            cuadro.x = pos;

//            gBGTexture.mostrar( 0, 0, &cuadro );
            Tank.mostrar(pos, 100);
            ++i;
            //Update screen
            SDL_RenderPresent( gRenderer );


            int frameTicks = capTimer.getTicks();
            if( frameTicks < SCREEN_TICK_PER_FRAME ){
                //Wait remaining time
                SDL_Delay( SCREEN_TICK_PER_FRAME - frameTicks );
            }
        }
	}

	//Free resources and close SDL
	close();

	return 0;
}
