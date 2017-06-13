#include "Header Files/Canvas.h"
#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include "Header Files/LTimer.h"
#include "Header Files/VistaTiles.h"
#include "Header Files/Tile.h"

#include "Header Files/ColectorDeAcciones.h"
#include "Header Files/Hud.h"
#include "Header Files/VistaHud.h"
#include "Header Files/VistaHudCaras.h"
#include "Header Files/VistaGui.h"
#include "CreadorMapa.h"
#include "VistaTexto.h"
#include <string>

const int SCREEN_FPS = 30;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

Canvas::Canvas(ColaPaquetes &colaEntrada, ColaPaquetes &colaSalida) :
    colaEntrada(colaEntrada), colaSalida(colaSalida) {
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
        gWindow = SDL_CreateWindow( "Z Game", SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
            }
        }
    }

    if (!success){
//        TODO lanzar excepcion aca, bah, no en cada instancia
    }
}


void Canvas::close() {

    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

//    TODO destruir a los elementos


    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

int getTileType(int x, int y){
    if (x < 50){
        return 0;
    } else if (x < 100) {
        return 1;
    } else if (x < 150){
        return 2;
    } else if (x < 200){
        return 3;
    }
}


void Canvas::manejarPaquetes(ElementoManager &elementoManager,
                             Hud &hud,
                             GuiEdificio &guiEdificio) {
//    TODO esto deberia ser otro thread? se me puede llegar a quedar
// bloqueado aca?
    CodigosPaquete codigos;
    while (!colaEntrada.isEmpty()){
        Paquete paquete = colaEntrada.desencolar();
        if (paquete.getComando() == codigos.crear) {
            elementoManager.crear(paquete);
        } else if (paquete.getComando() == codigos.mover){
            elementoManager.mover(paquete);
        } else if (paquete.getComando() == codigos.disparar){
            elementoManager.disparar(paquete);
        } else if (paquete.getComando() == codigos.matar){
            elementoManager.matar(paquete);
        } else if (paquete.getComando() == codigos.infoFabrica){
            PaqueteFabrica paqueteFabrica(paquete.getMensaje());
            guiEdificio.setInfo(paqueteFabrica);
        }
//        TODO manejar infos para el hud y la gui edificio
    }
}


void Canvas::run(){
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    Camara camara;


//Keeps track of time between steps
    LTimer stepTimer;
    //The frames per second timer
    LTimer fpsTimer;

    //The frames per second cap timer
    LTimer capTimer;
    //Current animation frame
    int frame = 0;

    while (colaEntrada.isEmpty()){
//        TODO fix pedorro hasta uqe se me ocurra una mejor manera
    }
    Paquete color = colaEntrada.desencolar();
    if (color.getComando() == 6){
        miColor = std::stoi(color.getMensaje().substr(1));
        printf("mi color es: %i", miColor);
    }
    while (colaEntrada.isEmpty()){
//        TODO fix pedorro hasta uqe se me ocurra una mejor manera
    }
    VistaTiles tilesTexture(gRenderer);
    std::vector<Tile> tiles;
    CreadorMapa creadorMapa;
    Paquete mapa = colaEntrada.desencolar();
//    TODO poner proper manejador de este tipo de paquetes aca.
    if (mapa.getComando() == 5){
        creadorMapa.crearMapa(mapa, tiles, tilesTexture);
    }

    VistaManager vistaManager(gRenderer);
    ElementoManager elementoManager(vistaManager, miColor);


    VistaHud vistaHud(gRenderer);
    VistaHudCaras vistaCaras(gRenderer);
    Hud hud(vistaHud, vistaCaras);
//    VistaGui vistaGui(gRenderer);
    GuiEdificio guiEdificio(gRenderer);

    Mouse mouse;
    SelectBox selectBox;
    Click click;
    ColectorDeAcciones colector(selectBox,
                                click,
                                hud,
                                guiEdificio,
                                colaSalida);


    while (!quit){
        capTimer.start();

        manejarPaquetes(elementoManager, hud, guiEdificio);

        //Handle events on queue
        while (SDL_PollEvent( &e ) != 0){
            //User requests quit
            if (e.type == SDL_QUIT){
                quit = true;
            }
            //Handle input for the dot
            camara.handleEvent(e);
            mouse.setState(e.type, e, camara.getOffset());
        }

        float timeStep = stepTimer.getTicks() / 1000.f;

        //Move the dot
//            camara.move();

        camara.move(timeStep);
        //Restart step timer
        stepTimer.start();

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        //Render background

        std::for_each(tiles.begin(), tiles.end(), [&](Tile& tile){
          tile.mostrar(camara);
        });


        mouse.setMouseAction(selectBox, click);

        elementoManager.elementosVivir(camara, click, selectBox);

        selectBox.mostrar(gRenderer, camara.getOffset());
        hud.mostrar();
        guiEdificio.mostrar(camara.getOffset());


        //Update screen
        SDL_RenderPresent(gRenderer);
        colector.crearAcciones();
        mouse.resetState();


        int frameTicks = capTimer.getTicks();
        if( frameTicks < SCREEN_TICK_PER_FRAME ){
            //Wait remaining time
            SDL_Delay( SCREEN_TICK_PER_FRAME - frameTicks );
        }
    }


    //Free resources and close SDL
    close();
}

void Canvas::gameLoop() {
//todo pasar el loop aca
}
