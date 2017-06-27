#include "Header Files/Canvas.h"
#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include "Header Files/Timer.h"
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
#include "Header Files/CanvasException.h"
#include "Header Files/Logger.h"

#define NOMBRE_JUEGO "Z: El Ejercicio Final"
using std::string;
const int SCREEN_FPS = 20;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

Canvas::Canvas(ColaPaquetes &colaEntrada, ColaPaquetes &colaSalida) :
    colaEntrada(colaEntrada), colaSalida(colaSalida), quit(false) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) <  0) {
        throw CanvasException("No se pudo inicializar SDL. SDL Error: " +
            string(SDL_GetError()));
    } else {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            throw CanvasException("No se pudo activar filtro lineal a textura");
        }

        gWindow = SDL_CreateWindow(NOMBRE_JUEGO,SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            throw CanvasException("No se pudo crear la ventana. SDL Error: " +
                string(SDL_GetError()));
        } else {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED
                | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
            if (gRenderer == NULL){
                throw CanvasException("No se pudo crear renderizador."
                                      " SDL Error: " +string(SDL_GetError()));
            } else {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    throw CanvasException("No se pudo inicializar a SDL_image"
                                              ". SDL_image Error: " +
                        string(IMG_GetError()));
                }
                if (TTF_Init() == -1){
                    throw CanvasException("No se pudo inicializar a SDL_ttf. "
                                              "SDL_ttf Error: " +
                        string(TTF_GetError()));
                }
                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
                    throw CanvasException("No se pudo inicializar a SDL_Mixer"
                                              ".  SDL_mixer Error: " +
                        string(Mix_GetError()));
                }
            }
        }
    }
}

void Canvas::manejarPaquetes(ElementoManager &elementoManager,
                             Hud &hud,
                             GuiFabrica &guiEdificio,
                             Reproductor &reproductor) {
    CodigosPaquete codigos;

    if (colaEntrada.estaCerrada()){
        quit = true;
//        Esto quiere decir que yo no fui la que cerre.
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                                 "Servidor Cerrado", "El servidor se ha "
                                     "desconectado, el juego se "
                                     "cerrará a continuación.", NULL);
        return;
    }

    while (!colaEntrada.isEmpty()){
        Paquete paquete = colaEntrada.desencolar();
        if (paquete.getComando() == codigos.crear) {
            PaqueteAccion paqueteAccion(paquete);
            elementoManager.crear(paqueteAccion);
            if (paqueteAccion.getColor() == miColor){
                int tipo = paqueteAccion.getTipo();
                if (tipo == codigos.fuerte){
                    camara.setCentro(Punto(paqueteAccion.getX(),
                                           paqueteAccion.getY()));
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
            PaqueteUnidad paqueteUnidad(paquete.getMensaje());
            hud.setInfo(paqueteUnidad);
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
}

void Canvas::inicializarDatos(Mapa &mapa) {
    CodigosPaquete codigos;
    Paquete color = colaEntrada.desencolarBloqueante();
    if (color.getComando() != codigos.equipo){
        throw CanvasException("El primer paquete enviado no fue el color, "
                                  "fue: " + color.getMensaje());
    }
    miColor = std::stoi(color.getMensaje().substr(1));
    Paquete pMapa = colaEntrada.desencolarBloqueante();
    if (pMapa.getComando() != codigos.mapa){
        throw CanvasException("El segundo paquete enviado no fue el mapa, "
                                  "fue: " + pMapa.getMensaje());
    }
    mapa.crearMapa(pMapa);
}


void Canvas::startGame(){
    Logger* logger = Logger::getInstancia();
    mensajeEsperando();

    Mapa mapa(gRenderer);
    try {
        inicializarDatos(mapa);
    } catch(CanvasException& e){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                                 "Juego Abortado", "No se recibieron los "
                                     "datos necesarios del servidor para "
                                     "inicializar, el juego se cerrará a "
                                     "continuación.",
                                 NULL);
        logger->logACerr(e.what());
    }

    VistaManager vistaManager(gRenderer);
    ElementoManager elementoManager(vistaManager, miColor);

    Hud hud(gRenderer);

    VistaTexto vistaTexto(gRenderer);
    GuiFabrica guiEdificio(gRenderer,vistaTexto);


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
}

void Canvas::gameLoop(ElementoManager &elementoManager,
                      Hud &hud,
                      GuiFabrica &guiEdificio,
                      ColectorDeAcciones &colector,
                      Mapa &mapa) {
    //Event handler
    SDL_Event e;

//    Para que la camara se mueva a una velocidad independiente de los FPS
    Timer stepTimer;


//  Para medir los ticks del loop y despues usarlo para cumplir con las
// frames por segundo
    Timer capTimer;
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

Canvas::~Canvas() {
    //Destruir ventana y renderizador
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Salir de SDL y sus módulos
    Mix_Quit();
    Mix_CloseAudio();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
