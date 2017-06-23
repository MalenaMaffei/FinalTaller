#include "Header Files/Mapa.h"
#include "Header Files/constantes.h"
#include "Header Files/Paquete.h"
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
using std::string;

void Mapa::crearMapa(Paquete &paquete) {

//    TODO destruir esta textura al final
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
//    std::for_each(tiles.begin(), tiles.end(), [&](Tile& tile){
//      tile.mostrar(camara);
//    });

//    TODO REFACTOR Y REVISAR XQ SE ITERAN 100 TILES DE MAS




    Punto camStart = camara.getPos();
    if (camStart == prevCamPos){
        target.render( 0, 0, NULL);
        return;
    }

    prevCamPos = camStart;

    target.setAsRenderTarget();




    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);


    Punto camEnd = camStart + Punto(SCREEN_WIDTH, SCREEN_HEIGHT);
    int col = camStart.x / TILE_WIDTH;
    int fil = camStart.y / TILE_HEIGHT;
    int headRowTile = col + fil*TILESX;

    col = camEnd.x / TILE_WIDTH;
    int tailRowTile = col + fil*TILESX;
    fil = camEnd.y / TILE_HEIGHT;
    int lastTile = col + fil*TILESX;
    int iteradas = 0;
    for (int i = headRowTile; i <= lastTile; i += TILESX) {
        for (int j = 0; j <= tailRowTile - headRowTile; ++j) {
            Tile tile = tiles[j+i];
            tile.mostrar(camara);
            ++iteradas;
        }
    }
//    printf("se iteraron: %i tiles\n", iteradas);
    SDL_SetRenderTarget( gRenderer, NULL );

//    Show rendered to texture
    target.render( 0, 0, NULL);

}

Mapa::Mapa(SDL_Renderer *gRenderer) : prevCamPos({-1, -1}), target(gRenderer)
    , gRenderer(gRenderer) {
    vistaTiles = new VistaTiles(gRenderer);
    if(!target.createBlank(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_TEXTUREACCESS_TARGET)) {
        printf( "Failed to create target texture!\n" );
    }
    target.setBlendMode(SDL_BLENDMODE_BLEND);

}

