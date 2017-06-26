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
#include "Header Files/ColaPaquetes.h"
#include <string>
#include <sstream>
#include <fstream>
#include <SDL_mixer.h>

#define NOMBRE_JUEGO "Z: El Ejercicio Final"
const int SCREEN_FPS = 20;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

Canvas::Canvas(ColaPaquetes &colaEntrada, ColaPaquetes &colaSalida) :
    colaEntrada(colaEntrada), colaSalida(colaSalida), quit(false) {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) <  0) {
        printf("No se pudo inicializar SDL. SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("No se pudo activar filtro lineal a textura\n");
        }

        gWindow = SDL_CreateWindow(NOMBRE_JUEGO,SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf( "No se pudo crear la ventana. SDL Error: %s\n", SDL_GetError
                () );
            success = false;
        } else {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED
                | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
            if (gRenderer == NULL){
                printf( "No se pudo crear renderizador. SDL Error: %s\n",
                        SDL_GetError() );
                success = false;
            } else {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

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
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }
            }
        }
    }

    if (!success){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
            "Juego Abortado", "El Juego no se pudo inicializar correctamente."
                                     " Se cerrará a continuación.",
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
    Mix_Quit();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}


void Canvas::manejarPaquetes(ElementoManager &elementoManager,
                             Hud &hud,
                             GuiEdificio &guiEdificio,
                             Reproductor &reproductor) {

    CodigosPaquete codigos;

    while (!colaEntrada.isEmpty()){
        Paquete paquete = colaEntrada.desencolar();
        if (paquete.getComando() == codigos.crear) {
            PaqueteAccion paqueteAccion(paquete);
            elementoManager.crear(paqueteAccion);
            if (paqueteAccion.getColor() == miColor){
                int tipo = paqueteAccion.getTipo();
                if (tipo == codigos.fuerte){
                    camara.setCentro(Punto(paqueteAccion.getX(), paqueteAccion.getY()));
                } else if (codigos.esRobot(tipo)){
                    reproductor.playCrearRobot();
                } else if (codigos.esVehiculo(tipo)){
                    reproductor.playCrearVehiculo();
                }
            }
        } else if (paquete.getComando() == codigos.mover){
            PaqueteAccion paqueteAccion(paquete);
            elementoManager.mover(paqueteAccion);
        } else if (paquete.getComando() == codigos.disparar){
            PaqueteAccion paqueteAccion(paquete);
            elementoManager.disparar(paqueteAccion);
        } else if (paquete.getComando() == codigos.matar){
            PaqueteAccion paqueteAccion(paquete);
            if (elementoManager.unidadEsMia(paqueteAccion.getId())){
                reproductor.playMuerte();
            }
            elementoManager.matar(paqueteAccion);
        } else if (paquete.getComando() == codigos.infoFabrica){
            PaqueteFabrica paqueteFabrica(paquete.getMensaje());
            guiEdificio.setInfo(paqueteFabrica);
        } else if (paquete.getComando() == codigos.infoUnidad){
            hud.setInfo(paquete);
        } else if (paquete.getComando() == codigos.perdedor){
            quit = true;
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                 "Game Over", "Tu fuerte fue destruido y perdiste, el juego se "
                                         "cerrará a continuación.", NULL);
        } else if (paquete.getComando() == codigos.ganador){
            quit = true;
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                                     "Ganaste el Juego!", "Felicitaciones, "
                                         "fuiste el ganador! El juego se "
                                         "cerrará a continuación.", NULL);
        }
    }

    if (colaEntrada.estaCerrada()){
        quit = true;
//        Esto quiere decir que yo no fui la que cerre.
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
            "Servidor Cerrado", "El servidor se ha desconectado, el juego se "
             "cerrará a continuación.", NULL);
    }
}

void Canvas::inicializarDatos(Mapa &mapa) {
    CodigosPaquete codigos;
    PaqueteAccion color = colaEntrada.desencolarBloqueante();
    if (color.getComando() != codigos.equipo){
//        TODO TIRAR ERROR ACA NO SE PUDO INICIALIZAR
    }
    miColor = std::stoi(color.getMensaje().substr(1));
    PaqueteAccion pMapa = colaEntrada.desencolarBloqueante();
    if (color.getComando() != codigos.mapa){
//        TODO TIRAR ERROR ACA NO SE PUDO INICIALIZAR
    }
    mapa.crearMapa(pMapa);
}


void Canvas::startGame(){

    mensajeEsperando();

    Mapa mapa(gRenderer);
    inicializarDatos(mapa);
//
    VistaManager vistaManager(gRenderer);
    ElementoManager elementoManager(vistaManager, miColor);


    Hud hud(gRenderer);
    VistaTexto vistaTexto(gRenderer);
    GuiEdificio guiEdificio(gRenderer,vistaTexto);
//
//
//    Mouse mouse;
//    SelectBox selectBox;
//    Click click;
    ColectorDeAcciones colector(selectBox,
                                click,
                                hud,
                                guiEdificio,
                                colaSalida);



    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);
    gameLoop(elementoManager,
             hud,
             guiEdificio,
             colector,
             mapa);


    vistaTexto.closeFont();
    //Cerrar SDL librenado recursos
    close();
}

void Canvas::gameLoop(ElementoManager &elementoManager,
                      Hud &hud,
                      GuiEdificio &guiEdificio,
                      ColectorDeAcciones &colector,
                      Mapa &mapa) {
    //Event handler
    SDL_Event e;

//    Para que la camara se mueva a una velocidad independiente de los FPS
    LTimer stepTimer;


//  Para medir los ticks del loop y despues usarlo para cumplir con las
// frames por segundo
    LTimer capTimer;
    Reproductor reproductor;

    while (!quit){
        capTimer.start();

        manejarPaquetes(elementoManager,
                        hud,
                        guiEdificio,
                        reproductor);

        while (SDL_PollEvent(&e) != 0){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            camara.handleEvent(e);
            mouse.setState(e.type, e, camara.getPos());
        }

        float timeStep = stepTimer.getTicks() / 1000.f;
        camara.mover(timeStep);
        stepTimer.start();

        //Borrar Pantalla
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

        //Actualizar Pantalla
        SDL_RenderPresent(gRenderer);

        colector.crearAcciones();
        mouse.resetState();


        int frameTicks = capTimer.getTicks();
        if (frameTicks < SCREEN_TICK_PER_FRAME){
            SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
        }
    }
}

void Canvas::mensajeEsperando() {
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);
    VistaTexto vistaTexto(gRenderer);
    vistaTexto.loadFont(fuentePath, 20);
    vistaTexto.mostrar("Esperando a que se conecte el resto de los Clientes"
                           "...", {0, 0,0}, {0,0});

    SDL_RenderPresent(gRenderer);
    vistaTexto.closeFont();
}
