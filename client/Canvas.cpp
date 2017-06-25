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
#include "Header Files/VistaIconoRobot.h"
#include "Header Files/VistaGui.h"
#include "Header Files/Mapa.h"
#include "Header Files/VistaTexto.h"
#include "Header Files/VistaLabelRobot.h"
#include "Header Files/VistaLabelVehiculo.h"
#include "Header Files/Reproductor.h"
#include <string>
#include <sstream>
#include <fstream>

const int SCREEN_FPS = 20;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

Canvas::Canvas(ColaPaquetes &colaEntrada, ColaPaquetes &colaSalida) :
    colaEntrada(colaEntrada), colaSalida(colaSalida), quit(false) {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("No se pudo inicializar SDL. SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("No se pudo activar filtro lineal a textura\n");
        }

        //Create window
        gWindow = SDL_CreateWindow( "Z: El Ejercicio Final",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if (gWindow == NULL) {
            printf( "No se pudo crear la ventana. SDL Error: %s\n", SDL_GetError
                () );
            success = false;
        } else {
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE );
            if (gRenderer == NULL){
                printf( "No se pudo crear renderizador. SDL Error: %s\n",
                        SDL_GetError() );
                success = false;
            } else {
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    printf("No se pudo inicializar a SDL_image could not SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
                if (TTF_Init() == -1){
                    printf("No se pudo inicializar a SDL_ttf. SDL_ttf Error:"
                                " %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }

    if (!success){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
            "Juego Abortado", "El Juego no se pudo inicializar correctamente.",
                                 NULL);
    }
}


void Canvas::close() {
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

//    TODO chequear que mas hace falta destruir o cerrar


    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


void Canvas::manejarPaquetes(ElementoManager &elementoManager,
                             Hud &hud,
                             GuiEdificio &guiEdificio) {
    Reproductor reproductor;
    CodigosPaquete codigos;
    while (!colaEntrada.isEmpty()){
        Paquete paquete = colaEntrada.desencolar();
        if (paquete.getComando() == codigos.crear) {
            elementoManager.crear(paquete);
            if (paquete.getTipo() == codigos.fuerte && paquete.getColor() ==
                miColor){
                camara.setCentro(Punto(paquete.getX(), paquete.getY()));
            }
//            TODO crashea despues de reprodicr
//            if (codigos.esRobot(paquete.getTipo())){
//                reproductor.reproducirFX
//                    ("../client/sounds"
//                         "/comp_robot_manufactured.wav");
//            }

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
            hud.setInfo(paquete);
        } else if (paquete.getComando() == codigos.perdedor){
            quit = true;
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                 "Game Over", "Tu fuerte fue destruido y perdiste, el juego se "
                                         "cerrará", NULL);
        }
    }

//    No lo pongo antes del while asi termina de desempaquetar todo. Aunque
// en realidad no tiene sentido porque ni lo va a mostrar
//    TODO decidir que hacer con esto
    if (colaEntrada.estaCerrada()){
        quit = true;
//        Esto quiere decir que yo no fui la que cerre.
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
            "Servidor Cerrado", "El servidor se ha desconectado, el juego se "
             "cerrará", NULL);
    }
}


void Canvas::startGame(){
    //Event handler
    SDL_Event e;

//Keeps track of time between steps
    LTimer stepTimer;
    //The frames per second timer
    LTimer fpsTimer;

    //The frames per second cap timer
    LTimer capTimer;
    //Current animation frame
    int frame = 0;


//    TODO dejar durmiendo esto hasta que entren los dos paquetes.. por ahi
// puedo probar con SDL_onEvent o algo asi
    while (colaEntrada.isEmpty()){
//        TODO fix MALO hasta uqe se me ocurra una mejor manera
    }
    Paquete color = colaEntrada.desencolar();
    if (color.getComando() == 6){
        miColor = std::stoi(color.getMensaje().substr(1));
        printf("mi color es: %i\n", miColor);
    }
    while (colaEntrada.isEmpty()){
//        TODO fix MALO hasta uqe se me ocurra una mejor manera
    }


    Mapa mapa(gRenderer);
    Paquete pMapa = colaEntrada.desencolar();
//    TODO poner proper manejador de este tipo de paquetes aca.
    if (pMapa.getComando() == 5){
        mapa.crearMapa(pMapa);
    }

    VistaManager vistaManager(gRenderer);
    ElementoManager elementoManager(vistaManager, miColor);


    Hud hud(gRenderer, miColor);
    GuiEdificio guiEdificio(gRenderer);


    Mouse mouse;
    SelectBox selectBox;
    Click click;
    ColectorDeAcciones colector(selectBox,
                                click,
                                hud,
                                guiEdificio,
                                colaSalida);


    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);
    while (!quit){
        capTimer.start();

        manejarPaquetes(elementoManager, hud, guiEdificio);

        while (SDL_PollEvent(&e) != 0){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            camara.handleEvent(e);
            mouse.setState(e.type, e, camara.getPos());
        }

        float timeStep = stepTimer.getTicks() / 1000.f;

        camara.mover(timeStep);
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
        selectBox.mostrar(gRenderer, camara.getPos());
        hud.mostrar();
        guiEdificio.mostrar(camara);

        //Update screen
        SDL_RenderPresent(gRenderer);
        colector.crearAcciones();
        mouse.resetState();


        int frameTicks = capTimer.getTicks();
        if (frameTicks < SCREEN_TICK_PER_FRAME){
            //Wait remaining time
            SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
        }
    }


    //Free resources and close SDL
    close();
}
