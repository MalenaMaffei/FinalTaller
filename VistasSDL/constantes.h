#ifndef TPFINAL_CONSTANTES_H
#define TPFINAL_CONSTANTES_H


//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//The dimensions of the level
const int LEVEL_WIDTH = SCREEN_WIDTH*4;
const int LEVEL_HEIGHT = SCREEN_HEIGHT*6;

//Tile constants
const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;
const int TOTAL_TILES = 192;
const int TOTAL_TILE_SPRITES = 12;

//The different tile sprites
const int TILE_RED = 0;
const int TILE_GREEN = 1;
const int TILE_BLUE = 2;
const int TILE_CENTER = 3;
const int TILE_TOP = 4;
const int TILE_TOPRIGHT = 5;
const int TILE_RIGHT = 6;
const int TILE_BOTTOMRIGHT = 7;
const int TILE_BOTTOM = 8;
const int TILE_BOTTOMLEFT = 9;
const int TILE_LEFT = 10;
const int TILE_TOPLEFT = 11;

const char tilePath[] = "../VistasSDL/imgs/tank.png";
const char tankPath[] = "../VistasSDL/imgs/ciudadTiles.png";
#endif //TPFINAL_CONSTANTES_H
