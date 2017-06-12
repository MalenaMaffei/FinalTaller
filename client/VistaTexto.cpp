#include "VistaTexto.h"
#include "Header Files/constantes.h"
#include "Header Files/Punto.h"

VistaTexto::VistaTexto(SDL_Renderer *gRenderer) : Texture(gRenderer) {}

bool VistaTexto::loadFont(std::string fontPath, int fontSize) {
    //Loading success flag
    bool success = true;



    //Open the font
    gFont = TTF_OpenFont(fontPath.c_str(), fontSize);
    if( gFont == NULL ){
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }


    printf("success en load font: %i\n", success);
    return success;
}

void VistaTexto::mostrar(std::string texto, SDL_Color color, Punto p) {
    printf("antes de load from render paso\n");
    if(loadFromRenderedText(texto, color, gFont)){
        printf("load from render paso\n");
        render(p.x, p.y);
    } else {
        printf( "Failed to render text texture!\n" );
//        TODO lanzar excep
    }
}

VistaTexto::~VistaTexto() {
    //Free loaded images
    free();

    //Free global font
    TTF_CloseFont( gFont );
    gFont = NULL;

    //Quit SDL subsystems
    TTF_Quit();
}

