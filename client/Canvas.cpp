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
#include "Header Files/Mapa.h"
#include "Header Files/VistaTexto.h"
#include "Header Files/VistaHudRobotLabels.h"
#include "Header Files/VistaHudVehiculoLabels.h"
#include <string>

const int SCREEN_FPS = 30;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

Canvas::Canvas(ColaPaquetes &colaEntrada, ColaPaquetes &colaSalida) :
    colaEntrada(colaEntrada), colaSalida(colaSalida) {
    bool success = true;

    if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
        printf( "No se pudo inicializar SDL. SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("No se pudo activar filtro lineal a textura\n");
        }

        //Create window
        gWindow = SDL_CreateWindow( "Z Game", SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if (gWindow == NULL) {
            printf( "No se pudo crear la ventana. SDL Error: %s\n", SDL_GetError
                () );
            success = false;
        }
        else {
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if (gRenderer == NULL){
                printf( "No se pudo crear renderizador. SDL Error: %s\n",
                        SDL_GetError() );
                success = false;
            } else {
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    printf( "No se pudo inicializar a SDL_image could not SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
                if (TTF_Init() == -1){
                    printf( "No se pudo inicializar a SDL_ttf. SDL_ttf Error:"
                                " %s\n", TTF_GetError() );
                    success = false;
                }
            }
        }
    }

    if (!success){
//        TODO lanzar excepcion aca, bah, no, en cada instancia
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


void Canvas::manejarPaquetes(ElementoManager &elementoManager,
                             Hud &hud,
                             GuiEdificio &guiEdificio) {
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
        } else if (paquete.getComando() == codigos.infoUnidad){
//            TODO refactorizar aca
            int tipo = std::stoi(paquete.getMensaje().substr(4,codigos.tipo));
            int vida = std::stoi(paquete.getMensaje().substr(6,3));
            hud.setInfo(tipo, vida);
        }
//        TODO manejar infos para el hud y la gui edificio
    }
}


void Canvas::startGame(){
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
        printf("mi color es: %i\n", miColor);
    }
    while (colaEntrada.isEmpty()){
//        TODO fix pedorro hasta uqe se me ocurra una mejor manera
    }

//    TODO crear clase mapa
    VistaTiles tilesTexture(gRenderer);
//    std::vector<Tile> tiles;
    Mapa mapa;
    Paquete pMapa = colaEntrada.desencolar();
//    TODO poner proper manejador de este tipo de paquetes aca.
    if (pMapa.getComando() == 5){
        mapa.crearMapa(pMapa, tilesTexture);
    }

    VistaManager vistaManager(gRenderer);
    ElementoManager elementoManager(vistaManager, miColor);

//TODO pasar esto adentro de hud como hice para guiEdificio
    VistaHud vistaHud(gRenderer);
    VistaHudCaras vistaCaras(gRenderer);
    VistaHudRobotLabels labelsRobot(gRenderer);
    VistaHudVehiculoLabels labelsVehiculo(gRenderer);
    VistaProgressBar barraVida(76, 8, gRenderer,{60, 175,23},{99, 71, 71});
    Hud hud(gRenderer,
            vistaHud,
            vistaCaras,
            labelsRobot,
            labelsVehiculo,
            barraVida);

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

        while (SDL_PollEvent( &e ) != 0){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            camara.handleEvent(e);
            mouse.setState(e.type, e, camara.getOffset());
        }

        float timeStep = stepTimer.getTicks() / 1000.f;



        camara.move(timeStep);
        //Restart step timer
        stepTimer.start();

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);


        mapa.mostrar(camara);

        mouse.setMouseAction(selectBox, click);

        elementoManager.elementosVivir(camara, click, selectBox);

//        TODO cambiar offset por camara! la gracia es que no se dibuje si no
// se ve
        selectBox.mostrar(gRenderer, camara.getOffset());
        hud.mostrar();
        guiEdificio.mostrar(camara);

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
