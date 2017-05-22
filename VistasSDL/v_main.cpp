#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <algorithm>
//#include "VistaAnimada.h"
#include "LTimer.h"
#include "Vista.h"
#include "LTexture.h"
#include "Camara.h"
#include "VistaTiles.h"
#include "Tile.h"
#include "VistaAnimada.h"
#include "VistaRoca.h"
#include "Elemento.h"
#include "ElementoRoca.h"
#include "ElementoFuerte.h"
#include "VistaBandera.h"
#include "ElementoBandera.h"
#include "VistaPuente.h"
#include "ElementoPuente.h"
#include "VistaRobotCaminar.h"
#include "ElementoRobot.h"

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

//    TODO destruir a los elementos




	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
int getTileType(int x, int y){
    if(x < 50){
        return 0;
    } else if(x < 100) {
        return 1;
    } else if(x < 150){
        return 2;
    } else if(x < 200){
        return 3;
    }
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
        int pos = 0;
        VistaAnimada Tank(gRenderer);


//        LTexture gBGTexture(gRenderer);
//        gBGTexture.loadFromFile("../VistasSDL/imgs/bg.png");
        VistaTiles tilesTexture(gRenderer);
        std::vector<Tile> tiles;
        for (int x = 0; x < LEVEL_WIDTH/TILE_WIDTH ; ++x) {
            for (int y = 0; y < LEVEL_HEIGHT/TILE_HEIGHT; ++y) {
                Tile tile (x*TILE_WIDTH, y*TILE_HEIGHT, getTileType(x,y),
                           &tilesTexture);
                tiles.push_back(tile);
            }
        }

//        SDL_Rect cuadro = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT   };


        VistaRoca rocaTextura(gRenderer);
        std::vector<Elemento*> elementos;
        for (int j = 0; j <640; j+=32) {
            Elemento* roca = new ElementoRoca(j, j+10, j+500,&rocaTextura);
            elementos.push_back(roca);
        }

        VistaFuerte fuerteTextura(gRenderer);
        Elemento* fuerte1 = new ElementoFuerte(1, 100, 100, &fuerteTextura);
        elementos.push_back(fuerte1);
        Elemento* fuerte2 = new ElementoFuerte(1, 900, 900, &fuerteTextura);
        elementos.push_back(fuerte2);

        VistaBandera banderaTextura(gRenderer);
        for (int j = 0; j <640; j+=32) {
            Elemento* bandera = new ElementoBandera(j, j+60, j+500,
                                                    &banderaTextura);
            elementos.push_back(bandera);
        }

        VistaPuente puenteTextura(gRenderer);
        for (int j = 0; j <640; j+=64) {
            Elemento* puente = new ElementoPuente(j, j+200, j+800,
                                                    &puenteTextura, j%3==0);
            elementos.push_back(puente);
        }


        VistaRobotCaminar robotCaminarTextura(gRenderer);
        Elemento* robot1 = new ElementoRobot(1,20,20, &robotCaminarTextura);
        elementos.push_back(robot1);
        Elemento* robot2 = new ElementoRobot(1,40,40, &robotCaminarTextura);
        elementos.push_back(robot2);



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

            std::for_each(tiles.begin(), tiles.end(), [&](Tile& tile){
              tile.mostrar(camara);
            });

            std::for_each(elementos.begin(), elementos.end(), [&](Elemento*
            elemento){
              elemento->mostrar(camara);
            });



//            tilesTexture.mostrar(0,0,0);
//            tilesTexture.mostrar(0,20,1);


//            gBGTexture.mostrar( 0, 0, camara.getCamara() );




			//Render objects
//			dot.mostrar( &gDotTexture );


//            pos = (i%LEVEL_WIDTH)*3;
//            cuadro.x = pos;

//            gBGTexture.mostrar( 0, 0, &cuadro );
//            Tank.mostrar(camara);
//            ++i;
            //Update screen
            SDL_RenderPresent( gRenderer );

//
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
