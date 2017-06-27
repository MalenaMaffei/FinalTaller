#include "Header Files/Mapa.h"
#include "Header Files/constantes.h"
#include "Header Files/PaqueteAccion.h"
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
using std::string;

Mapa::Mapa(SDL_Renderer *gRenderer) : prevCamPos({-1, -1}), target(gRenderer)
    , gRenderer(gRenderer) {
    vistaTiles = new VistaTiles(gRenderer);
//    Inicializo la textura sobre la que se renderizan los tiles
    target.createBlank(SCREEN_WIDTH, SCREEN_HEIGHT,SDL_TEXTUREACCESS_TARGET);
    target.setBlendMode(SDL_BLENDMODE_BLEND);
}

void Mapa::crearMapa(Paquete &paquete) {
    string mapa = paquete.getMensaje().substr(1);
    int x = 0;
    int y = 0;
    int tileType;
    for (char& c : mapa) {
        tileType = std::stoi(string(1,c));

        if ((tileType >= 0) && (tileType < TILE_CLIPS)){
            Tile tile(x*TILE_WIDTH, y*TILE_HEIGHT, tileType,vistaTiles);
            tiles.push_back(tile);
        } else {
            throw std::invalid_argument("Error generando mapa, "
                                            ""+std::to_string(tileType)+"es "
                "un tipo de tile inválido.");
        }
        ++x;

        if (x >= TILESX){
            x = 0;
            ++y;
            if (y > TILESY){
                throw std::invalid_argument("Error generando mapa, y:" +
                    std::to_string(y) +" es una dimensión inválida.");
            }
        }
    }
}

void Mapa::mostrar(Camara &camara) {
    Punto camStart = camara.getPos();
//    Si la camara no se movió, renderizo la misma textura de antes
    if (camStart == prevCamPos){
        target.render(0, 0, NULL);
        return;
    }

    prevCamPos = camStart;

//    seteo la textura para que de ahora en mas se renderice sobre ella
    target.setAsRenderTarget();
//  Reseteo el render (ahora la textura)
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);

//    Calculo que tiles voy a tener que iterar (los que estan dentro de la
// camara)
    Punto camEnd = camStart + Punto(SCREEN_WIDTH, SCREEN_HEIGHT);
    int col = camStart.x / TILE_WIDTH;
    int fil = camStart.y / TILE_HEIGHT;
    int headRowTile = col + fil*TILESX;

    col = camEnd.x / TILE_WIDTH;
    int tailRowTile = col + fil*TILESX;
    fil = camEnd.y / TILE_HEIGHT;
    int lastTile = col + fil*TILESX;
    int iteradas = 0;
//    Muestro los tiles
    for (int i = headRowTile; i <= lastTile; i += TILESX) {
        for (int j = 0; j <= tailRowTile - headRowTile; ++j) {
            Tile tile = tiles[j+i];
//            mostrar va a renderizar sobre la textura
            tile.mostrar(camara);
            ++iteradas;
        }
    }
//    Pantalla es el renderizador otra vez
    SDL_SetRenderTarget(gRenderer, NULL);
// Renderizo la textura con los tiles.
    target.render(0, 0, NULL);
}

Mapa::~Mapa() {
    delete vistaTiles;
}

