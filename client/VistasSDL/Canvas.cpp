#include "Header Files/Canvas.h"
#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include "Header Files/LTimer.h"
#include "Header Files/Vista.h"
#include "Header Files/Texture.h"
#include "Header Files/Camara.h"
#include "Header Files/VistaTiles.h"
#include "Header Files/Tile.h"
#include "Header Files/VistaRoca.h"
#include "Header Files/Elemento.h"
#include "Header Files/ElementoRoca.h"
#include "Header Files/ElementoFuerte.h"
#include "Header Files/VistaBandera.h"
#include "Header Files/ElementoBandera.h"
#include "Header Files/VistaPuente.h"
#include "Header Files/ElementoPuente.h"

#include "Header Files/ColectorDeAcciones.h"
#include "Header Files/Hud.h"
#include "Header Files/VistaHud.h"
#include "Header Files/VistaHudCaras.h"
#include "Header Files/common_CodigosPaquete.h"
#include "Header Files/VistaGui.h"
#include "Header Files/GuiEdificio.h"
#include "Header Files/Rect.h"
#include "VistaManager.h"
#include "Header Files/ElementoManager.h"

const int SCREEN_FPS = 20;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;


//TODO voy a necesitar un mapa de vistas, uno de vistas Dir, uno de
// todos los elementos y otro con solo las unidades. Los de las vistas los
// voy a tener que borrar los dos, pero los de elementos solo el de elementos
// tengo que hacer delete de cada uno. Todos los mapas van a tener punteros.

//TODO fabrica de vistas para no tener todos los include aca




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

    if (!success){
//        TODO lanzar excepcion aca, bah, no en cada instancia
    }
}


void Canvas::close()
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


void Canvas::manejarPaquetes() {
//    TODO aca voy a tener encolados todos los paquetes y voy sacando
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

    //While application is running
    int pos_robot = 0;
    int pos_tanque = 0;
    int pos = 0;


//        Texture gBGTexture(gRenderer);
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



    VistaManager vistaManager(gRenderer);
    ElementoManager elementoManager(vistaManager);

    VistaRoca rocaTextura(gRenderer);
    std::vector<Elemento*> elementos;
    for (int j = 0; j <640; j+=32) {
        Elemento* roca = new ElementoRoca(j, j+10, j+500,&rocaTextura);
        elementos.push_back(roca);
    }

    VistaFuerte fuerteTextura(gRenderer);
    Elemento* fuerte1 =
        new ElementoFuerte(1, 100, 100, &fuerteTextura, true, 0);
    elementos.push_back(fuerte1);
    Elemento* fuerte2 =
        new ElementoFuerte(1, 900, 900, &fuerteTextura, false, 0);
    elementos.push_back(fuerte2);

    VistaBandera banderaTextura(gRenderer);
    for (int j = 0; j <640; j+=32) {
        Elemento* bandera = new ElementoBandera(j, j + 60, j + 500,
                                                &banderaTextura, 0);
        elementos.push_back(bandera);
    }

    VistaPuente puenteTextura(gRenderer);
    for (int j = 0; j <640; j+=64) {
        Elemento* puente = new ElementoPuente(j, j+200, j+800,
                                              &puenteTextura, j%3==0);
        elementos.push_back(puente);
    }


    for (int i = 40; i <= 40*2; i+=40) {
        std::string id = "0" + std::to_string(i);
        std::string posX = "00"+std::to_string(i);
        std::string posY = "0020";
        std::string mio = std::to_string(i%2==0);
        std::string tipoColor = "91";
        std::string mensaje = id+"0"+posX+posY+mio+tipoColor;
        Paquete paquete(mensaje);
    printf("tipo: %i, x,y: %i,%i\n", paquete.getTipo(), paquete.getX(),
           paquete.getY());
        elementoManager.fabricar(paquete);
    }

    VistaHud vistaHud(gRenderer);
    VistaHudCaras vistaCaras(gRenderer);
    Hud hud(vistaHud, vistaCaras);
    VistaGui vistaGui(gRenderer);
    GuiEdificio guiEdificio(vistaGui);

    Mouse mouse;
    SelectBox selectBox;
    Click click;
    ColectorDeAcciones colector(selectBox,
                                click,
                                hud,
                                guiEdificio);
    while( !quit ){
        capTimer.start();
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ){
            //User requests quit
            if( e.type == SDL_QUIT ){
                quit = true;
            }
//TODO VER COMO SEPARAR TECLADO EVENT VS MOUSE EVENTS aunque no se si hace falta
            //Handle input for the dot
            camara.handleEvent( e );
            mouse.setState(e.type, e, camara.getOffset());
        }

        float timeStep = stepTimer.getTicks() / 1000.f;

        //Move the dot
//            camara.move();

        camara.move(timeStep);
        //Restart step timer
        stepTimer.start();

        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );



        //Render background

        std::for_each(tiles.begin(), tiles.end(), [&](Tile& tile){
          tile.mostrar(camara);
        });


        mouse.setMouseAction(selectBox, click);

        elementoManager.elementosVivir(camara, click, selectBox);

//        std::for_each(elementos.begin(), elementos.end(), [&](Elemento*
//        elemento){
//          elemento->mostrar(camara);
//          elemento->clicked(click);
//        });
//
//
//        std::for_each(unidades.begin(), unidades.end(), [&]
//            (ElementoUnidad* unidad){
//          unidad->mostrar(camara);
//          unidad->chequearSeleccion(selectBox);
//          unidad->clicked(click);
//        });



        selectBox.mostrar(gRenderer, camara.getOffset());
        hud.mostrar();
        guiEdificio.mostrar(camara.getOffset());


//        std::for_each(unidades.begin(), unidades.end(), [&]
//            (ElementoUnidad* unidad){
//          unidad->chequearSeleccion(selectBox);
//          unidad->clicked(click);
//        });



        ++pos_robot;
        ++pos_tanque;
        //Update screen
        SDL_RenderPresent( gRenderer );
        colector.crearAcciones();
        mouse.resetState();




//        int frameTicks = capTimer.getTicks();
//        if( frameTicks < SCREEN_TICK_PER_FRAME ){
//            //Wait remaining time
//            SDL_Delay( SCREEN_TICK_PER_FRAME - frameTicks );
//        }
    }


    //Free resources and close SDL
    close();

}

void Canvas::gameLoop() {
//todo pasar el loop aca
}
