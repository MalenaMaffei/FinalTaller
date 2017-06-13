#include "Header Files/CreadorMapa.h"
#include "Header Files/constantes.h"
#include "Header Files/Paquete.h"
#include <string>
#include <stdexcept>
#include <vector>
using std::string;

void CreadorMapa::crearMapa(Paquete &paquete,
                            std::vector<Tile> &tiles,
                            VistaTiles &tilesTexture) {
    string mapa = paquete.getMensaje().substr(1);
    int x = 0;
    int y = 0;
    int tileType;
    for (char& c : mapa) {
        tileType = std::stoi(string(1,c));

        if ((tileType >= 0) && (tileType < TILE_CLIPS)){
            Tile tile(x*TILE_WIDTH, y*TILE_HEIGHT, tileType,&tilesTexture);
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
